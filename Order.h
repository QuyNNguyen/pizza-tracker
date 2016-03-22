//
//  Order.h
//  PizzaProject
//
//  Created by Quy Nguyen on 12/1/15.
//  Copyright (c) 2015 Quy Nguyen. All rights reserved.
//

#ifndef _ORDER_H
#define _ORDER_H

#include <string>
#include <stdio.h>
#include "Time.h"
using namespace std;

class Order{
private:
    int state;   // 3 states: at the restaurant - 0 / out for delivery - 1 / delivered - 2
    string info;
    Time timeOrder;
    Time timeDelivered;
    bool isAtRestaurant;
    bool isDelivered;
public:
    /* --- Order constructor --------------------------------------
     Constructs an empty Order object.
     
     Precondition:  None.
     Postcondition: Creates an order with default values for data members.
     ---------------------------------------------------------------------*/
    inline Order(){Time time; timeOrder = time; info = ""; state = 0;    isAtRestaurant = true;
        isDelivered = false;};
    
    
    Order(Order const & o);
    
    
    /* --- Order constructor with arguments --------------------------------------
     Constructs an empty Order object.
     
     Precondition:  None.
     Postcondition: Creates an order with the given order time and information.
     ---------------------------------------------------------------------*/
    inline Order(Time time, string information){timeOrder = time, info = information; state =0;isAtRestaurant = true;isDelivered = false;
};
    
    
    /* --- depart() --------------------------------------
     Set state of the order to be "out for delivery"
     
     Pre: Order is at the restaurant
     Post: Order is set out for delivery.
     ---------------------------------------------------------------------*/
    void depart() throw (logic_error); 
    
    
    /* --- delivery() --------------------------------------
     Set state of the order to be "delivered"
     
     Pre: Order is out for delivery.
     Post: Order is delivered. Time to delivery is recorded.
     ---------------------------------------------------------------------*/
    void deliver(Time time) throw (logic_error);
    
    
    /* --- getMinToDelivery() --------------------------------------
     Returns the minutes until the order is delivered
     
     Pre: Order is delivered.
     Post: Returns the minutes until the order is delivered (i.e., between “order” and “deliver” commands).
     ---------------------------------------------------------------------*/
    int getMinToDelivery() throw (logic_error);
    
    /* --- toString() --------------------------------------
     Returns a string containing the order time and info.
     
     Post: None.
     Post: Returns a string containing the order time and info.
     ---------------------------------------------------------------------*/
    string toString();
    
};



#endif /* defined(__PizzaProject__Order__) */
