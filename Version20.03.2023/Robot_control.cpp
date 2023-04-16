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
		std::cout << "Robot waiting";
		if (ord_control->ordersExists()){
			this->status = 1;
		}
		else{
			break;
		}
	case 1:
		//std:: cout << "Robot get order";
		this->status = 2;
	case 2:
		//std::cout << "Robot moving: ";
		//std::cout << cam->getDistanceToTarget();
		this->status = 3;
	case 3:
		//std::cout << "Robot rotating: ";
		//std::cout << cam->getAngle();
		this->status = 4;
	case 4:
		//std::cout << "Robot finished";
		this->status = 0;
	}
}