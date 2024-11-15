#pragma once

#include <chrono>
#include <iostream>
#include <thread>

namespace stormlib {
/**
 * @brief aRGB class
 *
 */
class clock {

public:
  void start(long long milliseconds = 105000);

  void waitUntil(long long time_left);

  long long timeLeft();

private:
  std::chrono::high_resolution_clock::time_point end_time, start_time;
  long long duration;
};
} // namespace stormlib