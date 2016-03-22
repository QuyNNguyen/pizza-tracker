//
//  Restaurant.h
//  PizzaProject
//
//  Created by Quy Nguyen on 12/1/15.
//  Copyright (c) 2015 Quy Nguyen. All rights reserved.
//

#ifndef __PizzaProject__Restaurant__
#define __PizzaProject__Restaurant__

#include <stdio.h>
#include "Order.h"
#include "Driver.h"
#include <queue>
#include <list>
#include <deque>

class Restaurant{
private:
    int completedNumOrdered; 
    list <Driver*> driverList;
    deque <Order*> cookingQueue;
    deque <Order*> deliveryQueue;
    deque <Order*> deliveringQueue;
public:
    /* --- Restaurant constructor -----------------------------------------
     Constructs an empty restaurant object.
     
     Precondition:  None.
     Postcondition: Creates an empty restaurant.
     ---------------------------------------------------------------------*/
//    Restaurant();
    
    
    /* --- status() --------------------------------------------------------
     Prints status of orders and logged-in drivers
     
     Precondition:  None.
     Post: Prints status of orders and logged-in drivers
           Example:
                    Orders waiting to cook:
                    18:30 1 cheese 1 sausage to 1000 Beall Ave
                    Orders waiting to depart:
                    Drivers:
                    Bev 18:02 4 spinach to 100 Liberty St
     ---------------------------------------------------------------------*/
    void status();
    
    
    /* --- summary() -------------------------------------------------------
     Prints summary statistics on orders and drivers
     
     Precondition:  None.
     Post: Prints summary statistics on orders and drivers
           Example:
                    Number of Orders completed: 1
                    Average time per order: 45
                    Driver Dan:
                    Number of deliveries completed: 1
                    Average time per delivery: 30
                    Total driving time: 45
                    Total tips: 4.5
                    Driver Adam:
                    Number of deliveries completed: 0
                    Average time per delivery: 0
                    Total driving time: 0
                    Total tips: 0
     ---------------------------------------------------------------------*/
    void summary();
    
    
    /* --- getDriver() ---------------------------------------------------------------
     return a driver if he/she exist in the system
     
     Precondition:  None.
     Post: If a driver with the given name exists within the system (logged in or not), 
           returns a pointer to that driver. Otherwise, returns a null pointer.

     ---------------------------------------------------------------------------------*/
    Driver * getDriver(string name);
    
    
    /* --- addDriver() ---------------------------------------------------------------
     Add the given driver to the driverList
     
     Precondition:  None.
     Post: Adds the given driver to the system.
     ---------------------------------------------------------------------------------*/
    void addDriver(Driver * driver);
    
    
    /* --- addOrder() ----------------------------------------------------
     Add the given order to the cooking queue
     
     Precondition:  None.
     Post: Adds the given order to the system, enqueuing it for cooking.
     ---------------------------------------------------------------------*/
    void addOrder(Order * order);
    
    
    /* --- serveNextOrder() ----------------------------------------------
     Removes next order and enqueues it to the delivery queue
     
     Pre: The cooking queue is not empty.
     Post: Removes the oldest order from the cooking queue and enqueues it for departure.
     ---------------------------------------------------------------------*/
     void serveNextOrder() throw (logic_error);
    
    
    /* --- departNextOrder() ---------------------------------------------
     Removes the oldest order from the departure queue and returns it
     
     Pre: The departure queue is not empty.
     Post: Removes the oldest order from the departure queue and returns it.
     ---------------------------------------------------------------------*/
    Order* departNextOrder() throw (logic_error);
    
    
    /* --- deliver() ---------------------------------------------
     Set tip and time delivery for driver when they delivered an order
     
     Pre: The cooking queue is not empty.
     Post: The order carried by the driver is delivered at the given time. 
           The driver receives the given tip.
     ---------------------------------------------------------------------*/
    void deliver(Driver * driver, Time time, float tip);

};

#endif /* defined(__PizzaProject__Restaurant__) */
