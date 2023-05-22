#pragma once

#include "Order.h"
#include <vector>
#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

class Order_control{
private:
    std::vector <Order> orderList;

    char* server = nullptr;
    int port;

    uint8_t reconnect = true;
    char clientid[14] = "order_manager";
    struct mosquitto *mosq;
    int rc = 0;

    static void connect_callback(struct mosquitto *mosq, void *obj, int result);
    static void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);

    //Order currentOrder;
public:
    Order_control(char *s, int p);
    ~Order_control();
    //Order_control();
    void addOrder(Order ord);
    bool ordersExists();

    void set_order_exist();

    void deleteOrder();
    void loop();

    static bool order_exist;
};
