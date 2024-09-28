#pragma once

#include "pros/adi.hpp"
#include "display/lvgl.h"
#include <string>

namespace stormlib {
    /**
    * @brief selector class
    *
    */
    class selector{

        public:
            selector(int defaultAuton = 1, char* slot1Name = "AWP", char* slot2Name = "SAFE", char* slot3Name = "RUSH", char* slot4Name = "MISC");

            void initialize();

            void registerAuton(int slot, std::function<void ()> func);

            void runAuton();

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
            
        private:

            static lv_obj_t * vertLine;
            static lv_obj_t * horzLine;

            static lv_obj_t * teamScreen;
            static lv_obj_t * redButton;
            static lv_obj_t * redButtonLabel;
            static lv_obj_t * blueButton;
            static lv_obj_t * blueButtonLabel;

            static lv_obj_t * sideScreen;
            static lv_obj_t * leftButton;
            static lv_obj_t * leftButtonLabel;
            static lv_obj_t * rightButton;
            static lv_obj_t * rightButtonLabel;

            static lv_obj_t * optionScreen;
            static lv_obj_t * option1Button;
            static lv_obj_t * option1ButtonLabel;
            static lv_obj_t * option2Button;
            static lv_obj_t * option2ButtonLabel;
            static lv_obj_t * option3Button;
            static lv_obj_t * option3ButtonLabel;
            static lv_obj_t * option4Button;
            static lv_obj_t * option4ButtonLabel;

            static lv_obj_t * skillsScreen;
            static lv_obj_t * skills1Button;
            static lv_obj_t * skills1ButtonLabel;
            static lv_obj_t * skills2Button;
            static lv_obj_t * skills2ButtonLabel;
            static lv_obj_t * skills3Button;
            static lv_obj_t * skills3ButtonLabel;
            static lv_obj_t * skills4Button;
            static lv_obj_t * skills4ButtonLabel;

            static lv_obj_t * backButton;
            static lv_obj_t * backButtonLabel;

            static lv_obj_t * exitButton;
            static lv_obj_t * exitButtonLabel;
            static lv_obj_t * autonsButton;
            static lv_obj_t * autonsButtonLabel;
            static lv_obj_t * skillsButton;
            static lv_obj_t * skillsButtonLabel;

            static lv_obj_t * saveScreen;
            static lv_obj_t * saveExit;
            static lv_obj_t * saveDisp;
            static lv_obj_t * teamNum;

            static lv_obj_t * startScreen;

            static lv_style_t myButtonStyleREL; // released style
            static lv_style_t myButtonStylePR;  // pressed style
            static lv_style_t redStyle;
            static lv_style_t blueStyle;
            static lv_style_t selectedStyle;
            static lv_style_t backStyle;
            static lv_style_t menuStyle1;
            static lv_style_t menuStyle2;
            static lv_style_t style_btn_rel;
            static lv_style_t style_btn_pr;
            static lv_style_t style_bg;
            static lv_style_t invisibleStyle;
            static lv_style_t saveDispStyle;
            static lv_style_t teamNumStyle;

            static lv_res_t exitMenu_btn_click_action(lv_obj_t *btn);
            static lv_res_t autonsMenu_btn_click_action(lv_obj_t *btn);
            static lv_res_t skillsMenu_btn_click_action(lv_obj_t *btn);
            static lv_res_t red_btn_click_action(lv_obj_t *btn);
            static lv_res_t blue_btn_click_action(lv_obj_t *btn);
            static lv_res_t left_btn_click_action(lv_obj_t *btn);
            static lv_res_t right_btn_click_action(lv_obj_t *btn);
            static lv_res_t opt1_btn_click_action(lv_obj_t *btn);
            static lv_res_t opt2_btn_click_action(lv_obj_t *btn);
            static lv_res_t opt3_btn_click_action(lv_obj_t *btn);
            static lv_res_t opt4_btn_click_action(lv_obj_t *btn);
            static lv_res_t skl1_btn_click_action(lv_obj_t *btn);
            static lv_res_t skl2_btn_click_action(lv_obj_t *btn);
            static lv_res_t skl3_btn_click_action(lv_obj_t *btn);
            static lv_res_t skl4_btn_click_action(lv_obj_t *btn);
            static lv_res_t back_button_click_action1(lv_obj_t *btn);
            static lv_res_t back_button_click_action2(lv_obj_t *btn);
            static lv_res_t mbox_apply_action(lv_obj_t *mbox, const char *txt);

            static void menuSetup();

            static void resetButtonHighlights();

            int defaultAuton;
            char * slot1Name,  * slot2Name,  * slot3Name,  * slot4Name;
            
    };
} // namespace stormlib