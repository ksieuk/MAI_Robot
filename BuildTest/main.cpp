#include "opencv2/opencv.hpp"
#include <iostream>
#include "Server.h"
#include "Robot.h"
#include "Robot_control.h"
#include "Camera.h"
#include "Order.h"
#include "User.h"


using namespace std;
using namespace cv;

int main() {
	Robot_control control;
	Robot robot;
	control.setRobot(robot);
}
