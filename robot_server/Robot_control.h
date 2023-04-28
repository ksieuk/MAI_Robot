#pragma once

#include "Robot.h"
#include "Camera.h"
#include "Order_control.h"


class Robot_control {
private:
	Robot *robot;
	Camera *cam;
	Order_control *ord_control;
	int status;
public:
	Robot_control(Camera* cam, Robot* bot, Order_control* ord_control);
	void start();
	void piloting();
};