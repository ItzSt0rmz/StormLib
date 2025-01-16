#include "stormlib/led.hpp"
#include "pros/adi.hpp"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <math.h>
#include <vector>

std::vector<pros::adi::Led> stormlib::aRGB::leds;

/**
 * @brief Generate a gradient of colors between two given colors
 *
 * @param startColor First color bound
 * @param endColor Second color bound
 * @param length Size of gradient, use the length of the LED string
 */
std::vector<uint32_t> stormlib::aRGB::genGradient(uint32_t startColor,
                                                  uint32_t endColor,
                                                  size_t length) {

  std::vector<uint32_t> gradient;
  gradient.reserve(length);

  uint8_t startR = (startColor >> 16) & 0xFF;
  uint8_t startG = (startColor >> 8) & 0xFF;
  uint8_t startB = startColor & 0xFF;

  uint8_t endR = (endColor >> 16) & 0xFF;
  uint8_t endG = (endColor >> 8) & 0xFF;
  uint8_t endB = endColor & 0xFF;

  double stepR = static_cast<double>(endR - startR) / (length - 1);
  double stepG = static_cast<double>(endG - startG) / (length - 1);
  double stepB = static_cast<double>(endB - startB) / (length - 1);

  for (size_t i = 0; i < length; ++i) {
    uint8_t r = static_cast<uint8_t>(startR + (stepR * i));
    uint8_t g = static_cast<uint8_t>(startG + (stepG * i));
    uint8_t b = static_cast<uint8_t>(startB + (stepB * i));

    uint32_t color = (r << 16) | (g << 8) | b;
    gradient.push_back(color);
  }

  return gradient;
}

/**
 * @brief Construct a new aRGB strand
 *
 * @param adiPort the number or letter of the adi port that the strand is
 * attached to
 * @param length the number of diodes on the led strand
 * argument
 */
stormlib::aRGB::aRGB(int adiPort, int length) {
  if (length > 63)
    length = 63;
  this->adiPort = adiPort;
  this->length = length;
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

void stormlib::aRGB::setColor(uint32_t color) {
  shiftValue = 0;
  buffer.clear();
  buffer.resize(length, color);
}

/**
 * @brief Set the strand to flow from a color to another color
 *
 * @param
 */
void stormlib::aRGB::flow(uint32_t color1, uint32_t color2, int speed) {
  shiftValue = speed;
  buffer = genGradient(color1, color2, length);
}

/**
 * @brief Set the strand to flash a certain color
 *
 * @param
 */
void stormlib::aRGB::flash(uint32_t color, int speed, uint32_t color2) {
  shiftValue = length;
  buffer.clear();
  buffer.resize(length, color);
  buffer.resize(length * speed * 2, color2);
};

/**
 * @brief Set the strand to "breathe" a color (i.e a slower, less harsh flash)
 *
 * @param
 */
void stormlib::aRGB::breathe(uint32_t color) {}

void stormlib::aRGB::rainbow(int speed) {
  shiftValue = speed;
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

void stormlib::aRGB::pulse(uint32_t color, int run_length, int speed,
                           uint32_t color2) {
  buffer.clear();
  buffer.resize(length, color2);
  for (int i = 0; i < run_length; i++) {
    buffer[i] = color;
  }
  shiftValue = speed;
}

void stormlib::aRGB::bufferShift() {
  if (buffer.size() == 0 || buffer.size() < shiftValue || shiftValue == 0)
    return;

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

stormlib::aRGB_manager::aRGB_manager(aRGB *strand1, aRGB *strand2,
                                     aRGB *strand3, aRGB *strand4,
                                     aRGB *strand5, aRGB *strand6,
                                     aRGB *strand7, aRGB *strand8)
    : strand1(strand1), strand2(strand2), strand3(strand3), strand4(strand4),
      strand5(strand5), strand6(strand6), strand7(strand7), strand8(strand8) {
  strands = {strand1, strand2, strand3, strand4,
             strand5, strand6, strand7, strand8};
}

void stormlib::aRGB_manager::updater() {
  while (true) {

    for (int i = 0; i < strands.size(); i++) {
      if (strands[i] == nullptr)
        continue;
      strands[i]->bufferShift();
      strands[i]->update();

      pros::delay(refreshRate);
    }
  }
}

void stormlib::aRGB_manager::initialize(int refreshRate) {
  this->refreshRate = refreshRate;
  for (int i = 0; i < strands.size(); i++) {
    if (strands[i] != nullptr) {
      strands[i]->setColor(0x00ff00);
      strands[i]->init();
    }
  }

  pros::Task LED_MANAGER_TASK([&]() { updater(); });
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

void stormlib::aRGB_manager::setColor(uint32_t color) {
  for (int i = 0; i < strands.size(); i++) {
    if (strands[i] != nullptr) {
      strands[i]->setColor(color);
    }
  }
}

void stormlib::aRGB_manager::flash(uint32_t color, int speed, uint32_t color2) {
  for (int i = 0; i < strands.size(); i++) {
    if (strands[i] != nullptr) {
      strands[i]->flash(color, speed, color2);
    }
  }
}

void stormlib::aRGB_manager::flow(uint32_t color1, uint32_t color2, int speed) {
  for (int i = 0; i < strands.size(); i++) {
    if (strands[i] != nullptr) {
      strands[i]->flow(color1, color2, speed);
    }
  }
}

<<<<<<< HEAD
void stormlib::aRGB_manager::pixelRun(uint32_t color, int run_length, int speed, uint32_t color2) {
  for (int i = 0; i < strands.size(); i++) {
    if (strands[i] != nullptr) {
      strands[i]->pixelRun(color, run_length, speed, color2);
=======
void stormlib::aRGB_manager::pulse(uint32_t color, int length, int speed,
                                   uint32_t color2) {
  for (int i = 0; i < strands.size(); i++) {
    if (strands[i] != nullptr) {
      strands[i]->pulse(color, length, speed, color2);
>>>>>>> 360302a520c9658d7ac53efdc711401727412a45
    }
  }
}
