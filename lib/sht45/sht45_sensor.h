#include <sensor.h>
#include <SensirionI2cSht4x.h>
class TemperatureSensor : public Sensor {
private:
  static SensirionI2cSht4x sht;
public:
  float temp, hum;
  int c = 0;
    bool initialize() override {
        sht.begin(Wire, SHT45_I2C_ADDR_44);
    }
   void measure() override {
    float temperature, humidity;      
    sht.measureLowestPrecision(temperature, humidity);
   }
};