#pragma once

class Robot {
public:
	void moveForward();
	void turnLeft();
	void turnRight();

	char* server = nullptr;
    int port;

    void sendtoserver(const char* data);

	Robot(char *s, int p);
};