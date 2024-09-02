#include "main.h"

stormlib::aRGB strand(1, 50);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	selector_initialize();
	strand.init();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	if (!isSkills) {
		if (isRed) {
			if (isLeft) {
				if (currentAuton == 1) {}; // Red Left AWP
				if (currentAuton == 2) {}; // Red Left Safe
				if (currentAuton == 3) {}; // Red Left Rush
				if (currentAuton == 4) {}; // Red Left Misc
			}
			else {
				if (currentAuton == 1) {}; // Red Right AWP
				if (currentAuton == 2) {}; // Red Right Safe
				if (currentAuton == 3) {}; // Red Right Rush
				if (currentAuton == 4) {}; // Red Right Misc
			}
		}
		else {
			if (isLeft) {
				if (currentAuton == 1) {}; // Blue Left AWP
				if (currentAuton == 2) {}; // Blue Left Safe
				if (currentAuton == 3) {}; // Blue Left Rush
				if (currentAuton == 4) {}; // Blue Left Misc
			}
			else {
				if (currentAuton == 1) {}; // Blue Right AWP
				if (currentAuton == 2) {}; // Blue Right Safe
				if (currentAuton == 3) {}; // Blue Right Rush
				if (currentAuton == 4) {}; // Blue Right Misc
			}
		}
	}
	else {
		if (currentAuton == -1) {}; // Skills 1
		if (currentAuton == -2) {}; // Skills 2
		if (currentAuton == -3) {}; // Skills 3
		if (currentAuton == -4) {}; // Skills 4
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	strand.breathe(0x0000FF);
}
