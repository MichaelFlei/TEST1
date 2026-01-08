#include <sensor.h>
#include <SensirionI2cSht4x.h>
class TemperatureSensor : public Sensor {
private:
  static SensirionI2cSht4x sht;
public:
    bool initialize() override {
        sht.begin(Wire, SHT45_I2C_ADDR_44);
    }
   double measure(){
    float temperature, humidity;      
    sht.measureLowestPrecision(temperature, humidity);
    return temperature;
   }
};