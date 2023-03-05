#include "Robot_control.h"
#include "Robot.h"
#include <iostream>

void Robot_control::setRobot(Robot robot) {
	this->robot = robot;
	std::cout << "Robot have been set";
}
void Robot_control::moveForward() {
	robot.moveForward();
}

void Robot_control::setAngle() {
	robot.setAngle();
}

void Robot_control::moveBack() {
	robot.moveBack();
}

void Robot_control::stop() {
	robot.stop();
}