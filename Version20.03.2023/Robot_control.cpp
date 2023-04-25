#include "Robot_control.h"
#include "Robot.h"
#include "Order_control.h"
#include "opencv2/opencv.hpp"
#include <iostream>

Robot_control::Robot_control(Camera* cam, Robot* bot, Order_control* ord_control) {
	this->status = 0;
	this->robot = bot;
	this->cam = cam;
	this->ord_control = ord_control;
}

void Robot_control::start() {
	for (;;) {
		this->cam->updateImage();
		piloting();
		if (cv::waitKey(33) == 27) break;
	}
}

void Robot_control::piloting() {
	robot->moveForward();
	switch (this->status) {
	case 0:
		//Robot is waiting
		if (ord_control->ordersExists()){
			this->status = 1;
		}
		else{
			break;
		}
	case 1:
		//Robot is moving
		if (cam->getAngle > 0){
			this->status = 2;
		}
		else {
			this->status = 3;
		}

		if (cam->getDistanceToTarget > 200){
			robot->moveForward;
		}
		else {
			this->status = 4;
		}
		this->status = 0;
	case 2:
		//Robot is turnig left
		robot->turnLeft;
		break;

	case 3:
		//robot is turning right
		robot->turnRight;
		break;

	case 4:
		
	}
}