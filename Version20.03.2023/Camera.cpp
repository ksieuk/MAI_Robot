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

	//frameResult = findTarget(frameResult);

	frameResult = findRobot(frameResult);

	frontP = calcRectMiddle(front);
	backP = calcRectMiddle(back);
	middleP = calcRobotMiddle(frontP, backP);
	//cout << middleP;
}


Mat Camera::findRobot(Mat frameR) {

	vector <Rect> buf;

	int min = 40;

	//fint the front of robot
	cv::cvtColor(frameR, imgHSV, COLOR_BGR2HSV);
	cv::inRange(imgHSV, Scalar(150, 120, 120), Scalar(172, 255, 255), imgThresholded);
	for (int y = 0; y < imgThresholded.rows; y++) {
		for (int x = 0; x < imgThresholded.cols; x++) {
			int value = imgThresholded.at<uchar>(y, x);
			if (value == 255) {
				Rect rectF;
				int count = floodFill(imgThresholded, Point(x, y), Scalar(200), &rectF);
				if (rectF.width >= min && rectF.height >= min) {
					buf.push_back(rectF);
				}
			}
		}
	}

	//imshow("Pink", imgThresholded);

	Rect max;
	for (int i = 0; i < buf.size(); i++) {
		if (buf[i].height * buf[i].width > max.height * max.width) {
			max = buf[i];
		}
	}
	rectangle(frameR, max, Scalar(255, 0, 255, 4));
	front = max;

	buf.clear();

	//find the back of robot
	cv::inRange(imgHSV, Scalar(68, 120, 120), Scalar(122, 255, 255), imgThresholded2);
	for (int y = 0; y < imgThresholded2.rows; y++) {
		for (int x = 0; x < imgThresholded2.cols; x++) {
			int value = imgThresholded2.at<uchar>(y, x);
			if (value == 255) {
				Rect rectB;
				int count = floodFill(imgThresholded2, Point(x, y), Scalar(200), &rectB);
				if (rectB.width >= min && rectB.height >= min) {
					buf.push_back(rectB);
				}
			}
		}
	}

	//imshow("Blue", imgThresholded2);

	for (int i = 0; i < buf.size(); i++) {
		if (buf[i].height * buf[i].width > max.height * max.width) {
			max = buf[i];
		}
	}
	rectangle(frameR, max, Scalar(125, 0, 200, 4));
	back = max;

	buf.clear();

	int min = 40;
	//find the target
	cv::cvtColor(frameR, imgHSV, COLOR_BGR2HSV);
	cv::inRange(imgHSV, Scalar(45, 115, 170), Scalar(60, 255, 255), imgThresholded3);
	for (int y = 0; y < imgThresholded3.rows; y++) {
		for (int x = 0; x < imgThresholded3.cols; x++) {
			int value = imgThresholded3.at<uchar>(y, x);
			if (value == 255) {
				Rect rect;
				int count = floodFill(imgThresholded3, Point(x, y), Scalar(200), &rect);
				if (rect.width >= min && rect.height >= min) {
					buf.push_back(rect);
				}
			}
		}
	}

	imshow("Target", imgThresholded3);

	Rect max;
	for (int i = 0; i < buf.size(); i++) {
		if (buf[i].height * buf[i].width > max.height * max.width) {
			max = buf[i];
		}
	}
	rectangle(frameR, max, Scalar(125, 0, 200, 4));
	targetP = calcRectMiddle(max);

	buf.clear();

	cv::imshow("main", frameR);
	return frameR;
}

Mat Camera::findTarget(Mat frameR) {
	vector <Rect> buf;

	int min = 40;
	//find the target
	cv::cvtColor(frameR, imgHSV, COLOR_BGR2HSV);
	cv::inRange(imgHSV, Scalar(45, 115, 170), Scalar(60, 255, 255), imgThresholded3);
	for (int y = 0; y < imgThresholded3.rows; y++) {
		for (int x = 0; x < imgThresholded3.cols; x++) {
			int value = imgThresholded3.at<uchar>(y, x);
			if (value == 255) {
				Rect rect;
				int count = floodFill(imgThresholded3, Point(x, y), Scalar(200), &rect);
				if (rect.width >= min && rect.height >= min) {
					buf.push_back(rect);
				}
			}
		}
	}

	imshow("Target", imgThresholded3);

	Rect max;
	for (int i = 0; i < buf.size(); i++) {
		if (buf[i].height * buf[i].width > max.height * max.width) {
			max = buf[i];
		}
	}
	rectangle(frameR, max, Scalar(125, 0, 200, 4));
	targetP = calcRectMiddle(max);
	return frameR;
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

int Camera::calcAngleToTarget(Point robotFront, Point robotMiddle, Point target) {
	Point robotVector;
	robotVector.x = robotFront.x - robotMiddle.x;
	robotVector.y = robotFront.y - robotMiddle.y;

	Point targetVector;
	targetVector.x = targetVector.x - targetVector.x;
	targetVector.y = targetVector.y - targetVector.y;

	double cos = (robotVector.x * targetVector.x + robotVector.y + targetVector.y ) / (sqrt(robotVector.x * robotVector.x + robotVector.y * robotVector.y) * sqrt(targetVector.x * targetVector.x + targetVector.y * targetVector.y));
	double angle = acos(cos) * 180 / 3.14;
	if (angle >= 0)
		return angle;
	else
		return 360 + angle;
}

int Camera::calcDistanceToTarget(Point a, Point b) {
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int Camera::getDistanceToTarget(){
	int dist;
	dist = calcDistanceToTarget(middleP, targetP);
	return dist;
}

int Camera::getAngle(){
	int angle;
	angle = calcAngleToTarget(frontP, middleP, targetP);
	return angle;
}