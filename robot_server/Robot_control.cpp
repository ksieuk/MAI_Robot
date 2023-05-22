#include "Robot_control.h"
#include "Robot.h"
#include "Order_control.h"
#include "opencv2/opencv.hpp"
#include <iostream>

Robot_control::Robot_control(Detector* cam, Robot* bot, Order_control* ord_control) {
	this->status = 0;
	this->robot = bot;
	this->cam = cam;
	this->ord_control = ord_control;
}

void Robot_control::start() {
	for (;;) {
		this->cam->update_image();
        this->cam->draw_image();
		piloting();
		std::cout << "piloting completed";
		if (cv::waitKey(33) == 27) break;
	}
}

void Robot_control::piloting() {
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
		if (cam->get_angle_to_home() > 0){
			this->status = 2;
		}
		else {
			this->status = 3;
		}

		if (cam->has_delta_distance_to_home(200)){
			robot->moveForward();
			std::cout << "MoveForward";
		}
		else {
			this->status = 4;
		}

	case 2:
		//Robot is turnig left
		robot->turnLeft();
		break;

	case 3:
		//Robot is turning right
		robot->turnRight();
		break;

	case 4:
		//Delete the order
		//ord_control->deleteOrder();
		this->status = 1;
		break;
	}
}