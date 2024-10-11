#include <chrono>
#include <iostream>
#include "pros/device.hpp"
#include "stormlib/clock.hpp"
#include <thread>
#include "pros/rtos.hpp"


void stormlib::clock::start(long long milliseconds) {
    
    duration = milliseconds;
    start_time = std::chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(duration);
}

void stormlib::clock::waitUntil(long long time_left) {
        auto target_time = end_time - std::chrono::milliseconds(time_left);
        
        while (target_time > std::chrono::high_resolution_clock::now()) {
            pros::delay(10); 
        }
}
