#pragma once

#include "Robot.h"
#include "Camera.h"


class Robot_control {
private:
	Robot *robot;
	Camera *cam;
	Position *pos;
	int status;
public:
	Robot_control(Camera* cam, Robot* bot) {
		this->status = 0;
	};
	void start();
	void piloting();
};