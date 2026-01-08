// sensor_interface.hpp
#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <functional>
#include <memory>

class Sensor {
   public:
    // Pure virtual methods - must be implemented
    virtual bool initialize() = 0;


    
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