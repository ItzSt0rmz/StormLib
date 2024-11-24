#pragma once

#include "pros/adi.hpp"
#include <memory>
#include <string>

namespace stormlib {
/**
 * @brief aRGB class
 *
 */
class aRGB {

public:
  /**
   * @brief Construct a new aRGB strand
   *
   * @param LED_strip LED object to be used for strand
   * @param default_color default color for the strand to show if not given an
   * argument
   */
  aRGB(int adiPort, int length);

  /**
   * @brief Set the strand to flow from a color to another color
   *
   * @param drivetrain drivetrain to be used for the chassis
   * @param lateralSettings settings for the lateral controller
   * @param angularSettings settings for the angular controller
   * @param sensors sensors to be used for odometry
   */
  void flow(uint32_t color1, uint32_t color2 = 0xffffff, int speed = 1);

  void rainbow(int speed = 1);

  /**
   * @brief Set the strand to flash a certain color
   *
   * @param drivetrain drivetrain to be used for the chassis
   * @param lateralSettings settings for the lateral controller
   * @param angularSettings settings for the angular controller
   * @param sensors sensors to be used for odometry
   */
  void flash(uint32_t color, int speed = 5, uint32_t color2 = 0x000000);

  /**
   * @brief Set the strand to "breathe" a color (i.e a slower, less harsh flash)
   *
   * @param drivetrain drivetrain to be used for the chassis
   * @param lateralSettings settings for the lateral controller
   * @param angularSettings settings for the angular controller
   * @param sensors sensors to be used for odometry
   */
  void breathe(uint32_t color);

  /**
   * @brief Generate a gradient of colors between two given colors
   *
   * @param color1 First color bound
   * @param color2 Second color bound
   * @param size Size of gradient, use the length of the LED string
   */
  static std::vector<uint32_t> genGradient(uint32_t startColor,
                                           uint32_t endColor, size_t length);

  static std::vector<uint32_t> genRainbow(int length);

  void pulse(uint32_t color, int length = 3, int speed = 5,
             uint32_t color2 = 0x000000);

  /**
   * @brief Turn off the RGB
   *
   * @param
   */
  void off();

  void bufferShift();

  void setColor(uint32_t color);

  void update();

  void init();

  static void checkLeds();

  /**
   * @brief Creates task for main loop
   *
   * @param
   */

  // timer_init function (make it static)

  // time_left function (make it static)

  static std::vector<pros::adi::Led> leds;
  std::vector<uint32_t> buffer;

  int id;

private:
  int adiPort, length;
  uint32_t default_color, tempColor1, tempColor2;
  int speed, mode, shiftValue = 0;
};

class aRGB_manager {

public:
  aRGB_manager(aRGB *strand1, aRGB *strand2, aRGB *strand3, aRGB *strand4,
               aRGB *strand5, aRGB *strand6, aRGB *strand7, aRGB *strand8);
  void initialize(int refreshRate = 20);
  void updater();

  void rainbow(int speed = 5);
  void flow(uint32_t color1, uint32_t color2 = 0xffffff, int speed = 1);
  void flash(uint32_t color, int speed = 5, uint32_t color2 = 0x000000);
  void setColor(uint32_t color);
  void pulse(uint32_t color, int length = 3, int speed = 5,
             uint32_t color2 = 0xffffff);
  void off();

private:
  aRGB *strand1, *strand2, *strand3, *strand4, *strand5, *strand6, *strand7,
      *strand8;
  std::vector<aRGB *> strands;
  int refreshRate;
};
} // namespace stormlib