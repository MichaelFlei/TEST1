#include <sht45_handler.h>
void measure_task(Sensor* sensor){
    sensor->initialize();
    for(int i = 0; i<5; i++) {
        sensor->measure();
        printf("%f, %f", sensor->temp, sensor->hum);
    }
}