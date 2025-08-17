// MINUET CORE HELPERS
#include "esphome/components/fan/fan.h"

#include <cstdint>

namespace minuet {

const char *const TAG = "minuet";

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

  // The storage hack is needed because ESPHome global declarations cannot refer to types in user-defined include files.
  using Storage = typename std::remove_reference<decltype(*minuet_persistent_state_raw)>::type::value_type;
  constexpr Storage& to_storage() { return reinterpret_cast<Storage&>(*this); }
  static constexpr PersistentState& from_storage(Storage& storage) { return reinterpret_cast<PersistentState&>(storage); }
} __attribute__((packed));

static_assert(sizeof(PersistentState) == sizeof(PersistentState::Storage));

PersistentState& persistent_state() {
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
