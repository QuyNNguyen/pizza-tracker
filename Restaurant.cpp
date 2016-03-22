//
//  Restaurant.cpp
//  PizzaProject
//
//  Created by Quy Nguyen on 12/1/15.
//  Copyright (c) 2015 Quy Nguyen. All rights reserved.
//

#include "Restaurant.h"
#include <iostream>
using namespace std;


void Restaurant::addOrder(Order * order){
    Order* newO = new Order(*order);
    cookingQueue.push_back(newO);
}


void Restaurant::serveNextOrder() throw (logic_error){
    if(cookingQueue.empty())
        throw logic_error("Cooking queue is empty");
    deliveryQueue.push_back(cookingQueue.front());
    cookingQueue.pop_front();
}


Order* Restaurant::departNextOrder() throw (logic_error){
    if(deliveryQueue.empty())
        throw logic_error("Delivery queue is empty");
    deliveringQueue.push_back(deliveryQueue.front());
    Order* tempOrder = deliveryQueue.front();
    deliveryQueue.pop_front();
    return tempOrder;
}


Driver * Restaurant::getDriver(string name){
    if (driverList.empty()) return NULL;
    for (list<Driver*>::iterator it= driverList.begin(); it != driverList.end(); ++it){
        Driver temp = **it;
        if (name.compare(temp.getName()) == 0) return *it;
    }
    
    return NULL;
}


void Restaurant::addDriver(Driver * driver){
    driverList.push_back(driver);
}

void Restaurant::deliver(Driver * driver, Time time, float tip) {
    (*driver).deliver(time, tip);
    deliveringQueue.pop_front();
    completedNumOrdered++;
    
}

void Restaurant::status(){
    cout << endl << "----STATUS----" << endl;
    cout << "Orders waiting to cook: " <<endl;
     for (auto it = cookingQueue.begin(); it!= cookingQueue.end(); ++it){
         cout << (**it).toString() << endl;
    }
    cout << "Orders waiting to depart: " <<endl;
    for (auto it = deliveryQueue.begin(); it!= deliveryQueue.end(); ++it){
        cout << (**it).toString() << endl;
    }
    cout << "Driver: " <<endl;
    auto it2= deliveringQueue.begin();
    if (!(deliveringQueue.empty())) {
        for (auto it= driverList.begin(); it != driverList.end(); ++it){
            if ((**it).isDelivering()){
                cout << (**it).getName() << " ";
                cout << (**it2).toString()<<endl;
                it2++;
            }
        }

    }
    
}


void Restaurant::summary(){
    int totalMinute= 0;
    cout << endl << "----SUMMARY----" << endl;
    
    cout << "Number of Orders completed: " << completedNumOrdered <<endl;
    
    for (auto it= driverList.begin(); it != driverList.end(); ++it){
        totalMinute += (**it).getTotalMinDelivering();
    }
    cout << "Average time per order: ";
    if(completedNumOrdered >0){
        cout << (totalMinute/ completedNumOrdered) <<endl;
    }
    else cout << 0 <<endl;
    for (auto it= driverList.begin(); it != driverList.end(); ++it){
        cout << (**it).toString() << endl;
    }
}


