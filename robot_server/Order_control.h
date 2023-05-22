#pragma once
#include "Order.h"
#include <vector>

class Order_control{
private:
    std::vector <Order> orderList;
    //Order currentOrder;
public:
    //Order_control();
    void addOrder(Order ord);
    bool ordersExists();
    void deleteOrder();
};
