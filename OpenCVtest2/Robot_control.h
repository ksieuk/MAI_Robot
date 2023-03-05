#pragma once

#include "Robot.h"

class Robot_control {
private:
	Robot robot;
public:
	void setRobot(Robot robot);
	void moveForward();
	void setAngle();
	void moveBack();
	void stop();
};