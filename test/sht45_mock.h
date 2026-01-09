#include <sensor.h>
class Mocksensor : public Sensor {
private:
  
public:

    bool initialize() override {
        printf("this is a mock\n");
        return true;
    }
   void measure() override{
    temp = 100;
    hum = 100;
    c++;
   }
};