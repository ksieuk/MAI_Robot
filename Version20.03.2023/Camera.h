#pragma once
#include<opencv2/core/mat.hpp>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class Camera {
private:
	Mat frame;
	Mat frameResult;
	Mat imgThresholded;
	Mat imgHSV;
	Mat imgThresholded2;
	Mat imgThresholded3;

	VideoCapture cap;

	Rect front;
	Rect back;
	Rect target;

	Point frontP;
	Point backP;
	Point middleP;
	Point targetP;

	Mat getImage();
	Mat findRobot(Mat frameR);
	Mat findTarget(Mat frameR);
	Point calcRectMiddle(Rect rect);
	Point calcRobotMiddle(Point a, Point b);
	int calcAngleToTarget(Point robotFront, Point robotMiddle, Point target);
	int calcDistanceToTarget(Point a, Point b);
public:
    Camera(int i);
	void updateImage();
	int getDistanceToTarget();
	int getAngle();
	~Camera();
};