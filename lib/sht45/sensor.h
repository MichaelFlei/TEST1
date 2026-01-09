// sensor_interface.hpp
#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <functional>
#include <memory>

class Sensor {
   public:
    float temp = 0;
    float hum = 0;
    float c = 0;
    // Pure virtual methods - must be implemented
    virtual bool initialize() = 0;

    virtual void measure() = 0;

    virtual float get_temp() {
        return temp;
    }
    virtual float get_hum() {
        return hum;
    }
    
    // Optional virtual methods with default implementation
    virtual bool calibrate() {
        // Default calibration does nothing
        return true;
    }
    
    virtual void reset() {
        // Default reset does nothing
    }
    
    
    // Virtual destructor
    virtual ~Sensor() =default;
    

         
};