/**
 * @file src/stormlib/led.cpp
 * @author Cole Hawkins
 * @brief aRGB Class Definitions
 * @version 0.4.5
 * @date 2024-01-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <math.h>
#include "pros/llemu.hpp"
#include "stormlib/led.hpp"
#include "pros/adi.hpp"
#include "pros/rtos.hpp"

/**
* @brief Convert a hex color code to a hexadecimal code
*
* @param hex Hex color code to be converted
*/
uint32_t stormlib::aRGB::hexToDec(const std::string& hex) {
    std::stringstream ss;
    ss << std::hex << hex;
    uint32_t dec;
    ss >> dec;
    return dec;
}

/**
* @brief Convert a hexadecimal color code to a hex code
*
* @param hex Hexadecimal color code to be converted
*/
std::string stormlib::aRGB::decToHex(uint32_t dec) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << dec;
    return ss.str();
}

/**
* @brief Generate a gradient of colors between two given colors
*
* @param startColor First color bound 
* @param endColor Second color bound
* @param length Size of gradient, use the length of the LED string
*/
std::vector<uint32_t> stormlib::aRGB::genGradient(uint32_t startColor, uint32_t endColor, size_t length) {

    std::vector<uint32_t> gradient;
    gradient.reserve(length);

    // extract RGB components of startColor
    uint8_t startR = (startColor >> 16) & 0xFF;
    uint8_t startG = (startColor >> 8) & 0xFF;
    uint8_t startB = startColor & 0xFF;

    // extract RGB components of endColor
    uint8_t endR = (endColor >> 16) & 0xFF;
    uint8_t endG = (endColor >> 8) & 0xFF;
    uint8_t endB = endColor & 0xFF;

    // calculate the step size for each color component
    double stepR = static_cast<double>(endR - startR) / (length - 1);
    double stepG = static_cast<double>(endG - startG) / (length - 1);
    double stepB = static_cast<double>(endB - startB) / (length - 1);

    // generate the gradient
    for (size_t i = 0; i < length; ++i) {
        uint8_t r = static_cast<uint8_t>(startR + (stepR * i));
        uint8_t g = static_cast<uint8_t>(startG + (stepG * i));
        uint8_t b = static_cast<uint8_t>(startB + (stepB * i));

        // Combine the RGB components into a single uint32_t color
        uint32_t color = (r << 16) | (g << 8) | b;
        gradient.push_back(color);
    }

    return gradient;
}

/**
 * @brief Construct a new aRGB strand
 *
 * @param LED_strip LED object to be used for strand
 * @param default_color default color for the strand to show if not given an argument
*/
stormlib::aRGB::aRGB(int adiPort, int length)  : led(adiPort, length) {
    this->adiPort = adiPort;
    this->length = length;
}

/**
 * @brief Turn off the RGB
 *
 * @param 
*/
void stormlib::aRGB::off() {
    this->mode = 0;
}

/**
 * @brief Set the strand to flow from a color to another color
 *
 * @param 
*/
void stormlib::aRGB::flow(u_int32_t color1, u_int32_t color2, int speed) {
    this->mode = 1;
    this->colors = genGradient(color1, color2, 60);
}

/**
 * @brief Set the strand to flash a certain color
 *
 * @param 
*/
void stormlib::aRGB::flash(u_int32_t color, int speed, u_int32_t color2) {
    this->mode = 3;
    this->tempColor1 = color;
    this->speed = speed;
    this->tempColor2 = color2;
};

/**
 * @brief Set the strand to "breathe" a color (i.e a slower, less harsh flash)
 *
 * @param 
*/
void stormlib::aRGB::breathe(uint32_t color) {};

/**
 * @brief Main loop where most of logic is
 *
 * @param 
*/
void stormlib::aRGB::mainLoop() {
    while (true) {

        // default, off mode
        if (mode == 0) {
            led.clear_all();
            pros::lcd::print(0, "LED: OFF     ");
            pros::delay(100);
        }

        // flow mode
        else if (mode == 1) {
            pros::lcd::print(0, "LED: FLOW     ");

			// loop through each pixel gets a color, update buffer, shift color matrix by 1, repeat
			for (int i = 0; i < 60; ++i) {
                led.set_pixel(colors[i], i);
			}

			// shift color vector
			std::rotate(colors.begin(), colors.begin()+1, colors.end());
        }
        
        // breathe mode
        else if (mode == 2) {
            pros::lcd::print(0, "LED: BREATHE     ");
        }

        // flash mode
        else if (mode == 3) {
            led.set_all(tempColor1);
			pros::delay(speed*100);
			led.set_all(tempColor2);
			pros::delay(speed*100);
        }

        // shine mode
        else if (mode == 4) {}
        
        pros::delay(30);
    }
}

void stormlib::aRGB::updater() {
    led.update();
    pros::delay(100);
}

/**
 * @brief Creates task for main loop
 *
 * @param 
*/
void stormlib::aRGB::init() {
    pros::Task ledMainLoop([&]() { mainLoop(); });
    pros::Task ledUpdater([&]() { updater(); });
}   