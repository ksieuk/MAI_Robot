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

	struct customColor{
		int a;
		int b;
		int c;
		customColor(int _a, int _b, int _c){
			a = _a;
			b = _b;
			c = _c;
		}
	};

	customColor FrontBotColor = customColor(0, 0, 0);
	customColor RearBotColor  = customColor(0, 0, 0);
	customColor TargetColor  = customColor(0, 0, 0);
	customColor HomeColor  = customColor(0, 0, 0);

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
	void setColorBotFront(int a, int b, int c);
	void setColorBotRear(int a, int b, int c);
	void setColorTarget(int a, int b, int c);
	void setColorHome(int a, int b, int c);
	~Camera();
};