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

std::vector<pros::adi::Led> stormlib::aRGB::leds;

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
stormlib::aRGB::aRGB(int adiPort, int length) : adiPort(adiPort), length(length) {
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
    shiftValue = 1 * speed;
    buffer = genGradient(color1, color2, length);
}

/**
 * @brief Set the strand to flash a certain color
 *
 * @param 
*/
void stormlib::aRGB::flash(u_int32_t color, int speed, u_int32_t color2) {
    shiftValue = length;
    buffer.clear();
    buffer.resize(length, color);
    buffer.resize(length*speed*2, 0x00000F);
};

/**
 * @brief Set the strand to "breathe" a color (i.e a slower, less harsh flash)
 *
 * @param 
*/
void stormlib::aRGB::breathe(uint32_t color) {
    
}

void stormlib::aRGB::rainbow(int speed) {
    shiftValue = 1 * speed;
    buffer = genRainbow(length);
}

std::vector<uint32_t> stormlib::aRGB::genRainbow(int length) {
    std::vector<uint32_t> rainbowColors;
    
    for (int i = 0; i < length; ++i) {
        // Calculate the hue based on the position in the vector
        float hue = static_cast<float>(i) / length * 360.0f;
        
        // Convert hue to RGB
        float r, g, b;
        if (hue < 60) {
            r = hue / 60;
            g = 1;
            b = 0;
        } else if (hue < 120) {
            r = 1;
            g = 1 - (hue - 60) / 60;
            b = 0;
        } else if (hue < 180) {
            r = 0;
            g = 1;
            b = (hue - 120) / 60;
        } else if (hue < 240) {
            r = 0;
            g = 1 - (hue - 180) / 60;
            b = 1;
        } else if (hue < 300) {
            r = (hue - 240) / 60;
            g = 0;
            b = 1;
        } else {
            r = 1;
            g = 0;
            b = 1 - (hue - 300) / 60;
        }

        // Convert RGB to uint32_t
        uint32_t color = (static_cast<uint32_t>(r * 255) << 16) |
                         (static_cast<uint32_t>(g * 255) << 8) |
                         (static_cast<uint32_t>(b * 255));

        rainbowColors.push_back(color);
    }

    return rainbowColors;
}

void stormlib::aRGB::bufferShift() {
    if (buffer.size() == 0 || buffer.size() < shiftValue || shiftValue == 0) return;

    std::rotate(buffer.rbegin(), buffer.rbegin() + shiftValue, buffer.rend());
}

void stormlib::aRGB::update() {
    for (int i = 0; i < leds[id].length(); i++) {
        leds[id].set_pixel(buffer[i], i);
    }

    leds[id].update();
}

void stormlib::aRGB::checkLeds() {
    pros::lcd::print(0, "size of leds: %d", leds.size());
}

void stormlib::aRGB::init() {
    id = leds.size();
    leds.emplace_back(adiPort, length);
    buffer.resize(length, 0xFFFFFF);
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
}

void stormlib::aRGB_manager::updater() {
    while (true) {

        for (int i = 0; i < strands.size(); i++) {
            if (strands[i] == nullptr) continue;
            strands[i]->bufferShift();
            strands[i]->update();

            pros::delay(20);
        }
    }
}

void stormlib::aRGB_manager::initialize() {
    for (int i = 0; i < strands.size(); i++) {
        if (strands[i] != nullptr) {
            strands[i]->init();
        }
    }

    pros::Task task1([&]() { updater(); });
}

void stormlib::aRGB_manager::rainbow(int speed) {
    for (int i = 0; i < strands.size(); i++) {
        if (strands[i] != nullptr) {
            strands[i]->rainbow(speed);
        }
    }
}

void stormlib::aRGB_manager::off() {
    for (int i = 0; i < strands.size(); i++) {
        if (strands[i] != nullptr) {
            strands[i]->off();
        }
    }
}

void stormlib::aRGB_manager::setColor(u_int32_t color) {
    for (int i = 0; i < strands.size(); i++) {
        if (strands[i] != nullptr) {
            strands[i]->setColor(color);
        }
    }
}

void stormlib::aRGB_manager::flash(u_int32_t color, int speed, u_int32_t color2) {
    for (int i = 0; i < strands.size(); i++) {
        if (strands[i] != nullptr) {
            strands[i]->flash(color, speed, color2);
        }
    }
}

void stormlib::aRGB_manager::flow(u_int32_t color1, u_int32_t color2, int speed) {
    for (int i = 0; i < strands.size(); i++) {
        if (strands[i] != nullptr) {
            strands[i]->flow(color1, color2, speed);
        }
    }
}
