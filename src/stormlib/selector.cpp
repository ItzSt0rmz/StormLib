#include "led.hpp"
#include "main.h"
#include "selector.hpp"
#include <string>

using namespace pros;

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

static lv_style_t myButtonStyleREL; 
static lv_style_t myButtonStylePR;  
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

int autonSlot = 1;
bool stormlib::selector::isRed, stormlib::selector::isLeft, stormlib::selector::isSkills = false;
bool stormlib::selector::isDefault = true;


stormlib::selector::selector(int defaultAuton, const char* slot1Name, const char* slot2Name, const char* slot3Name, const char* slot4Name) {
    this->defaultAuton = defaultAuton;
    this->slot1Name = slot1Name;
    this->slot2Name = slot2Name;
    this->slot3Name = slot3Name;
    this->slot4Name = slot4Name;
}

void stormlib::selector::resetButtonHighlights() 
{
    
}

void stormlib::selector::exitMenu_btn_click_action(lv_event_t * event)
{
    lv_scr_load(saveScreen);
}

void stormlib::selector::autonsMenu_btn_click_action(lv_event_t * event)
{
    lv_scr_load(teamScreen);
}

void stormlib::selector::skillsMenu_btn_click_action(lv_event_t * event)
{
    lv_scr_load(skillsScreen);
}

void stormlib::selector::red_btn_click_action(lv_event_t * event)
{
    isRed = true;
    lv_scr_load(sideScreen);
}

void stormlib::selector::blue_btn_click_action(lv_event_t * event)
{
    isRed = false;
    lv_scr_load(sideScreen);
}

void stormlib::selector::left_btn_click_action(lv_event_t * event)
{
    isLeft = true;
    lv_scr_load(optionScreen);
}

void stormlib::selector::right_btn_click_action(lv_event_t * event)
{
    isLeft = false;
    lv_scr_load(optionScreen);
}

void stormlib::selector::opt1_btn_click_action(lv_event_t * event)
{
    lv_obj_t * btn = lv_event_get_target(event);
    isDefault = false;
    autonSlot = 1;
    resetButtonHighlights();
}

void stormlib::selector::opt2_btn_click_action(lv_event_t * event)
{
    isDefault = false;
    autonSlot = 2;
    resetButtonHighlights();
}

void stormlib::selector::opt3_btn_click_action(lv_event_t * event)
{
    isDefault = false;
    autonSlot = 3;
    resetButtonHighlights();
}

void stormlib::selector::opt4_btn_click_action(lv_event_t * event)
{
    isDefault = false;
    autonSlot = 4;
    resetButtonHighlights();
}

void stormlib::selector::skl1_btn_click_action(lv_event_t * event)
{
    autonSlot = 1;
    resetButtonHighlights();
}

void stormlib::selector::skl2_btn_click_action(lv_event_t * event)
{
    autonSlot = 2;
    resetButtonHighlights();
}

void stormlib::selector::skl3_btn_click_action(lv_event_t * event)
{
    autonSlot = 3;
    resetButtonHighlights();
}

void stormlib::selector::skl4_btn_click_action(lv_event_t * event)
{
    autonSlot = 4;
    resetButtonHighlights();
}

void stormlib::selector::back_button_click_action1(lv_event_t * event)
{
    lv_scr_load(teamScreen);
}

void stormlib::selector::back_button_click_action2(lv_event_t * event)
{
    lv_scr_load(sideScreen);
    resetButtonHighlights();
}

void stormlib::selector::menuSetup() 
{
    exitButton = lv_btn_create(lv_scr_act()); // create button, lv_scr_act() is default screen object
    lv_obj_add_event_cb(exitButton, exitMenu_btn_click_action, LV_EVENT_CLICKED, NULL); // set function to be called on button click
    lv_obj_add_style(exitButton, &menuStyle1, LV_INDEV_STATE_PRESSED); // set the released style
    lv_obj_add_style(exitButton, &menuStyle1, LV_INDEV_STATE_RELEASED); // set the pressed style
    lv_obj_set_size(exitButton, 160, 40); // set the button size
    lv_obj_align(exitButton, LV_ALIGN_TOP_LEFT, 0, 0); // set the position to top mid

    exitButtonLabel = lv_label_create(exitButton); // create label and puts it inside of the button
    lv_label_set_text(exitButtonLabel, "Exit"); // sets label text

    autonsButton = lv_btn_create(lv_scr_act()); // create button, lv_scr_act() is default screen object
    lv_obj_add_event_cb(autonsButton, autonsMenu_btn_click_action, LV_EVENT_CLICKED, NULL); // set function to be called on button click
    lv_obj_add_style(autonsButton, &menuStyle1, LV_INDEV_STATE_RELEASED); // set the released style
    lv_obj_add_style(autonsButton, &menuStyle1, LV_STATE_PRESSED); // set the pressed style
    lv_obj_set_size(autonsButton, 160, 40); // set the button size
    lv_obj_align(autonsButton, LV_ALIGN_TOP_LEFT, 160, 0); // set the position to top mid

    autonsButtonLabel = lv_label_create(autonsButton); // create label and puts it inside of the button
    lv_label_set_text(autonsButtonLabel, "Autons"); // sets label text

    skillsButton = lv_btn_create(lv_scr_act()); // create button, lv_scr_act() is default screen object
    lv_obj_add_event_cb(skillsButton, skillsMenu_btn_click_action, LV_EVENT_CLICKED, NULL); // set function to be called on button click
    lv_obj_add_style(skillsButton, &menuStyle1, LV_INDEV_STATE_RELEASED); // set the released style
    lv_obj_add_style(skillsButton, &menuStyle1, LV_STATE_PRESSED); // set the pressed style
    lv_obj_set_size(skillsButton, 160, 40); // set the button size
    lv_obj_align(skillsButton, LV_ALIGN_TOP_LEFT, 320, 0); // set the position to top mid

    skillsButtonLabel = lv_label_create(skillsButton); // create label and puts it inside of the button
    lv_label_set_text(skillsButtonLabel, "Skills"); // sets label text
}


void stormlib::selector::initialize() 
{
    lv_style_init(&myButtonStyleREL);
    lv_style_set_bg_color(&myButtonStyleREL, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_color(&myButtonStyleREL, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_radius(&myButtonStyleREL, 0);
    lv_style_set_text_color(&myButtonStyleREL, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&myButtonStyleREL, 2);

    lv_style_init(&myButtonStylePR);
    lv_style_set_bg_color(&myButtonStylePR, lv_color_make(255, 0, 0));
    lv_style_set_bg_grad_color(&myButtonStylePR, lv_color_make(0, 0, 255));
    lv_style_set_radius(&myButtonStylePR, 0);
    lv_style_set_text_color(&myButtonStylePR, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&myButtonStylePR, 2);

    lv_style_init(&redStyle);
    lv_style_set_bg_color(&redStyle, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&redStyle, lv_palette_main(LV_PALETTE_YELLOW));
    lv_style_set_radius(&redStyle, 0);
    lv_style_set_text_color(&redStyle, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&redStyle, 2);

    lv_style_init(&blueStyle);
    lv_style_set_bg_color(&blueStyle, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_color(&blueStyle, lv_palette_main(LV_PALETTE_LIGHT_BLUE));
    lv_style_set_radius(&blueStyle, 0);
    lv_style_set_text_color(&blueStyle, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&blueStyle, 2);

    lv_style_init(&selectedStyle);
    lv_style_set_bg_color(&selectedStyle, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_radius(&selectedStyle, 0);
    lv_style_set_text_color(&selectedStyle, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&selectedStyle, 2);

    lv_style_init(&backStyle);
    lv_style_set_bg_color(&backStyle, lv_color_make(0, 0, 0));
    lv_style_set_radius(&backStyle, 10);
    lv_style_set_text_color(&backStyle, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&backStyle, 2);

    lv_style_init(&menuStyle1);
    lv_style_set_bg_color(&menuStyle1, lv_palette_main(LV_PALETTE_NONE));
    lv_style_set_bg_grad_color(&menuStyle1, lv_palette_main(LV_PALETTE_NONE));
    lv_style_set_text_color(&menuStyle1, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&menuStyle1, 2);

    lv_style_init(&menuStyle2);
    lv_style_set_bg_color(&menuStyle2, lv_color_make(255, 255, 255));
    lv_style_set_bg_grad_color(&menuStyle2, lv_color_make(255, 255, 255));
    lv_style_set_text_color(&menuStyle2, lv_color_make(0, 0, 0));
    lv_style_set_border_width(&menuStyle2, 2);

    // Initialize background style
    lv_style_init(&style_bg);
    lv_style_set_bg_color(&style_bg, lv_color_make(0xf5, 0x45, 0x2e));
    lv_style_set_bg_grad_color(&style_bg, lv_color_make(0xb9, 0x1d, 0x09));
    lv_style_set_border_color(&style_bg, lv_color_make(0x3f, 0x0a, 0x03));
    lv_style_set_text_color(&style_bg, lv_color_make(255, 255, 255));
    lv_style_set_pad_hor(&style_bg, 12);
    lv_style_set_pad_ver(&style_bg, 8);
    lv_style_set_shadow_width(&style_bg, 8);

    lv_style_init(&style_btn_rel);
    lv_style_is_empty(&style_btn_rel); // Draw only the border
    lv_style_set_border_color(&style_btn_rel, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&style_btn_rel, 2);
    lv_style_set_border_opa(&style_btn_rel, LV_OPA_70);
    lv_style_set_pad_hor(&style_btn_rel, 12);
    lv_style_set_pad_ver(&style_btn_rel, 8);

    lv_style_init(&style_btn_pr);
    lv_style_is_empty(&style_btn_rel); // Draw only the border
    lv_style_set_border_color(&style_btn_pr, lv_color_make(255, 255, 255));
    lv_style_set_border_width(&style_btn_pr, 2);
    lv_style_set_border_opa(&style_btn_pr, LV_OPA_70);
    lv_style_set_pad_hor(&style_btn_pr, 12);
    lv_style_set_pad_ver(&style_btn_pr, 8);
    lv_style_set_bg_color(&style_btn_pr, LV_COLOR_MAKE(0x5d, 0x0f, 0x04));
    lv_style_set_bg_grad_color(&style_btn_pr, LV_COLOR_MAKE(0x5d, 0x0f, 0x04));

    lv_style_init(&invisibleStyle);
    lv_style_set_opa(&invisibleStyle, 0);

    teamScreen = lv_obj_create(NULL);

    sideScreen = lv_obj_create(NULL);

    optionScreen = lv_obj_create(NULL);

    skillsScreen = lv_obj_create(NULL);

    saveScreen = lv_obj_create(NULL);

    startScreen = lv_obj_create(NULL);

    lv_scr_load(teamScreen);

    menuSetup();

    lv_obj_add_style(autonsButton, &menuStyle2, LV_PART_MAIN);

    // Create and configure redButton
    redButton = lv_btn_create(teamScreen); // create button
    lv_obj_add_event_cb(redButton, red_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(redButton, &redStyle, LV_PART_MAIN); // set the style for released and pressed state
    lv_obj_set_size(redButton, 240, 200); // set button size
    lv_obj_align(redButton, LV_ALIGN_TOP_LEFT, 0, 40); // set position

    // Create label for redButton
    redButtonLabel = lv_label_create(redButton); // create label inside button
    lv_label_set_text(redButtonLabel, "Red"); // set label text

    // Create and configure blueButton
    blueButton = lv_btn_create(teamScreen); // create button
    lv_obj_add_event_cb(blueButton, blue_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(blueButton, &blueStyle, LV_PART_MAIN); // set the style for released and pressed state
    lv_obj_set_size(blueButton, 240, 200); // set button size
    lv_obj_align(blueButton, LV_ALIGN_TOP_LEFT, 240, 40); // set position

    // Create label for blueButton
    blueButtonLabel = lv_label_create(blueButton); // create label inside button
    lv_label_set_text(blueButtonLabel, "Blue"); // set label text

    // Load the side screen
    lv_scr_load(sideScreen);

    // Menu setup
    menuSetup();

    lv_obj_add_style(autonsButton, &menuStyle2, LV_PART_MAIN);

    leftButton = lv_btn_create(sideScreen); // create button
    lv_obj_add_event_cb(leftButton, left_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(leftButton, &myButtonStyleREL, LV_PART_MAIN); // set released style
    lv_obj_add_style(leftButton, &myButtonStylePR, LV_STATE_PRESSED); // set pressed style
    lv_obj_set_size(leftButton, 240, 200); // set button size
    lv_obj_align(leftButton, LV_ALIGN_TOP_LEFT, 0, 40); // set position

    leftButtonLabel = lv_label_create(leftButton); // create label inside button
    lv_label_set_text(leftButtonLabel, "Left"); // set label text

    rightButton = lv_btn_create(sideScreen); // create button
    lv_obj_add_event_cb(rightButton, right_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(rightButton, &myButtonStyleREL, LV_PART_MAIN); // set released style
    lv_obj_add_style(rightButton, &myButtonStylePR, LV_STATE_PRESSED); // set pressed style
    lv_obj_set_size(rightButton, 240, 200); // set button size
    lv_obj_align(rightButton, LV_ALIGN_TOP_LEFT, 240, 40); // set position

    rightButtonLabel = lv_label_create(rightButton); // create label inside button
    lv_label_set_text(rightButtonLabel, "Right"); // set label text

    backButton = lv_btn_create(lv_scr_act()); // create button
    lv_obj_add_event_cb(backButton, back_button_click_action1, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(backButton, &backStyle, LV_PART_MAIN); // set style
    lv_obj_set_size(backButton, 100, 60); // set button size
    lv_obj_align(backButton, LV_ALIGN_CENTER, 0, 20); // set position

    backButtonLabel = lv_label_create(backButton); // create label inside button
    lv_label_set_text(backButtonLabel, "Back"); // set label text

    // Load the option screen
    lv_scr_load(optionScreen);

    menuSetup();

    lv_obj_add_style(autonsButton, &menuStyle2, LV_PART_MAIN);

    option1Button = lv_btn_create(optionScreen); // create button
    lv_obj_add_event_cb(option1Button, opt1_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(option1Button, &myButtonStyleREL, LV_PART_MAIN); // set released style
    lv_obj_add_style(option1Button, &myButtonStylePR, LV_STATE_PRESSED); // set pressed style
    lv_obj_set_size(option1Button, 240, 100); // set button size
    lv_obj_align(option1Button, LV_ALIGN_TOP_LEFT, 0, 40); // set position

    option1ButtonLabel = lv_label_create(option1Button); // create label inside button
    lv_label_set_text(option1ButtonLabel, slot1Name); // set label text

    option2Button = lv_btn_create(optionScreen); // create button
    lv_obj_add_event_cb(option2Button, opt2_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(option2Button, &myButtonStyleREL, LV_PART_MAIN); // set released style
    lv_obj_add_style(option2Button, &myButtonStylePR, LV_STATE_PRESSED); // set pressed style
    lv_obj_set_size(option2Button, 240, 100); // set button size
    lv_obj_align(option2Button, LV_ALIGN_TOP_LEFT, 240, 40); // set position

    option2ButtonLabel = lv_label_create(option2Button); // create label inside button
    lv_label_set_text(option2ButtonLabel, slot2Name); // set label text

    option3Button = lv_btn_create(optionScreen); // create button
    lv_obj_add_event_cb(option3Button, opt3_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(option3Button, &myButtonStyleREL, LV_PART_MAIN); // set released style
    lv_obj_add_style(option3Button, &myButtonStylePR, LV_STATE_PRESSED); // set pressed style
    lv_obj_set_size(option3Button, 240, 100); // set button size
    lv_obj_align(option3Button, LV_ALIGN_TOP_LEFT, 0, 140); // set position

    option3ButtonLabel = lv_label_create(option3Button); // create label inside button
    lv_label_set_text(option3ButtonLabel, slot3Name); // set label text

    option4Button = lv_btn_create(optionScreen); // create button
    lv_obj_add_event_cb(option4Button, opt4_btn_click_action, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(option4Button, &myButtonStyleREL, LV_PART_MAIN); // set released style
    lv_obj_add_style(option4Button, &myButtonStylePR, LV_STATE_PRESSED); // set pressed style
    lv_obj_set_size(option4Button, 240, 100); // set button size
    lv_obj_align(option4Button, LV_ALIGN_TOP_LEFT, 240, 140); // set position

    option4ButtonLabel = lv_label_create(option4Button); // create label inside button
    lv_label_set_text(option4ButtonLabel, slot4Name); // set label text

    backButton = lv_btn_create(lv_scr_act()); // create button
    lv_obj_add_event_cb(backButton, back_button_click_action2, LV_EVENT_CLICKED, NULL); // set click event
    lv_obj_add_style(backButton, &backStyle, LV_PART_MAIN); // set released style and pressed style
    lv_obj_set_size(backButton, 100, 60); // set button size
    lv_obj_align(backButton, LV_ALIGN_CENTER, 0, 20); // set position

    backButtonLabel = lv_label_create(backButton); // create label inside button
    lv_label_set_text(backButtonLabel, "Back"); // set label text

    lv_scr_load(skillsScreen);

    menuSetup();

    lv_obj_add_style(skillsButton, &menuStyle2, LV_PART_MAIN);

    skills1Button = lv_btn_create(skillsScreen);
    lv_obj_add_event_cb(skills1Button, skl1_btn_click_action, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(skills1Button, &myButtonStyleREL, LV_PART_MAIN);
    lv_obj_add_style(skills1Button, &myButtonStylePR, LV_STATE_PRESSED);
    lv_obj_set_size(skills1Button, 240, 100);
    lv_obj_align(skills1Button, LV_ALIGN_TOP_LEFT, 0, 40);

    skills1ButtonLabel = lv_label_create(skills1Button);
    lv_label_set_text(skills1ButtonLabel, "Skills 1");

    skills2Button = lv_btn_create(skillsScreen);
    lv_obj_add_event_cb(skills2Button, skl2_btn_click_action, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(skills2Button, &myButtonStyleREL, LV_PART_MAIN);
    lv_obj_add_style(skills2Button, &myButtonStylePR, LV_STATE_PRESSED);
    lv_obj_set_size(skills2Button, 240, 100);
    lv_obj_align(skills2Button, LV_ALIGN_TOP_LEFT, 240, 40);

    skills2ButtonLabel = lv_label_create(skills2Button);
    lv_label_set_text(skills2ButtonLabel, "Skills 2");

    skills3Button = lv_btn_create(skillsScreen);
    lv_obj_add_event_cb(skills3Button, skl3_btn_click_action, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(skills3Button, &myButtonStyleREL, LV_PART_MAIN);
    lv_obj_add_style(skills3Button, &myButtonStylePR, LV_STATE_PRESSED);
    lv_obj_set_size(skills3Button, 240, 100);
    lv_obj_align(skills3Button, LV_ALIGN_TOP_LEFT, 0, 140);

    skills3ButtonLabel = lv_label_create(skills3Button);
    lv_label_set_text(skills3ButtonLabel, "Skills 3");

    skills4Button = lv_btn_create(skillsScreen);
    lv_obj_add_event_cb(skills4Button, skl4_btn_click_action, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(skills4Button, &myButtonStyleREL, LV_PART_MAIN);
    lv_obj_add_style(skills4Button, &myButtonStylePR, LV_STATE_PRESSED);
    lv_obj_set_size(skills4Button, 240, 100);
    lv_obj_align(skills4Button, LV_ALIGN_TOP_LEFT, 240, 140);

    skills4ButtonLabel = lv_label_create(skills4Button);
    lv_label_set_text(skills4ButtonLabel, "Skills 4");

    lv_scr_load(saveScreen);

    /** 
    LV_IMG_DECLARE(IMG HERE);
	lv_obj_t *img = lv_img_create(lv_scr_act(), NULL);
	lv_img_set_src(img, &IMG HERE);
	lv_obj_align(img, NULL, LV_ALIGN_CENTER, 0, 0);
    */

    // TODO: Make a background screen (have stormlib on it somewhere) 
    //       and make a box and label in it that the user can input their team 
    //       number into it for the save screen

    saveExit = lv_btn_create(saveScreen); //create button, lv_scr_act() is deafult screen object
    lv_obj_add_event_cb(saveExit, autonsMenu_btn_click_action, LV_EVENT_CLICKED, NULL); //set function to be called on button click
    lv_obj_add_style(saveExit, &invisibleStyle, LV_PART_MAIN);
    lv_obj_add_style(saveExit, &invisibleStyle, LV_STATE_PRESSED);
    lv_obj_set_size(saveExit, 480, 240); //set the button size
    lv_obj_align(saveExit, LV_ALIGN_TOP_LEFT, 0, 0); //set the position to top mid

    //----------------------------------------

    lv_scr_load(teamScreen);
}

int stormlib::selector::getAuton() {
    if (isDefault) return 0;

    if (!isSkills) {
		if (isRed) {
			if (isLeft) {
				if (autonSlot == 1) return stormlib::selector::E_RED_LEFT_1;
				if (autonSlot == 2) return stormlib::selector::E_RED_LEFT_2;
				if (autonSlot == 3) return stormlib::selector::E_RED_LEFT_3;
				if (autonSlot == 4) return stormlib::selector::E_RED_LEFT_4;
			}
			else {
				if (autonSlot == 1) return stormlib::selector::E_RED_RIGHT_1;
				if (autonSlot == 2) return stormlib::selector::E_RED_RIGHT_2;
				if (autonSlot == 3) return stormlib::selector::E_RED_RIGHT_3;
				if (autonSlot == 4) return stormlib::selector::E_RED_RIGHT_4;
			}
		}
		else {
			if (isLeft) {
				if (autonSlot == 1) return stormlib::selector::E_BLUE_LEFT_1;
				if (autonSlot == 2) return stormlib::selector::E_BLUE_LEFT_2;
				if (autonSlot == 3) return stormlib::selector::E_BLUE_LEFT_3;
				if (autonSlot == 4) return stormlib::selector::E_BLUE_LEFT_4;
			}
			else {
				if (autonSlot == 1) return stormlib::selector::E_BLUE_RIGHT_1;
				if (autonSlot == 2) return stormlib::selector::E_BLUE_RIGHT_2;
				if (autonSlot == 3) return stormlib::selector::E_BLUE_RIGHT_3;
				if (autonSlot == 4) return stormlib::selector::E_BLUE_RIGHT_4;
			}
		}
	}
	else {
		if (autonSlot == 1) return stormlib::selector::E_SKILLS_1;
		if (autonSlot == 2) return stormlib::selector::E_SKILLS_2;
		if (autonSlot == 3) return stormlib::selector::E_SKILLS_3;
		if (autonSlot == 4) return stormlib::selector::E_SKILLS_4;
	}

    return 1;
}

bool stormlib::selector::isAllianceRed() {
    return isRed;
}