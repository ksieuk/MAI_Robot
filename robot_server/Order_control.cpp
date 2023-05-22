#include "Order_control.h"
#include "Order.h"
#include <iostream>
#include <vector>
#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <mosquitto.h>

using namespace std;

#define input_topic "/robot_mai/order_control"

bool Order_control::order_exist = false;

void Order_control::connect_callback(struct mosquitto *mosq, void *obj, int result) {
    printf("connect callback(order_manager mqtt), rc=%d\n", result);
}


void Order_control::message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message) {
    printf("got message '%.*s' for topic '%s'\n", message->payloadlen, (char*) message->payload, message->topic);

    std::cout << "Message recieved"; 
    order_exist = true;
}

Order_control::Order_control(char *s, int p): server(s), port(p){
    mosquitto_lib_init();
    mosq = mosquitto_new(clientid, true, 0);
    if (mosq){
        mosquitto_connect_callback_set(mosq, connect_callback);
        mosquitto_message_callback_set(mosq, message_callback);
        rc = mosquitto_connect_async(mosq, server, port, 60);
        mosquitto_loop_start(mosq);
        mosquitto_subscribe(mosq, NULL, input_topic, 0);
    }
}

Order_control::~Order_control(){
    mosquitto_disconnect(mosq);
    mosquitto_loop_stop(mosq, false);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
}

void Order_control::loop(){
        if(rc){
            printf("connection error! (order_manager mqtt)\n");
            mosquitto_reconnect(mosq);
        }
}

void Order_control::addOrder(Order ord){
    orderList.push_back(ord);
}

void Order_control::deleteOrder(){
    order_exist = false;
}

bool Order_control::ordersExists(){
    if (order_exist = true){
        return true;
    }
    else {
        return false;
    }
}