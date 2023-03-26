#include "Camera.h"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;
using namespace cv;

Camera::Camera(int i) {
    this->cap.open(i); //capture the video from web cam

    if (!this->cap.isOpened())
    {
        cout << "Cannot open the web cam" << endl;
    }
}

Mat Camera::getImage() {
	//cout << "Get Image";

	cap >> frame;
	return frame;
}
	

void Camera::updateImage() {
	//cout << "Update Image";

	frameResult = getImage();

	frameResult = findRobot(frameResult);

	//frameResult = findTarget(frameResult);
	//frontP = calcRectMiddle(front);
	//backP = calcRectMiddle(back);
	//middleP = calcRobotMiddle(frontP, backP);
	//cout << middleP;
}


Mat Camera::findRobot(Mat frameR) {
	vector <Rect> buf;
	int min = 40;
	//fint the front of robot
	cv::cvtColor(frameR, imgHSV, COLOR_BGR2HSV);
	cv::inRange(frameR, Scalar(150, 120, 120), Scalar(172, 255, 255), imgThresholded);
	for (int y = 0; y < imgThresholded.rows; y++) {
		for (int x = 0; x < imgThresholded.cols; x++) {
			int value = imgThresholded.at<uchar>(y, x);
			if (value == 255) {
				Rect rectF;
				int count = floodFill(imgThresholded, Point(x, y), Scalar(200), &rectF);
				//buf.push_back(rectF);
				if (rectF.width >= min && rectF.height >= min) {
					rectangle(frameR, rectF, Scalar(255, 0, 255, 4));
				}
				//front = rectF;
			}
		}
	}

	imshow("Tresholded", imgThresholded);
	/*Rect max;
	for (auto it = buf.begin(); it != buf.end(); it++) {
		if (*it.heght > max) {
		
		}
	}*/
	
	//buf.clear();

	//find the back of robot
	cv::inRange(frameR, Scalar(68, 120, 120), Scalar(122, 255, 255), imgThresholded2);
	for (int y = 0; y < imgThresholded2.rows; y++) {
		for (int x = 0; x < imgThresholded2.cols; x++) {
			int value = imgThresholded2.at<uchar>(y, x);
			if (value == 255) {
				Rect rectB;
				buf.push_back(rectB);
				int count = floodFill(imgThresholded2, Point(x, y), Scalar(200), &rectB);
				if (rectB.width >= min && rectB.height >= min) {
					rectangle(frameR, rectB, Scalar(125, 0, 200, 4));
				}
				//back = rectB;
			}
		}
	}
	imshow("Tresholded2", imgThresholded2);
	cv::imshow("main", frameR);
	return frameR;
}

Mat findTarget(Mat frameR) {
	cout << "Target found";
	cv::Mat frameRs = frameR;
	return frameRs;
}

Point Camera::calcRectMiddle(Rect rect){
	int x = rect.x + (rect.width / 2);
	int y = rect.y + (rect.height / 2);

	return Point(x, y);
}


Point Camera::calcRobotMiddle(Point a, Point b) {
	int x = (a.x + b.x) / 2;
	int y = (a.y + b.y) / 2;
	return Point(x, y);
}

int Camera::calcAngleToTarget(Point robot, Point target) {
	double cos = (robot.x + robot.y) / (sqrt(robot.x * robot.x + robot.y * robot.y) * sqrt(target.x * target.x + target.y * target.y));
	double angle = acos(cos) * 180 / 3.14;
	if (angle >= 0)
		return angle;
	else
		return 360 + angle;
}

int calcDistanceToTarget(Point a, Point b) {
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}