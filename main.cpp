#include "opencv2/opencv.hpp"
#include <iostream>
#include "Robot.h"
#include "Robot_control.h"
#include "Camera.h"
#include "Order.h"
#include "User.h"


using namespace std;
using namespace cv;

int main() {
	Robot *robot = new Robot;
    Camera *cam = new Camera(0);
    Robot_control *control = new Robot_control(cam, robot);
    control->start();
}
