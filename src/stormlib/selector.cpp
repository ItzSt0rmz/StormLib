#include "main.h"
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

bool isRed = true;
bool isLeft = true;
bool isSkills = false;
int autonSlot = 1;


stormlib::selector::selector(int defaultAuton, bool initializeNow = true, const char* slot1Name, const char* slot2Name, const char* slot3Name, const char* slot4Name) {
    this->defaultAuton = defaultAuton;
    this->slot1Name = slot1Name;
    this->slot2Name = slot2Name;
    this->slot3Name = slot3Name;
    this->slot4Name = slot4Name;

    if (initializeNow)  this->initialize();
}

void stormlib::selector::resetButtonHighlights() 
{
    lv_btn_set_style(option1Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
    lv_btn_set_style(option2Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
    lv_btn_set_style(option3Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
    lv_btn_set_style(option4Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
    lv_btn_set_style(skills1Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
    lv_btn_set_style(skills2Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
    lv_btn_set_style(skills3Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
    lv_btn_set_style(skills4Button, LV_BTN_STYLE_REL, &myButtonStyleREL);
}

 lv_res_t stormlib::selector::exitMenu_btn_click_action(lv_obj_t * btn)
{
    lv_scr_load(saveScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::autonsMenu_btn_click_action(lv_obj_t * btn)
{
    lv_scr_load(teamScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::skillsMenu_btn_click_action(lv_obj_t * btn)
{
    lv_scr_load(skillsScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::red_btn_click_action(lv_obj_t * btn)
{
    isRed = true;
    lv_scr_load(sideScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::blue_btn_click_action(lv_obj_t * btn)
{
    isRed = false;
    lv_scr_load(sideScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::left_btn_click_action(lv_obj_t * btn)
{
    isLeft = true;
    lv_scr_load(optionScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::right_btn_click_action(lv_obj_t * btn)
{
    isLeft = false;
    lv_scr_load(optionScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::opt1_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 1;
    resetButtonHighlights();
    lv_btn_set_style(option1Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::opt2_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 2;
    resetButtonHighlights();
    lv_btn_set_style(option2Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::opt3_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 3;
    resetButtonHighlights();
    lv_btn_set_style(option3Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::opt4_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 4;
    resetButtonHighlights();
    lv_btn_set_style(option4Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::skl1_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 1;
    resetButtonHighlights();
    lv_btn_set_style(skills1Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::skl2_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 2;
    resetButtonHighlights();
    lv_btn_set_style(skills2Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::skl3_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 3;
    resetButtonHighlights();
    lv_btn_set_style(skills3Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::skl4_btn_click_action(lv_obj_t * btn)
{
    autonSlot = 4;
    resetButtonHighlights();
    lv_btn_set_style(skills4Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::back_button_click_action1(lv_obj_t * btn)
{
    lv_scr_load(teamScreen);
    return LV_RES_OK;
}

lv_res_t stormlib::selector::back_button_click_action2(lv_obj_t * btn)
{
    lv_scr_load(sideScreen);
    resetButtonHighlights();
    return LV_RES_OK;
}

lv_res_t stormlib::selector::mbox_apply_action(lv_obj_t * mbox, const char * txt)
{
    lv_scr_load(teamScreen);
    return LV_RES_OK; /*Return OK if the message box is not deleted*/
}

void stormlib::selector::menuSetup() 
{
    exitButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(exitButton, LV_BTN_ACTION_CLICK, exitMenu_btn_click_action); //set function to be called on button click
    lv_btn_set_style(exitButton, LV_BTN_STYLE_REL, &menuStyle1); //set the relesed style
    lv_btn_set_style(exitButton, LV_BTN_STYLE_PR, &menuStyle1); //set the pressed style
    lv_obj_set_size(exitButton, 160, 40); //set the button size
    lv_obj_align(exitButton, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0); //set the position to top mid

    exitButtonLabel = lv_label_create(exitButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(exitButtonLabel, "Exit"); //sets label text

    autonsButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(autonsButton, LV_BTN_ACTION_CLICK, autonsMenu_btn_click_action); //set function to be called on button click
    lv_btn_set_style(autonsButton, LV_BTN_STYLE_REL, &menuStyle1); //set the relesed style
    lv_btn_set_style(autonsButton, LV_BTN_STYLE_PR, &menuStyle1); //set the pressed style
    lv_obj_set_size(autonsButton, 160, 40); //set the button size
    lv_obj_align(autonsButton, NULL, LV_ALIGN_IN_TOP_LEFT, 160, 0); //set the position to top mid

    autonsButtonLabel = lv_label_create(autonsButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(autonsButtonLabel, "Autons"); //sets label text

    skillsButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(skillsButton, LV_BTN_ACTION_CLICK, skillsMenu_btn_click_action); //set function to be called on button click
    lv_btn_set_style(skillsButton, LV_BTN_STYLE_REL, &menuStyle1); //set the relesed style
    lv_btn_set_style(skillsButton, LV_BTN_STYLE_PR, &menuStyle1); //set the pressed style
    lv_obj_set_size(skillsButton, 160, 40); //set the button size
    lv_obj_align(skillsButton, NULL, LV_ALIGN_IN_TOP_LEFT, 320, 0); //set the position to top mid

    skillsButtonLabel = lv_label_create(skillsButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(skillsButtonLabel, "Skills"); //sets label text
}

void stormlib::selector::initialize() 
{
    lv_style_copy(&myButtonStyleREL, &lv_style_plain);
    myButtonStyleREL.body.main_color = LV_COLOR_BLUE;
    myButtonStyleREL.body.grad_color = LV_COLOR_RED;
    myButtonStyleREL.body.radius = 0;
    myButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);
    myButtonStyleREL.body.border.width = 2;

    lv_style_copy(&myButtonStylePR, &lv_style_plain);
    myButtonStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
    myButtonStylePR.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
    myButtonStylePR.body.radius = 0;
    myButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);
    myButtonStyleREL.body.border.width = 2;

    lv_style_copy(&redStyle, &lv_style_plain);
    redStyle.body.main_color = LV_COLOR_RED;
    redStyle.body.grad_color = LV_COLOR_YELLOW;
    redStyle.body.radius = 0;
    redStyle.text.color = LV_COLOR_MAKE(255, 255, 255);
    redStyle.body.border.width = 2;

    lv_style_copy(&blueStyle, &lv_style_plain);
    blueStyle.body.main_color = LV_COLOR_BLUE;
    blueStyle.body.grad_color = LV_COLOR_AQUA;
    blueStyle.body.radius = 0;
    blueStyle.text.color = LV_COLOR_MAKE(255, 255, 255);
    blueStyle.body.border.width = 2;

    lv_style_copy(&selectedStyle, &lv_style_plain);
    blueStyle.body.main_color = LV_COLOR_GRAY;
    blueStyle.body.radius = 0;
    blueStyle.text.color = LV_COLOR_MAKE(255, 255, 255);
    blueStyle.body.border.width = 2;

    lv_style_copy(&backStyle, &lv_style_plain);
    backStyle.body.main_color = LV_COLOR_MAKE(0, 0, 0);
    backStyle.body.radius = 10;
    backStyle.text.color = LV_COLOR_MAKE(255, 255, 255);
    backStyle.body.border.width = 2;

    lv_style_copy(&menuStyle1, &lv_style_plain);
    menuStyle1.body.main_color = LV_COLOR_BLACK;
    menuStyle1.body.grad_color = LV_COLOR_BLACK;
    menuStyle1.text.color = LV_COLOR_WHITE;
    menuStyle1.body.border.width = 2;

    lv_style_copy(&menuStyle2, &lv_style_plain);
    menuStyle2.body.main_color = LV_COLOR_WHITE;
    menuStyle2.body.grad_color = LV_COLOR_WHITE;
    menuStyle2.text.color = LV_COLOR_BLACK;
    menuStyle2.body.border.width = 2;
    
    lv_style_copy(&style_bg, &lv_style_pretty);
    style_bg.body.main_color = LV_COLOR_MAKE(0xf5, 0x45, 0x2e);
    style_bg.body.grad_color = LV_COLOR_MAKE(0xb9, 0x1d, 0x09);
    style_bg.body.border.color = LV_COLOR_MAKE(0x3f, 0x0a, 0x03);
    style_bg.text.color = LV_COLOR_WHITE;
    style_bg.body.padding.hor = 12;
    style_bg.body.padding.ver = 8;
    style_bg.body.shadow.width = 8;

    lv_style_copy(&style_btn_rel, &lv_style_btn_rel);
    style_btn_rel.body.empty = 1;                    /*Draw only the border*/
    style_btn_rel.body.border.color = LV_COLOR_WHITE;
    style_btn_rel.body.border.width = 2;
    style_btn_rel.body.border.opa = LV_OPA_70;
    style_btn_rel.body.padding.hor = 12;
    style_btn_rel.body.padding.ver = 8;

    lv_style_copy(&style_btn_pr, &style_btn_rel);
    style_btn_pr.body.empty = 0;
    style_btn_pr.body.main_color = LV_COLOR_MAKE(0x5d, 0x0f, 0x04);
    style_btn_pr.body.grad_color = LV_COLOR_MAKE(0x5d, 0x0f, 0x04);

    lv_style_copy(&invisibleStyle, &lv_style_plain);
    invisibleStyle.body.empty = true;

    saveDispStyle.body.radius = 0;    

    teamScreen = lv_obj_create(NULL, NULL);

    sideScreen = lv_obj_create(NULL, NULL);

    optionScreen = lv_obj_create(NULL, NULL);

    skillsScreen = lv_obj_create(NULL, NULL);

    saveScreen = lv_obj_create(NULL, NULL);

    startScreen = lv_obj_create(NULL, NULL);

    lv_scr_load(teamScreen);

    menuSetup();

    lv_btn_set_style(autonsButton, LV_BTN_STYLE_REL, &menuStyle2);

    redButton = lv_btn_create(teamScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(redButton, LV_BTN_ACTION_CLICK, red_btn_click_action); //set function to be called on button click
    lv_btn_set_style(redButton, LV_BTN_STYLE_REL, &redStyle); //set the relesed style
    lv_btn_set_style(redButton, LV_BTN_STYLE_PR, &redStyle); //set the pressed style
    lv_obj_set_size(redButton, 240, 200); //set the button size
    lv_obj_align(redButton, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 40); //set the position to top mid

    redButtonLabel = lv_label_create(redButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(redButtonLabel, "Red"); //sets label text
    
	blueButton = lv_btn_create(teamScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(blueButton, LV_BTN_ACTION_CLICK, blue_btn_click_action); //set function to be called on button click
    lv_btn_set_style(blueButton, LV_BTN_STYLE_REL, &blueStyle); //set the relesed style
    lv_btn_set_style(blueButton, LV_BTN_STYLE_PR, &blueStyle); //set the pressed style
    lv_obj_set_size(blueButton, 240, 200); //set the button size
    lv_obj_align(blueButton, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 240, 40); //set the position to top mid

    blueButtonLabel = lv_label_create(blueButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(blueButtonLabel, "Blue"); //sets label text

    lv_scr_load(sideScreen);
    
    menuSetup();

    lv_btn_set_style(autonsButton, LV_BTN_STYLE_REL, &menuStyle2);

	leftButton = lv_btn_create(sideScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(leftButton, LV_BTN_ACTION_CLICK, left_btn_click_action); //set function to be called on button click
    lv_btn_set_style(leftButton, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(leftButton, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(leftButton, 240, 200); //set the button size
    lv_obj_align(leftButton, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 40); //set the position to top mid

    leftButtonLabel = lv_label_create(leftButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(leftButtonLabel, "Left"); //sets label text

	rightButton = lv_btn_create(sideScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(rightButton, LV_BTN_ACTION_CLICK, right_btn_click_action); //set function to be called on button click
    lv_btn_set_style(rightButton, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(rightButton, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(rightButton, 240, 200); //set the button size
    lv_obj_align(rightButton, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 40); //set the position to top mid

    rightButtonLabel = lv_label_create(rightButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(rightButtonLabel, "Right"); //sets label text

    backButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(backButton, LV_BTN_ACTION_CLICK, back_button_click_action1); //set function to be called on button click
    lv_btn_set_style(backButton, LV_BTN_STYLE_REL, &backStyle); //set the relesed style
    lv_btn_set_style(backButton, LV_BTN_STYLE_PR, &backStyle); //set the pressed style
    lv_obj_set_size(backButton, 100, 60); //set the button size
    lv_obj_align(backButton, NULL, LV_ALIGN_CENTER, 0, 20); //set the position to top mid

    backButtonLabel = lv_label_create(backButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(backButtonLabel, "Back"); //sets label text

    lv_scr_load(optionScreen);

    menuSetup();

    lv_btn_set_style(autonsButton, LV_BTN_STYLE_REL, &menuStyle2);

	option1Button = lv_btn_create(optionScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(option1Button, LV_BTN_ACTION_CLICK, opt1_btn_click_action); //set function to be called on button click
    lv_btn_set_style(option1Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(option1Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(option1Button, 240, 100); //set the button size
    lv_obj_align(option1Button, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 40); //set the position to top mid

    option1ButtonLabel = lv_label_create(option1Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(option1ButtonLabel, slot1Name); //sets label text

	option2Button = lv_btn_create(optionScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(option2Button, LV_BTN_ACTION_CLICK, opt2_btn_click_action); //set function to be called on button click
    lv_btn_set_style(option2Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(option2Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(option2Button, 240, 100); //set the button size
    lv_obj_align(option2Button, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 40); //set the position to top mid

    option2ButtonLabel = lv_label_create(option2Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(option2ButtonLabel, slot2Name); //sets label text

	option3Button = lv_btn_create(optionScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(option3Button, LV_BTN_ACTION_CLICK, opt3_btn_click_action); //set function to be called on button click
    lv_btn_set_style(option3Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(option3Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(option3Button, 240, 100); //set the button size
    lv_obj_align(option3Button, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 140); //set the position to top mid

    option3ButtonLabel = lv_label_create(option3Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(option3ButtonLabel, slot3Name); //sets label text

	option4Button = lv_btn_create(optionScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(option4Button, LV_BTN_ACTION_CLICK, opt4_btn_click_action); //set function to be called on button click
    lv_btn_set_style(option4Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(option4Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(option4Button, 240, 100); //set the button size
    lv_obj_align(option4Button, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 140); //set the position to top mid

    option4ButtonLabel = lv_label_create(option4Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(option4ButtonLabel, slot4Name); //sets label text

    backButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(backButton, LV_BTN_ACTION_CLICK, back_button_click_action2); //set function to be called on button click
    lv_btn_set_style(backButton, LV_BTN_STYLE_REL, &backStyle); //set the relesed style
    lv_btn_set_style(backButton, LV_BTN_STYLE_PR, &backStyle); //set the pressed style
    lv_obj_set_size(backButton, 100, 60); //set the button size
    lv_obj_align(backButton, NULL, LV_ALIGN_CENTER, 0, 20); //set the position to top mid

    backButtonLabel = lv_label_create(backButton, NULL); //create label and puts it inside of the button
    lv_label_set_text(backButtonLabel, "Back"); //sets label text

    lv_scr_load(skillsScreen);

    menuSetup();

    lv_btn_set_style(skillsButton, LV_BTN_STYLE_REL, &menuStyle2);

    skills1Button = lv_btn_create(skillsScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(skills1Button, LV_BTN_ACTION_CLICK, skl1_btn_click_action); //set function to be called on button click
    lv_btn_set_style(skills1Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(skills1Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(skills1Button, 240, 100); //set the button size
    lv_obj_align(skills1Button, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 40); //set the position to top mid

    skills1ButtonLabel = lv_label_create(skills1Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(skills1ButtonLabel, "Skills 1"); //sets label text

	skills2Button = lv_btn_create(skillsScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(skills2Button, LV_BTN_ACTION_CLICK, skl2_btn_click_action); //set function to be called on button click
    lv_btn_set_style(skills2Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(skills2Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(skills2Button, 240, 100); //set the button size
    lv_obj_align(skills2Button, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 40); //set the position to top mid

    skills2ButtonLabel = lv_label_create(skills2Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(skills2ButtonLabel, "Skills 2"); //sets label text

	skills3Button = lv_btn_create(skillsScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(skills3Button, LV_BTN_ACTION_CLICK, skl3_btn_click_action); //set function to be called on button click
    lv_btn_set_style(skills3Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(skills3Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(skills3Button, 240, 100); //set the button size
    lv_obj_align(skills3Button, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 140); //set the position to top mid

    skills3ButtonLabel = lv_label_create(skills3Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(skills3ButtonLabel, "Skills 3"); //sets label text

	skills4Button = lv_btn_create(skillsScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(skills4Button, LV_BTN_ACTION_CLICK, skl4_btn_click_action); //set function to be called on button click
    lv_btn_set_style(skills4Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(skills4Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(skills4Button, 240, 100); //set the button size
    lv_obj_align(skills4Button, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 140); //set the position to top mid

    skills4ButtonLabel = lv_label_create(skills4Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(skills4ButtonLabel, "Skills 4"); //sets label text

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

    saveExit = lv_btn_create(saveScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(saveExit, LV_BTN_ACTION_CLICK, autonsMenu_btn_click_action); //set function to be called on button click
    lv_btn_set_style(saveExit, LV_BTN_STYLE_REL, &invisibleStyle); //set the relesed style
    lv_btn_set_style(saveExit, LV_BTN_STYLE_PR, &invisibleStyle);
    lv_obj_set_size(saveExit, 480, 240); //set the button size
    lv_obj_align(saveExit, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0); //set the position to top mid

    //----------------------------------------

    lv_scr_load(startScreen);

    lv_obj_t * mbox1 = lv_mbox_create(lv_scr_act(), NULL);
    lv_mbox_set_text(mbox1, "Did you finish\n"
                            "the robot"); 
                                               
    static const char * btns[] ={"\221Yes!", "\221No :(", ""}; /*Button description. '\221' lv_btnm like control char*/
    lv_mbox_add_btns(mbox1, btns, mbox_apply_action);
    lv_obj_set_width(mbox1, 250);
    lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); 

    lv_scr_load(teamScreen);
}

int stormlib::selector::getAuton() {
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
}