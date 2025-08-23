// MINUET FAN MOTOR DRIVER
//
// Configures the MCF8316D BLDC motor driver chip for the installed fan motor.
// Includes a table of well-known motors and a mechanism for storing
// custom tuning parameters for other motors.
#include <cstdint>
#include <type_traits>

#include "esphome/components/mcf8316/mcf8316.h"
#include "esphome/core/log.h"

namespace minuet {
namespace fan_driver {

using namespace esphome::mcf8316;
using ErrorCode = MCF8316Component::ErrorCode;

constexpr float rpm_to_hz(float rpm) { return rpm / 60.f; }
constexpr float hz_to_rpm(float hz) { return hz * 60.f; }

// Describes a brushless DC fan motor and the parameters needed to operate it.
// Refer to the MCF8316D datasheet for more information.
struct MotorProfile final {
  // FG divisor, number of motor pole pairs.
  //
  // Choose this value by consulting the motor datasheet.
  unsigned fg_div : 4 {0};

  // Motor BEMF lead angle.
  //
  // Can be optimized for drive efficiency at higher speeds but 0 is fine
  unsigned lead_angle : 5 {0};

  // Motor phase resistance (MPET).
  unsigned motor_res : 8 {0};

  // Motor phase inductance (MPET).
  unsigned motor_ind : 8 {0};

  // Motor BEMF constant (MPET).
  unsigned motor_bemf_const : 8 {0};

  // Speed loop Kp coefficient (MPET).
  unsigned spd_loop_kp : 10 {0};

  // Speed loop Ki coefficient (MPET).
  unsigned spd_loop_ki : 10 {0};

  // IPD clock frequency.
  //
  // Increasing this value reduces the "tick" heard during IPD motor startup.
  // Too high may cause IPD startup faults.
  IPDClockFrequency ipd_clk_freq : 3 {0};

  // IPD current threshold.
  //
  // Reducing this value reduces the "tick" heard during IPD motor startup.
  // Too low may cause IPD startup to incorrectly determing the motor alignment and
  // cause the motor to start spinning backwards.
  IPDCurrentThreshold ipd_curr_thr : 5 {0};

  // Open loop current limit per phase.
  //
  // Choose this value to provide enough current for the motor to startup and run
  // up to `OPN_CL_HANDOFF_THR` speed.  Too low and the motor may stall before reaching
  // this speed which will cause an MPET fault.  Should be about 1/2 to 2/3 of `ILIMIT`.
  CurrentLimit ol_ilimit : 4 {0};

  // Open loop acceleration.
  //
  // Choose this value to ensure a smooth handoff from the IPD advance into open loop
  // control.  Too low and the motor may stall on startup.  Too high and the motor
  // may lose synchronization with then open loop if it cannot speed up fast enough to
  // match the acceleration due to rotor inertia.
  //
  // Note: The acceleration rate is defined in electrical Hz per second (not rotor Hz per second)
  // so the appropriate value to use depends on the number of motor poles and inertia.
  OpenLoopAcceleration ol_acc_a1 : 4 {0};

  // Closed loop current limit per phase.
  //
  // Choose this value by consulting the motor datasheet.
  // Must be less than BOARD_LOCK_ILIMIT.
  CurrentLimit ilimit : 4 {0}; // Closed loop current limit per phase

  // Closed loop acceleration when not fully aligned.
  //
  // Should be equal to or a little greater than OL_ACC_A1.  Accelerating too quickly
  // while the closed loop is not fully aligned may cause loss of motor synchronization.
  // It's fine to keep accelerating at a similar pace to the open loop.
  //
  // Note: The acceleration rate is defined in electrical Hz per second (not rotor Hz per second)
  // so the appropriate value to use depends on the number of motor poles and inertia.
  ClosedLoopSlowAcceleration cl_slow_acc : 4 {0};

  // Closed loop acceleration when fully aligned.
  //
  // Should be much greater than CL_SLOW_ACC so the motor quickly comes up to speed.
  // The acceleration rate is defined in electrical Hz per second (not rotor Hz per second)
  // so the appropriate value to use depends on the number of motor poles.
  //
  // Note: The acceleration rate is defined in electrical Hz per second (not rotor Hz per second)
  // so the appropriate value to use depends on the number of motor poles and inertia.
  ClosedLoopAcceleration cl_acc : 5 {0};

  // Closed loop deceleration.
  //
  // Deceleration is generally limited by rotor inertia so this value can be set arbitrarily large
  // or be unlimited with no significant effect.
  //
  // Note: The acceleration rate is defined in electrical Hz per second (not rotor Hz per second)
  // so the appropriate value to use depends on the number of motor poles and inertia.
  ClosedLoopDeceleration cl_dec : 5 {0};

  // Mapping from fan speed index (1 to 10) to fan speed RPM (monotonically increasing)
  //
  // The lowest entry should be a slow speed that the motor can quietly sustain under load.
  // The highest entry should be a fast speed that the motor can sustain under load without excess vibration.
  //
  // Overall, the speeds in the table should be memorable and friendly for humans.
  // They should provide some options for quiet operation, some for greater airflow, and some in between.
  uint16_t fan_speed_rpm_table[10] {0};
} __attribute__((packed));

// Describes a motor's provenance and parameters.
struct MotorDescriptor final {
  // Motor manufacturer name (human-readable text).
  const char* manufacturer;

  // Motor model name (human-readable text).
  const char* model;

  // Motor profile.
  MotorProfile profile;
};

// A table of well-known motors that have been tested for use with Minuet.
constexpr MotorDescriptor MOTORS[] = {
  {
    "StepperOnline", "57BYA54-12-01", {
      .fg_div = fg_div_from_motor_poles(4),
      .lead_angle = lead_angle_from_degrees(0),
      .motor_res = 74,
      .motor_ind = 98,
      .motor_bemf_const = 103,
      .spd_loop_kp = 115,
      .spd_loop_ki = 293,
      .ipd_clk_freq = IPDClockFrequency::FREQ_1000_HZ,
      .ipd_curr_thr = IPDCurrentThreshold::THR_1_5_A,
      .ol_ilimit = CurrentLimit::LIMIT_2_0_A,
      .ol_acc_a1 = OpenLoopAcceleration::ACCEL_2_5_HZ_S,
      .ilimit = CurrentLimit::LIMIT_4_0_A,
      .cl_slow_acc = ClosedLoopSlowAcceleration::ACCEL_3_0_HZ_S,
      .cl_acc = ClosedLoopAcceleration::ACCEL_20_0_HZ_S,
      .cl_dec = ClosedLoopDeceleration::ACCEL_NO_LIMIT,
      .fan_speed_rpm_table = { 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1200 },
    }
  },
};

// This constant determines the 100% reference input speed for the motor driver.
// It is converted to electrical Hz and assigned to the MAX_SPEED parameter.
//
// Many of the MCF8316's configuration parameters are defined as a percentage
// of MAX_SPEED so don't change the value of this constant unless you intend to
// change all of those parameters too.  This value is already set above the
// maximum speed that Minuet will command the fan motor to achieve.
//
// If you're looking for a way to change how Minuet decides what speed to use
// for a given speed index, refer to the motor profile speed table.
// Please don't change this constant arbitrarily.
constexpr float BOARD_MAX_SPEED_RPM = 2000.f;

// This constant limits the maximum power that the MCF8316 can draw from the DC bus.
// The maximum power that can be safely used is ultimately limited by the thermal
// capacity of the Minuet PCB and its power supply.  We assume that Minuet is
// powered from a large battery that can supply much more power than this limit.
//
// The Minuet PCB traces are rated for about 4 A, the supply is protected
// with a 4 A polyfuse and has a nominal voltage of 12 V for a nominal maximum power
// draw of 48 W for the board.  So we set the limit to somewhat less to ensure a margin.
//
// The DC bus power limit should never be exceeded in normal operation even when the
// motor is running at fully speed under load.  Most of the inductive energy circulates
// between the motor phases and the MCF8316 so the phase current limits are more
// constraining than the bus power limit.
constexpr float BOARD_DC_BUS_MAX_POWER_WATTS = 40.f;

// This constant sets the motor phase current limit beyond which the MCF8316 reports
// a software-detected overcurrent lock fault and stops the motor.
//
// These are some factors that determine the current limit:
// - The MCF8316 is rated for a maximum of 8 A per phase.
// - The motor connector is rated for a maximum of 10 A per pin.
// - The Minuet PCB traces between the MCF8316 and the motor connector are short and wide
//   with negligible voltage drop.
// - This current limit should be a little more than ILIMIT.
// - The published maximum motor current limit (ILIMIT) for Minuet is 4 A.
// - The chip gets hot at high current and has been seen to trigger an overtemperature
//   within a few minutes at 4.5 A.
constexpr CurrentLimit BOARD_LOCK_ILIMIT = CurrentLimit::LIMIT_4_5_A;

// This constant sets the motor phase current limit beyond which the MCF8316 reports
// a hardware-detected overcurrent lock fault and stops the motor.  It behaves similarly
// to BOARD_LOCK_ILIMIT but it acts much more quickly.
//
// This value should be slightly greater than BOARD_LOCK_ILIMIT.
constexpr CurrentLimit BOARD_HW_LOCK_ILIMIT = CurrentLimit::LIMIT_5_0_A;

// Controls the MCF8316 motor driver chip.
class Controller {
public:
  static inline MCF8316Component* driver() { return minuet_fan_driver; }

  void init(const MotorDescriptor& descriptor);
  void shutdown();

  bool set_state(float speed_rpm, bool exhaust, bool brake, bool keep_awake);
  void start_mpet();

  float get_tachometer_rpm();
  float get_bus_current();
  float get_motor_phase_peak_current();
  float get_vm_voltage();
  float get_fan_speed_by_index(int index) const;

private:
  Config make_config_(const MotorProfile& profile);
  bool set_inputs_(float speed_in_rotor_hz, bool direction_counter_clockwise, bool brake_on);

  bool ready_{false};
  MotorProfile profile_{};
};


Config Controller::make_config_(const MotorProfile& profile) {
  Config config = driver()->make_default_config();

  // Motor parameters
  config.set(FG_DIV, uint8_t(profile.fg_div)); // Conversion factor from electrical Hz to rotor Hz
  config.set(LEAD_ANGLE, uint8_t(profile.lead_angle)); // BEMF lead angle
  config.set(MOTOR_RES, uint8_t(profile.motor_res)); // Motor phase resistance
  config.set(MOTOR_IND, uint8_t(profile.motor_ind)); // Motor phase inductance
  config.set(MOTOR_BEMF_CONST, uint8_t(profile.motor_bemf_const)); // Motor BEMF constant
  config.set(SPD_LOOP_KP, uint16_t(profile.spd_loop_kp)); // Speed loop Kp coefficient
  config.set(SPD_LOOP_KI, uint16_t(profile.spd_loop_ki)); // Speed loop Ki coefficient
  // N/A: CURR_LOOP_KP: only for current control loop
  // N/A: CURR_LOOP_KI: only for current control loop

  // Speed input
  config.set(MAX_SPEED, uint16_t(convert_speed_in_rotor_hz_to_electrical_hz(rpm_to_hz(BOARD_MAX_SPEED_RPM), profile.fg_div) * 6)); // Maximum speed with a 100% reference input
  config.set(INPUT_REFERENCE_WINDOW, uint8_t(0)); // Input reference window stops motor when speed reference inside the window: disabled
  // N/A: SPEED_RANGE_SEL: only for PWM speed input
  // N/A: INPUT_MAXIMUM_FREQ: only for frequency speed input
  // N/A: SPEED_LIMIT_ENABLE: only for reference inputs other than speed

  // Reference profiles (speed input transfer function)
  config.set(REF_PROFILE_CONFIG, uint8_t(0)); // Reference profile configuration: equation, use the speed input directly as-is
  config.set(DUTY_CLAMP1, uint8_t(0)); // Duty cycle clamp 1: 0%, must be 0, otherwise would impose a minimum duty cycle on the speed input
  config.set(DUTY_HYS, uint8_t(0)); // Duty cycle hysteresis: 0%, must be 0, otherwise would impose hysteresis on the speed input
  config.set(MIN_DUTY, uint8_t(0)); // Minimum duty cycle: 1%, must be as small as possible, will not operate the motor when the speed input is below this threshold
  config.set(REF_CLAMP1, uint8_t(0)); // Reference clamp 1: 0%, must be 0, otherwise would impose a minimum value on the speed input
  // N/A: DUTY_ON1, DUTY_OFF1, DUTY_ON2, DUTY_OFF2, DUTY_CLAMP2
  // N/A: DUTY_A, DUTY_B, DUTY_C, DUTY_D, DUTY_E
  // N/A: REF_ON1, REF_OFF1, REF_ON2, REF_OFF2, REF_CLAMP2
  // N/A: REF_A, REF_B, REF_C, REF_D, REF_E
  // N/A: VOLTAGE_MODE_CONFIG, DUTY_COMMAND_FILTER

  // Initial speed detection
  config.set(ISD_EN, true); // Initial speed detection: enabled
  config.set(BRAKE_EN, true); // ISD brake state: enabled
  config.set(HIZ_EN, false); // ISD HI-Z state: disabled, coasting is not needed
  // N/A: HIZ_TIME: only for ISD HI-Z state
  config.set(RESYNC_EN, true); // ISD resynchronization state: enabled
  config.set(FW_DRV_RESYN_THR, uint8_t(3)); // Resync speed threshold: 20% of MAX_SPEED
  config.set(STAT_DETECT_THR, uint8_t(0)); // Stationary detection BEMF threshold: 50 mV, set to a low BEMF to ensure rotor really has stopped, particularly when changing directions
  config.set(ISD_BEMF_FILT_ENABLE, true); // Enable BEMF filter during ISD: enabled, recommended according to tuning guide
  config.set(ISD_STOP_TIME, uint8_t(2)); // ISD detect motor stopped: after 50 ms, increase for better confidence
  config.set(ISD_RUN_TIME, uint8_t(2)); // ISD detect motor running: after 50 ms, increase for better confidence
  config.set(ISD_TIMEOUT, uint8_t(2)); // ISD timeout: after 1000 ms
  config.set(BRAKE_CURRENT_PERSIST, uint8_t(3)); // ISD brake persistence: 500 ms, wait longer to declare that the motor has braked due to rotor inertia
  config.set(FAST_ISD_EN, false); // Fast ISD: disabled, slow ISD is more reliable

  // Motor startup with initial position detection
  config.set(MTR_STARTUP, uint8_t(2)); // Motor startup: use IPD to avoid spinning the motor backwards, makes a little "tick" sound during startup
  config.set(IPD_CLK_FREQ, profile.ipd_clk_freq); // IPD clock frequency
  config.set(IPD_CURR_THR, profile.ipd_curr_thr); // IPD current threshold
  config.set(IPD_RLS_MODE, uint8_t(1)); // IPD release mode: tristate, faster decay than braking, less noisy
  config.set(IPD_ADV_ANGLE, uint8_t(1)); // IPD advance angle: 30 degrees
  config.set(IPD_REPEAT, uint8_t(2)); // IPD repeat count: 3 times, more reliable (2 times is enough but sometimes fails)
  config.set(IPD_HIGH_RESOLUTION_EN, true); // IPD high resolution mode: enabled
  config.set(IPD_TIMEOUT_FAULT_EN, true); // IPD timeout fault mode: enabled
  config.set(IPD_FREQ_FAULT_EN, true); // IPD frequency fault mode: enabled
  // N/A: ALIGN_ANGLE: only for align startup mode
  // N/A: ALIGN_TIME: only for align startup mode
  // N/A: ALIGN_OR_SLOW_CURRENT_ILIMIT, only for align or slow current startup mode

  // Open loop control
  config.set(OL_ILIMIT, profile.ol_ilimit); // Open loop motor phase current limit
  config.set(OL_ACC_A1, profile.ol_acc_a1); // Open loop acceleration rate
  config.set(OL_ACC_A2, uint8_t(0)); // Open loop acceleration rate: 0 Hz/s^2
  config.set(FIRST_CYCLE_FREQ_SEL, uint8_t(0)); // First cycle frequency select: start from 0 Hz
  // SLOW_FIRST_CYC_FREQ: sets start frequency only when FIRST_CYCLE_FREQ_SEL is 1
  config.set(ALIGN_SLOW_RAMP_RATE, uint8_t(6)); // Open loop current ramp rate: 50 A/s (used for all startup modes, not just align)

  // Open loop to closed loop handoff
  config.set(AUTO_HANDOFF_EN, true); // Auto handoff to closed loop: enabled, ignores OPN_CL_HANDOFF_THR except for MPET
  config.set(AUTO_HANDOFF_MIN_BEMF, uint8_t(2)); // Minimum BEMF for auto handoff: 100 mV
  config.set(OPN_CL_HANDOFF_THR, uint8_t(21)); // Open to closed loop handoff speed: 25% of MAX_SPEED, used in MPET to get the motor running, ignored in normal operation due to auto handoff
  config.set(IQ_RAMP_EN, false); // IQ ramp down in transition from open to closed loop: disabled, otherwise the transition takes too long
  config.set(LOW_SPEED_RECIRC_BRAKE_EN, true); // Open loop low speed braking: enabled, ensures the open loop can stop the motor quickly (otherwise inertia keeps the rotor spinning a long time)
  config.set(THETA_ERROR_RAMP_RATE, uint8_t(2)); // Theta error ramp: 0.1 deg/ms

  // Closed loop control
  config.set(ILIMIT, profile.ilimit); // Closed loop motor phase current limit
  config.set(OVERMODULATION_ENABLE, false); // Closed loop overmodulation: disabled to minimize acoustic noise
  config.set(CL_SLOW_ACC, profile.cl_slow_acc); // Closed loop acceleration when not fully aligned
  config.set(CL_ACC, profile.cl_acc); // Closed loop acceleration
  config.set(CL_DEC, profile.cl_dec); // Closed loop deceleration
  config.set(MTR_STOP, uint8_t(1)); // Closed loop motor stop mode: recirculate, avoids sending inductive energy back to the bus
  config.set(MTR_STOP_BRK_TIME, uint8_t(13)); // Closed loop motor stop time: 5000 ms, needs to be long enough to account for rotor inertia
  // N/A: ACT_SPIN_THR: only for MTR_STOP active spin-down mode

  // Braking
  config.set(BRK_MODE, uint8_t(1)); // Brake mode: low-side brake
  config.set(BRK_CONFIG, uint8_t(1)); // Brake config: exit brake state based on current and time
  config.set(BRK_CURR_THR, uint8_t(0)); // Brake current threshold: 0.1 A
  config.set(BRK_TIME, uint8_t(14)); // Brake stop time: 10s, must allow a long time to stop due to high rotor inertia
  config.set(BRAKE_SPEED_THRESHOLD, uint8_t(11)); // Brake speed threshold: reduce speed to 20% of MAX_SPEED before entering brake state
  config.set(BRAKE_PIN_MODE, uint8_t(0)); // Brake pin mode: low-side brake
  // N/A: ALIGN_BRAKE_ANGLE_SEL: only used when BRAKE_PIN_MODE is align brake mode

  // Active braking
  config.set(ACTIVE_BRAKE_EN, false); // Active braking: disabled, unnecessary, can cause voltage spikes during braking
  // N/A: ACTIVE_BRAKE_CURRENT_LIMIT
  // N/A: ACTIVE_BRAKE_BUS_CURRENT_SLEW_RATE
  // N/A: ACTIVE_BRAKE_KP
  // N/A: ACTIVE_BRAKE_KI
  // N/A: ACTIVE_BRAKE_SPEED_DELTA_LIMIT_ENTRY
  // N/A: ACTIVE_BRAKE_SPEED_DELTA_LIMIT_EXIT
  // N/A: ACTIVE_BRAKE_MOD_INDEX_LIMIT

  // Reverse drive
  config.set(DIR_CHANGE_MODE, uint8_t(0)); // Direction change mode: brake then change directions (don't reverse drive)
  config.set(RVS_DR_EN, false); // Reverse drive: disabled, unnecessary and requires tuning
  // N/A: REV_DRV_HANDOFF_THR
  // N/A: REV_DRV_OPEN_LOOP_CURRENT
  // N/A: REV_DRV_OPEN_LOOP_ACCEL_A1
  // N/A: REV_DRV_OPEN_LOOP_ACCEL_A2
  // N/A: REV_DRV_OPEN_LOOP_DEC

  // Flux weakening
  config.set(FLUX_WEAK_ENABLE, false); // Flux weakining: disabled, we don't need to opeerate the motor above its rated speed
  // N/A: FLUX_WEAK_REF
  // N/A: FLUX_WEAK_KP
  // N/A: FLUX_WEAK_KI

  // Automatic lock retry
  config.set(LCK_RETRY, uint8_t(2)); // Retry interval after lock: 1 s
  config.set(AUTO_RETRY_TIMES, uint8_t(3)); // Auto-retry number of times: 5

  // Software lock to protect PCB from overcurrent
  config.set(LOCK_ILIMIT, BOARD_LOCK_ILIMIT); // Software lock current limit
  config.set(LOCK_ILIMIT_DEG, uint8_t(2)); // Software lock deglitch time: 0.2 ms
  config.set(LOCK_ILIMIT_MODE, uint8_t(3)); // Software lock mode: retry up to retry limit then latch fault

  // Hardware lock to protect PCB from overcurrent
  config.set(HW_LOCK_ILIMIT, BOARD_HW_LOCK_ILIMIT); // Hardware lock current limit
  config.set(HW_LOCK_ILIMIT_DEG, uint8_t(2)); // Hardware lock deglitch time: 2 us
  config.set(HW_LOCK_ILIMIT_MODE, uint8_t(3)); // Hardware lock mode: retry up to retry limit then latch fault

  // Motor lock to detect strange behavior of the motor
  config.set(LOCK1_EN, true); // Motor lock on abnormal speed: enabled
  config.set(LOCK2_EN, true); // Motor lock on abnormal BEMF: enabled
  config.set(LOCK3_EN, true); // Motor lock on no motor: enabled
  config.set(LOCK_ABN_SPEED, uint8_t(0)); // Motor lock abnormal speed threshold: 130% of max speed
  config.set(ABNORMAL_BEMF_THR, uint8_t(5)); // Motor abnormal BEMF threshold: 65%
  config.set(ABNORMAL_BEMF_PERSISTENT_TIME, uint8_t(1)); // Motor abnormal BEMF detection time: 500 ms
  config.set(NO_MTR_THR, uint8_t(0)); // No motor current threshold: 0.0375 A
  config.set(NO_MTR_FLT_CLOSEDLOOP_DIS, false); // No motor fault detection in closed loop: enabled
  config.set(MTR_LCK_MODE, uint8_t(3)); // Motor lock mode: retry up to retry limit then latch fault

  // Gate driver
  config.set(CIRCULAR_CURRENT_LIMIT_ENABLE, true); // Circular current limit: `ILIMIT` sets peak phase current limit
  config.set(AVS_EN, true); // Anti-voltage surge protection: enabled, prevent excess inductive energy from flowing back to the bus
  config.set(DEADTIME_COMP_EN, true); // Deadtime compensation: enabled, reduce audible noise
  config.set(SLEW_RATE, uint8_t(3)); // Slew rate: 200 mV/us, factory default
  config.set(MIN_ON_TIME, uint8_t(2)); // Low-side MOSFET minimum on-time: 0.5 us, factory default
  config.set(DYNAMIC_CSA_GAIN_EN, true); // Dynamic current sense amplifier gain: enabled, factory default
  config.set(DYNAMIC_VOLTAGE_GAIN_EN, false); // Dynamic voltage gain: disabled, factory default
  // N/A: CSA_GAIN: only for when DYNAMIC_CSA_GAIN_EN is disabled

  // Modulation
  config.set(SPREAD_SPECTRUM_MODULATION_DIS, false); // Spread spectrum modulation: enabled
  config.set(PWM_MODE, uint8_t(0)); // PWM mode: continuous space vector modulation
  config.set(PWM_FREQ_OUT, uint8_t(3)); // PWM frequency: 25 kHz
  config.set(PWM_DITHER_MODE, uint8_t(1)); // PWM dither mode: random
  config.set(PWM_DITHER_DEPTH, uint8_t(1)); // PWM dither depth: 5%
  // N/A: PWM_DITHER_STEP: only for triangular PWM dither

  // Buck converter
  config.set(BUCK_DIS, true); // Buck converter: disabled, FB_BK tied to +3.3 V rail
  config.set(BUCK_PS_DIS, true); // Buck power sequencing: disabled, AVDD supplies from VM, DVDD supplied from FB_BK
  config.set(BUCK_SEL, uint8_t(0)); // Buck voltage selection: 3.3 V
  config.set(BUCK_CL, uint8_t(1)); // Buck current limit: 150 mA, unclear if this setting is needed, suggested by SLLA673

  // Bus voltage and power limits
  config.set(BUS_VOLT, uint8_t(1)); // Bus voltage configuration: 30 V maximum
  config.set(VOLTAGE_HYSTERESIS, uint8_t(1)); // Voltage limit hysteresis: 1 V
  config.set(MIN_VM_MOTOR, uint8_t(3)); // Minimum bus voltage to operate motor: 8 V
  config.set(MIN_VM_MODE, uint8_t(1)); // Minimum bus voltage mode: clear fault when in bounds
  config.set(MAX_VM_MOTOR, uint8_t(1)); // Maximum bus voltage to operate motor: 18 V
  config.set(MAX_VM_MODE, uint8_t(1)); // Maximum bus voltage mode: clear fault when in bounds
  config.set(VDC_FILTER, uint8_t(1)); // Vdc(VM) filter cut-off frequency: factory default
  config.set(MAX_POWER, uint16_t(max_power_from_watts(BOARD_DC_BUS_MAX_POWER_WATTS))); // Maximum bus power
  config.set(BUS_POWER_LIMIT_ENABLE, true); // Limit DC bus to `MAX_POWER`: enabled

  // Protection circuits
  config.set(OVP_SEL, uint8_t(19)); // Bus overvoltage level: 22 V
  config.set(OVP_EN, true); // Bus overvoltage protection: enabled
  config.set(OTW_REP, true); // Overtemperature warning report: enabled, fault at 145 C junction temperature
  config.set(OCP_DEG, uint8_t(1)); // Overcurrent deglitch time: 0.6 us
  config.set(OCP_LVL, uint8_t(0)); // Overcurrent level: 16 A
  config.set(OCP_MODE, uint8_t(0)); // Overcurrent fault mode: report a latched fault

  // Output pins
  config.set(ALARM_PIN_EN, false); // Alarm pin: disabled
  config.set(FG_SEL, uint8_t(0)); // FG output select: output in ISD, open loop, and closed loop
  config.set(FG_CONFIG, uint8_t(0)); // FG output configuration: FG active as long as the motor is driven
  // N/A: FG_BEMF_THR: only for FG_CONFIG in BEMF threshold mode
  // N/A: FG_IDLE_CONFIG: nothing connected to FG pin
  // N/A: FG_FAULT_CONFIG: nothing connected to FG pin
  // N/A: DAC_SOx_SEL: nothing connected to DAC pins

  // EEPROM
  config.set(EEP_FAULT_MODE, uint8_t(0)); // EEPROM fault mode: latched fault
  config.set(EEPROM_LOCK_MODE, uint8_t(0)); // EEPROM lock mode: disabled
  // N/A: EEPROM_LOCK_KEY: EEPROM is not locked

  // Miscellaneous
  config.set(SPEED_PIN_GLITCH_FILTER, uint8_t(1)); // Speed pin glitch filter: 0.2 us
  config.set(SLEW_RATE_I2C_PINS, uint8_t(0)); // I2C slew rate: 4.8 mA, factory default
  config.set(PULLUP_ENABLE, false); // Internal pull-ups: disabled
  config.set(CRC_ERR_MODE, uint8_t(0)); // CRC error mode: latched fault
  config.set(SATURATION_FLAGS_EN, false); // Indicate current loop and speed loop saturation: disabled
  config.set(EXT_CLK_EN, false); // External clock: disabled
  // N/A: EXT_CLK_CONFIG: no external clock to configure

  return config;
}

bool Controller::set_inputs_(float speed_in_rotor_hz, bool direction_counter_clockwise, bool brake_on) {
  const bool run = speed_in_rotor_hz > 0;
  bool error = false;
  error |= brake_on && driver()->write_brake_input_config(true);
  error |= !run && driver()->write_speed_input(0);
  error |= driver()->write_direction_input_config(direction_counter_clockwise);
  error |= run && driver()->write_speed_input(speed_in_rotor_hz);
  error |= !brake_on && driver()->write_brake_input_config(false);
  return !error;
}

void Controller::init(const MotorDescriptor& descriptor) {
  this->ready_ = false;

  ESP_LOGI(TAG, "Initializing fan motor driver for \"%s\" \"%s\"", descriptor.manufacturer, descriptor.model);
  Config config = this->make_config_(descriptor.profile);
  log_config(config);

  ErrorCode error = driver()->write_config(config);
  if (!error) {
    error = driver()->save_config_to_eeprom();
  }
  if (error) {
    ESP_LOGE(TAG, "Failed to initialize the fan motor driver: %s", MCF8316Component::error_name(error));
    return;
  }

  this->ready_ = true;
  this->profile_ = descriptor.profile;
}

void Controller::shutdown() {
  ESP_LOGI(TAG, "Shutdown fan motor driver");

  if (driver()->is_awake()) {
    driver()->write_speed_input(0);
    driver()->sleep();
  }
  this->ready_ = false;
}

#define MINUET_FAN_DRIVER_RETURN_IF_NOT_READY \
  if (!this->ready_) { \
    ESP_LOGW(TAG, "Fan motor not ready"); \
    return; \
  }

#define MINUET_FAN_DRIVER_RETURN_RESULT_IF_NOT_READY(result) \
  if (!this->ready_) { \
    ESP_LOGW(TAG, "Fan motor not ready"); \
    return (result); \
  }

bool Controller::set_state(float speed_rpm, bool exhaust, bool brake, bool keep_awake) {
  ESP_LOGI(TAG, "Set fan state: speed_rpm=%f, exhaust=%d, brake=%d, keep_awake=%d", speed_rpm, exhaust, brake, keep_awake);
  MINUET_FAN_DRIVER_RETURN_RESULT_IF_NOT_READY(false);

  if (driver()->config_shadow().needs_mpet_for_speed_loop()) {
    ESP_LOGW(TAG, "Must run MPET before starting the fan.");
    return false; // don't poke the speed input
  }

  const bool run = speed_rpm > 0;
  if (run > 0 || keep_awake) {
    driver()->wake();
  }

  if (driver()->is_awake() && !this->set_inputs_(rpm_to_hz(speed_rpm), !exhaust, brake)) {
    ESP_LOGW(TAG, "Failed to set the fan driver inputs");
    if (!keep_awake) {
      driver()->sleep();
    }
    return false;
  }

  if (!run) {
    if (driver()->is_awake() && driver()->is_faulted()) {
      driver()->clear_fault();
    }
    if (!keep_awake) {
      driver()->sleep();
    }
  }
  return true;
}

void Controller::start_mpet() {
  MINUET_FAN_DRIVER_RETURN_IF_NOT_READY;

  driver()->wake();
  driver()->clear_fault();
  driver()->start_mpet(true /*write_shadow*/);
}

float Controller::get_tachometer_rpm() {
  if (this->ready_) {
    float speed_in_rotor_hz;
    ErrorCode error = driver()->read_speed_feedback(&speed_in_rotor_hz);
    if (!error) {
      return hz_to_rpm(speed_in_rotor_hz);
    }
  }
  return 0.f;
}

float Controller::get_bus_current() {
  if (this->ready_) {
    float current_in_amps;
    ErrorCode error = driver()->read_bus_current(&current_in_amps);
    if (!error) {
      return current_in_amps;
    }
  }
  return NAN;
}

float Controller::get_motor_phase_peak_current() {
  if (this->ready_) {
    float current_in_amps;
    ErrorCode error = driver()->read_motor_phase_peak_current(&current_in_amps);
    if (!error) {
      return current_in_amps;
    }
  }
  return NAN;
}

float Controller::get_vm_voltage() {
  if (this->ready_) {
    float voltage_in_volts;
    ErrorCode error = driver()->read_vm_voltage(&voltage_in_volts);
    if (!error) {
      return voltage_in_volts;
    }
  }
  return NAN;
}

float Controller::get_fan_speed_by_index(int index) const {
  return this->ready_ && index >= 1 && index <= 10 ? this->profile_.fan_speed_rpm_table[index - 1] : 0.f;
}

Controller controller;

} // namespace fan_driver
} // namespace minuet
