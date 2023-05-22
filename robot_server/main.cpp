#include "opencv2/opencv.hpp"
#include <iostream>
#include "Robot.h"
#include "Robot_control.h"
#include "Camera.h"
#include "Order.h"
#include "Order_control.h"


using namespace std;
using namespace cv;

#define mqtt_host "broker.hivemq.com"
#define mqtt_port 1883

int main() {
    Robot *robot = new Robot(mqtt_host, mqtt_port);
    Detector *cam = new Detector(0);
    Order_control *ord_control = new Order_control(mqtt_host, mqtt_port); 
    Robot_control *control = new Robot_control(cam, robot, ord_control);
    

    Order fOrd;

    ord_control->addOrder(fOrd);

    cam->set_color_bot_front(166, 180, 80);//pink
    cam->set_color_bot_rear(110, 170, 70);//blue
    cam->set_color_target(31, 25, 50);//green

    control->start();
}
