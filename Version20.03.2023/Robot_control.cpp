#include "Robot_control.h"
#include "Robot.h"
#include "opencv2/opencv.hpp"
#include <iostream>

Robot_control::Robot_control(Camera* cam, Robot* bot) {
	this->status = 0;
	this->robot = bot;
	this->cam = cam;
}

void Robot_control::start() {
	for (;;) {
		this->cam->updateImage();
		//piloting();
		if (cv::waitKey(33) == 27) break;
	}
}

void Robot_control::piloting() {
	switch (this->status) {
	case 0:
		std::cout << "Robot waiting";
		this->status = 1;
	case 1:
		std:: cout << "Robot get order";
		this->status = 2;
	case 2:
		std::cout << "Robot moving";
		this->status = 3;
	case 3:
		std::cout << "Robot rotating";
		this->status = 4;
	case 4:
		std::cout << "Robot finished";
		this->status = 0;
	}
}