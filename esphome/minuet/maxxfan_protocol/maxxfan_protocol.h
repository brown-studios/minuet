#pragma once

#include "esphome/components/remote_base/remote_base.h"

namespace esphome {
namespace remote_base {

struct MaxxfanData {
  bool fan_on;
  bool cover_override;
  bool fan_exhaust;
  bool cover_open;
  bool auto_mode;
  bool warn;
  uint8_t fan_speed;
  uint8_t auto_temperature;

  bool operator==(const MaxxfanData &rhs) const {
    return fan_on == rhs.fan_on && cover_override == rhs.cover_override && fan_exhaust == rhs.fan_exhaust &&
        cover_open == rhs.cover_open && auto_mode == rhs.auto_mode && warn == rhs.warn &&
        fan_speed == rhs.fan_speed &&
        auto_temperature == rhs.auto_temperature;
  }
};

class MaxxfanProtocol : public RemoteProtocol<MaxxfanData> {
 public:
  void encode(RemoteTransmitData *dst, const MaxxfanData &data) override;
  optional<MaxxfanData> decode(RemoteReceiveData src) override;
  void dump(const MaxxfanData &data) override;
};

DECLARE_REMOTE_PROTOCOL(Maxxfan)

}  // namespace remote_base
}  // namespace esphome
