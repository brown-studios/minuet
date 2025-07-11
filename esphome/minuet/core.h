// Minuet core declarations
#include "esphome/components/fan/fan.h"

namespace minuet {

uint8_t transient_operation_depth = 0;

// Returns true if the current operation was initiated by transient operations that should
// not update the persistent state, such as synchronizing the fan with the automatic thermostat.
bool is_transient_operation() {
  return transient_operation_depth != 0;
}

// Runs a function as a transient operation.
template <typename T>
void perform_transient_operation(T func) {
  transient_operation_depth++;
  func();
  transient_operation_depth--;
}

// Records the state of the fan and cover as it was most recently set by the user, disregarding transient operations.
struct PersistentState {
  bool fan_on : 1 {false};
  unsigned fan_speed : 4 {1};
  bool fan_exhaust : 1 {true};
  bool cover_open : 1 {false};

  constexpr uint8_t& to_storage() { return reinterpret_cast<uint8_t&>(*this); }
  static constexpr PersistentState& from_storage(uint8_t& storage) { return reinterpret_cast<PersistentState&>(storage); }
} __attribute__((packed));

// Gets the persistent state
// This hack is needed because ESPHome global declarations cannot refer to types in user-defined include files.
PersistentState& persistent_state() {
  static_assert(sizeof(PersistentState) == sizeof(uint8_t));
  return PersistentState::from_storage(minuet_persistent_state_raw->value());
}

bool cover_is_open_or_opening(esphome::cover::Cover* cover) {
  return (cover->current_operation == COVER_OPERATION_IDLE && cover->position == COVER_OPEN)
      || cover->current_operation == COVER_OPERATION_OPENING;
}

constexpr bool fan_direction_is_exhaust(esphome::fan::FanDirection direction) {
  return direction == esphome::fan::FanDirection::REVERSE;
}

constexpr esphome::fan::FanDirection fan_direction(bool exhaust) {
  return exhaust ? esphome::fan::FanDirection::REVERSE : esphome::fan::FanDirection::FORWARD;
}

} // namespace minuet
