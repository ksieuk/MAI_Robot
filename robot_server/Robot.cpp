#include "Robot.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <mosquitto.h>
#include <string.h>
#define NUM_MESSAGES 30
#define THREAD 10
#define KEEP_ALIVE 60
#define MQTT_PUB_TOPIC "abot/command/Alex"
#define MQTT_QOS_LEVEL 2
#define MSG_MAX_SIZE 512

Robot::Robot(char *s, int p): server(s), port(p){
};

void Robot::sendtoserver (const char* data) {
    bool clean_session = true;
    struct mosquitto *mosq = NULL;
    mosq = mosquitto_new( NULL, clean_session, NULL );
    mosquitto_connect(mosq, server, port, KEEP_ALIVE);
    mosquitto_publish( mosq, NULL, MQTT_PUB_TOPIC, strlen(data), data, 0, 0 );
    mosquitto_destroy( mosq );
}

void Robot::moveForward() {
    sendtoserver("{ \"cmd\":\"forward\", \"val\": 0.1, \"spd\": 0.3}");
}

void Robot::turnLeft() {
    sendtoserver("{ \"cmd\":\"left\", \"val\": 0.1, \"spd\": 0.3}");
}

void Robot::turnRight() {
    sendtoserver("{ \"cmd\":\"right\", \"val\": 0.1, \"spd\": 0.3}");
}