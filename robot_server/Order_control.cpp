#include "Order_control.h"
#include <iostream>
#include <vector>

using namespace std;

void Order_control::addOrder(Order ord){
    orderList.push_back(ord);
}

void Order_control::deleteOrder(){
    orderList.erase(orderList.begin());
}

bool Order_control::ordersExists(){
    if (orderList.size() > 0){
        return true;
    }
    else {
        return false;
    }
}