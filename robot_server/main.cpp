#include "opencv2/opencv.hpp"
#include <iostream>
#include "Robot.h"
#include "Robot_control.h"
#include "Camera.h"
#include "Order.h"
#include "User.h"
#include "Order_control.h"


using namespace std;
using namespace cv;

#define mqtt_host "broker.hivemq.com"
#define mqtt_port 1883

int main() {
	Robot *robot = new Robot(mqtt_host, mqtt_port);
    Camera *cam = new Camera(0);
    Order_control *ord_control = new Order_control; 
    Robot_control *control = new Robot_control(cam, robot, ord_control);
    Order fOrd;

    ord_control->addOrder(fOrd);

    cam->setColorBotFront(34, 65, 255);
    cam->setColorBotRear(176, 130, 170);
    cam->setColorHome(130, 120, 65);
    cam->setColorTarget(90, 249, 68);

    control->start();
}
