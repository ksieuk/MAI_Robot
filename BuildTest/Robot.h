#pragma once

class Robot {
private:
	int posX;
	int posY;
	int status;
public:
	Robot() {
		posX = 0;
		posY = 0;
		status = 0;
	};
	void moveForward();
	void setAngle();
	void moveBack();
	void stop();
};

