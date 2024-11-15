#pragma once

#include "liblvgl/lvgl.h"
#include "pros/adi.hpp"
#include <string>

namespace stormlib {
/**
 * @brief selector class
 *
 */
class selector {

public:
  selector(int defaultAuton, const char *slot1Name = "AWP",
           const char *slot2Name = "SAFE", const char *slot3Name = "RUSH",
           const char *slot4Name = "MISC", bool is96504D = false);

  void initialize();

  // void registerSaveScreen();

  void loadSaveScreen();

  static int getAuton();

  static bool isAllianceRed();

  void setAllianceColorRed(bool allianceIsRed);

  enum AUTON_SLOTS {
    E_RED_RIGHT_1 = 1,
    E_RED_RIGHT_2 = 2,
    E_RED_RIGHT_3 = 3,
    E_RED_RIGHT_4 = 4,
    E_RED_LEFT_1 = 5,
    E_RED_LEFT_2 = 6,
    E_RED_LEFT_3 = 7,
    E_RED_LEFT_4 = 8,
    E_BLUE_RIGHT_1 = 9,
    E_BLUE_RIGHT_2 = 10,
    E_BLUE_RIGHT_3 = 11,
    E_BLUE_RIGHT_4 = 12,
    E_BLUE_LEFT_1 = 13,
    E_BLUE_LEFT_2 = 14,
    E_BLUE_LEFT_3 = 15,
    E_BLUE_LEFT_4 = 16,
    E_SKILLS_1 = 17,
    E_SKILLS_2 = 18,
    E_SKILLS_3 = 19,
    E_SKILLS_4 = 20
  };

  static bool isRed, isLeft, isSkills, isDefault;

private:
  static void exitMenu_btn_click_action(lv_event_t *event);
  static void autonsMenu_btn_click_action(lv_event_t *event);
  static void skillsMenu_btn_click_action(lv_event_t *event);
  static void red_btn_click_action(lv_event_t *event);
  static void blue_btn_click_action(lv_event_t *event);
  static void left_btn_click_action(lv_event_t *event);
  static void right_btn_click_action(lv_event_t *event);
  static void opt1_btn_click_action(lv_event_t *event);
  static void opt2_btn_click_action(lv_event_t *event);
  static void opt3_btn_click_action(lv_event_t *event);
  static void opt4_btn_click_action(lv_event_t *event);
  static void skl1_btn_click_action(lv_event_t *event);
  static void skl2_btn_click_action(lv_event_t *event);
  static void skl3_btn_click_action(lv_event_t *event);
  static void skl4_btn_click_action(lv_event_t *event);
  static void back_button_click_action1(lv_event_t *event);
  static void back_button_click_action2(lv_event_t *event);

  static void menuSetup();

  static void resetButtonHighlights();

  int defaultAuton;
  const char *slot1Name, *slot2Name, *slot3Name, *slot4Name;
  bool is96504D;
};

} // namespace stormlib
