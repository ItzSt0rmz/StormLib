#include "main.h"
#include "stormlib/led.hpp"

stormlib::aRGB strand1(6, 26);
stormlib::aRGB strand2(7,31);
stormlib::aRGB strand3(8, 26);

stormlib::selector autonSelector(stormlib::selector::E_BLUE_RIGHT_4, "AWP", "5Ring", "Goal Rush", "Disrupt");

stormlib::aRGB_manager manager(
	&strand1,
	&strand2,
	&strand3,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr
);

void autonLeft1() {

} 

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	autonSelector.initialize();
	manager.initialize();
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
	int auton = autonSelector.getAuton();

	if (auton == 0) autonLeft1(); // put default auton here
	if (auton == stormlib::selector::E_BLUE_LEFT_1) autonLeft1();
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
	strand1.rainbow();
	strand2.rainbow();
	strand3.rainbow();
}
