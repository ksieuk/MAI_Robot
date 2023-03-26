#pragma once

#include "Robot.h"
#include "Camera.h"


class Robot_control {
private:
	Robot *robot;
	Camera *cam;
	int status;
public:
	Robot_control(Camera* cam, Robot* bot);
	void start();
	void piloting();
};