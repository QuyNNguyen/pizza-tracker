//
//  Order.cpp
//  PizzaProject
//
//  Created by Quy Nguyen on 12/1/15.
//  Copyright (c) 2015 Quy Nguyen. All rights reserved.
//

#include "Order.h"
#include "Time.h"

Order::Order (Order const &o){
    info = o.info;
    state = o.state;
    timeOrder = o.timeOrder;
}

void Order::depart() throw (logic_error){
    if (state != 0)
        throw logic_error("Order is not at the restaurant for delivery");
    state = 1;
}



void Order:: deliver(Time time) throw (logic_error){
    if (state != 1)
        throw logic_error("Order is not out for delivery to be delivered");
    state = 2;
    timeDelivered = time;

}



int Order::getMinToDelivery() throw (logic_error){
    return Time::elapsedMin(timeOrder, timeDelivered);
}



string Order::toString(){
    string result = timeOrder.toString();
    result.append(" "); 
    result.append(info);
    return result;
}