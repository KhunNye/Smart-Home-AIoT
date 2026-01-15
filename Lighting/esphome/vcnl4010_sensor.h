#include "esphome.h"
#include "Wire.h"
#include "Adafruit_VCNL4010.h"

class VCNL4010Sensor : public PollingComponent, public Sensor {
 public:
  Adafruit_VCNL4010 vcnl4010;

  VCNL4010Sensor() : PollingComponent(5000) {}  // Update every 5s

  void setup() override {
    Wire.begin();
    if (!vcnl4010.begin()) {
      ESP_LOGE("VCNL4010", "Sensor not found!");
    }
  }

  void update() override {
    float proximity = vcnl4010.readProximity();
    publish_state(proximity);
  }
};
