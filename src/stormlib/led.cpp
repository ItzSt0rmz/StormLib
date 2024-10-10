#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>
#include <math.h>
#include "pros/llemu.hpp"
#include "stormlib/led.hpp"
#include "pros/adi.hpp"
#include "pros/rtos.hpp"

std::vector<pros::adi::Led> stormlib::aRGB::leds = {}; 

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
stormlib::aRGB::aRGB(const int adiPort, const int length) : adiPort(adiPort), length(length), id(leds.size()) {
    leds.emplace_back(adiPort, length);
}

/**
 * @brief Turn off the RGB
 *
 * @param 
*/
void stormlib::aRGB::off() {
    shiftValue = 0;
    buffer.clear();
    buffer.resize(length, 0x00000F);
}

void stormlib::aRGB::setColor(u_int32_t color) {
    shiftValue = 0;
    buffer.clear();
    buffer.resize(length, color);
}

/**
 * @brief Set the strand to flow from a color to another color
 *
 * @param 
*/
void stormlib::aRGB::flow(u_int32_t color1, u_int32_t color2, int speed) {
    shiftValue = 1;
    buffer = genGradient(color1, color2, length);
}

/**
 * @brief Set the strand to flash a certain color
 *
 * @param 
*/
void stormlib::aRGB::flash(u_int32_t color, int speed, u_int32_t color2) {
    
};

/**
 * @brief Set the strand to "breathe" a color (i.e a slower, less harsh flash)
 *
 * @param 
*/
void stormlib::aRGB::breathe(uint32_t color) {
    
}

void stormlib::aRGB::bufferShift() {
    if (buffer.size() == 0 || buffer.size() < shiftValue || shiftValue == 0) return;

    //std::rotate(buffer.rbegin(), buffer.rbegin() + shiftValue, buffer.rend());
}

void stormlib::aRGB::updater() {
    while (true) {
		for (int i = 0; i < leds.size(); i++) {
			leds[i].update();
	}
		pros::delay(100);
	}
}

void stormlib::aRGB::update() {

    if (leds.empty()) return;
    
    for (int i = 0; i < leds[id].length(); i++) {
        leds[id][i] = buffer[i];
    }

}

// *********************************************************************************************************************************************************

stormlib::aRGB_manager::aRGB_manager(aRGB* strand1, aRGB* strand2, aRGB* strand3, aRGB* strand4, aRGB* strand5, aRGB* strand6, aRGB* strand7, aRGB* strand8):
    strand1(strand1),
    strand2(strand2),
    strand3(strand3),
    strand4(strand4),
    strand5(strand5),
    strand6(strand6),
    strand7(strand7),
    strand8(strand8)
{
    strands = {strand1, strand2, strand3, strand4, strand5, strand6, strand7, strand8};
    strands.erase(std::remove(strands.begin(), strands.end(), nullptr));
}

void stormlib::aRGB_manager::updater() {
    while (true) {
        for (int i = 0; i < strands.size(); i++) {
            strands[i]->bufferShift();
            strands[i]->update();
            pros::delay(100);
        }
    }
}

void stormlib::aRGB_manager::initialize() {
    pros::Task task1([&]() { updater(); });
    pros::Task task2([&]() { stormlib::aRGB::updater(); });
}