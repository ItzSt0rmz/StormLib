#include "main.h"
#include <string>

using namespace pros;

lv_obj_t * vertLine;
lv_obj_t * horzLine;

lv_obj_t * teamScreen;
lv_obj_t * redButton;
lv_obj_t * redButtonLabel;
lv_obj_t * blueButton;
lv_obj_t * blueButtonLabel;

lv_obj_t * sideScreen;
lv_obj_t * leftButton;
lv_obj_t * leftButtonLabel;
lv_obj_t * rightButton;
lv_obj_t * rightButtonLabel;

lv_obj_t * optionScreen;
lv_obj_t * option1Button;
lv_obj_t * option1ButtonLabel;
lv_obj_t * option2Button;
lv_obj_t * option2ButtonLabel;
lv_obj_t * option3Button;
lv_obj_t * option3ButtonLabel;
lv_obj_t * option4Button;
lv_obj_t * option4ButtonLabel;

lv_obj_t * skillsScreen;
lv_obj_t * skills1Button;
lv_obj_t * skills1ButtonLabel;
lv_obj_t * skills2Button;
lv_obj_t * skills2ButtonLabel;
lv_obj_t * skills3Button;
lv_obj_t * skills3ButtonLabel;
lv_obj_t * skills4Button;
lv_obj_t * skills4ButtonLabel;

lv_obj_t * backButton;
lv_obj_t * backButtonLabel;

lv_obj_t * exitButton;
lv_obj_t * exitButtonLabel;
lv_obj_t * autonsButton;
lv_obj_t * autonsButtonLabel;
lv_obj_t * skillsButton;
lv_obj_t * skillsButtonLabel;

lv_obj_t * saveScreen;
lv_obj_t * saveExit;
lv_obj_t * saveDisp;
lv_obj_t * teamNum;

lv_obj_t * startScreen;

lv_style_t myButtonStyleREL; //relesed style
lv_style_t myButtonStylePR; //pressed style
lv_style_t redStyle;
lv_style_t blueStyle;
lv_style_t selectedStyle;
lv_style_t backStyle;
lv_style_t menuStyle1;
lv_style_t menuStyle2;
lv_style_t style_btn_rel;
lv_style_t style_btn_pr;
lv_style_t style_bg;
lv_style_t invisibleStyle;
lv_style_t saveDispStyle;
lv_style_t teamNumStyle;

bool isRed, isLeft, isSkills;
int currentScreen = 1;
int currentAuton = 2;

void resetButtonHighlights() 
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

static lv_res_t exitMenu_btn_click_action(lv_obj_t * btn)
{
    lv_scr_load(saveScreen);
    return LV_RES_OK;
}

static lv_res_t autonsMenu_btn_click_action(lv_obj_t * btn)
{
	lv_scr_load(teamScreen);
    return LV_RES_OK;
}

static lv_res_t skillsMenu_btn_click_action(lv_obj_t * btn)
{
	lv_scr_load(skillsScreen);
    return LV_RES_OK;
}

static lv_res_t red_btn_click_action(lv_obj_t * btn)
{
	isRed = true;
	lv_scr_load(sideScreen);
    return LV_RES_OK;
}

static lv_res_t blue_btn_click_action(lv_obj_t * btn)
{
	isRed = false;
	lv_scr_load(sideScreen);
    return LV_RES_OK;
}

static lv_res_t left_btn_click_action(lv_obj_t * btn)
{
	isLeft = true;
	lv_scr_load(optionScreen);
    return LV_RES_OK;
}

static lv_res_t right_btn_click_action(lv_obj_t * btn)
{
	isLeft = false;
	lv_scr_load(optionScreen);
    return LV_RES_OK;
}

static lv_res_t opt1_btn_click_action(lv_obj_t * btn)
{
	currentAuton = 1;
    resetButtonHighlights();
    lv_btn_set_style(option1Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t opt2_btn_click_action(lv_obj_t * btn)
{
	currentAuton = 2;
    resetButtonHighlights();
    lv_btn_set_style(option2Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t opt3_btn_click_action(lv_obj_t * btn)
{
	currentAuton = 3;
    resetButtonHighlights();
    lv_btn_set_style(option3Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t opt4_btn_click_action(lv_obj_t * btn)
{
	currentAuton = 4;
    resetButtonHighlights();
    lv_btn_set_style(option4Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t skl1_btn_click_action(lv_obj_t * btn)
{
	currentAuton = -1;
    resetButtonHighlights();
    lv_btn_set_style(skills1Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t skl2_btn_click_action(lv_obj_t * btn)
{
	currentAuton = -2;
    resetButtonHighlights();
    lv_btn_set_style(skills2Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t skl3_btn_click_action(lv_obj_t * btn)
{
	currentAuton = -3;
    resetButtonHighlights();
    lv_btn_set_style(skills3Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t skl4_btn_click_action(lv_obj_t * btn)
{
	currentAuton = -4;
    resetButtonHighlights();
    lv_btn_set_style(skills4Button, LV_BTN_STYLE_REL, &selectedStyle);
    return LV_RES_OK;
}

static lv_res_t back_button_click_action1(lv_obj_t * btn)
{
    lv_scr_load(teamScreen);
    return LV_RES_OK;
}

static lv_res_t back_button_click_action2(lv_obj_t * btn)
{
    lv_scr_load(sideScreen);
    resetButtonHighlights();
    return LV_RES_OK;
}

static lv_res_t mbox_apply_action(lv_obj_t * mbox, const char * txt)
{
    lv_scr_load(teamScreen);

    return LV_RES_OK; /*Return OK if the message box is not deleted*/
}

void menuSetup() 
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

void selector_initialize() 
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
    lv_label_set_text(option1ButtonLabel, "AWP"); //sets label text

	option2Button = lv_btn_create(optionScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(option2Button, LV_BTN_ACTION_CLICK, opt2_btn_click_action); //set function to be called on button click
    lv_btn_set_style(option2Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(option2Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(option2Button, 240, 100); //set the button size
    lv_obj_align(option2Button, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 40); //set the position to top mid

    option2ButtonLabel = lv_label_create(option2Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(option2ButtonLabel, "Safe"); //sets label text

	option3Button = lv_btn_create(optionScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(option3Button, LV_BTN_ACTION_CLICK, opt3_btn_click_action); //set function to be called on button click
    lv_btn_set_style(option3Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(option3Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(option3Button, 240, 100); //set the button size
    lv_obj_align(option3Button, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 140); //set the position to top mid

    option3ButtonLabel = lv_label_create(option3Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(option3ButtonLabel, "Rush"); //sets label text

	option4Button = lv_btn_create(optionScreen, NULL); //create button, lv_scr_act() is deafult screen object
    lv_btn_set_action(option4Button, LV_BTN_ACTION_CLICK, opt4_btn_click_action); //set function to be called on button click
    lv_btn_set_style(option4Button, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
    lv_btn_set_style(option4Button, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
    lv_obj_set_size(option4Button, 240, 100); //set the button size
    lv_obj_align(option4Button, NULL, LV_ALIGN_IN_TOP_LEFT, 240, 140); //set the position to top mid

    option4ButtonLabel = lv_label_create(option4Button, NULL); //create label and puts it inside of the button
    lv_label_set_text(option4ButtonLabel, "Misc"); //sets label text

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

}