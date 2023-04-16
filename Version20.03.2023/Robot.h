#pragma once

class Robot {
public:
	void moveForward();
	void setAngle();
	void moveBack();
	void stop();

	char* server = nullptr;
    int port;

    void sendtoserver(const char* data);

	Robot(char *s, int p);
};