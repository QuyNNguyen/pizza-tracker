// Driver.cpp
// by eifu


#include "Driver.h"
#include "Time.h"
#include <iostream>

Driver::Driver(std::string name) throw (std::logic_error){
    std::size_t found = name.find(" ");
    if(found != std::string::npos) throw std::logic_error("er 22ror");
    else{
        myName = name;
        myLog = false;
        myDelivering = false;
        myDriving = false;
        myTips = 0;
        totalDeliveries = 0;
        totalMinDelivering = 0;
        totalMinDriving = 0;
    }
}

Driver::~Driver(){

}

void Driver::login()  throw (std::logic_error){
    myLog = true;
}

void Driver::logout(){
    myLog = false;
}


void Driver::depart(Time time, Order o) throw (std::logic_error){
    myDelivering = true;
    myDriving = true;
    departureTime = time;
    myOrder = o;
}
void Driver::deliver(Time time, float tip) throw(std::logic_error){
    myDelivering = false;

    myTips += tip;
    totalMinDelivering += Time::elapsedMin(departureTime,time);
}
void Driver::arrive(Time time) throw (std::logic_error){
    if(myDelivering || !myDriving ) throw std::logic_error("error");
    else{
         totalMinDriving += Time::elapsedMin(departureTime,time);
        totalDeliveries++;
         myDriving = false;
     }
}

Order Driver::getOrder() throw (std::logic_error){
    if(!myDelivering) throw std::logic_error("error");
    else return myOrder;
}
std::string Driver::toString(){
    return "Driver: "+myName
           +"\n Number of deliveries completed: "+std::to_string(totalDeliveries)
           +"\n Average time per delivery: "+std::to_string(totalMinDelivering)
           +"\n Total driving time: "+std::to_string(totalMinDriving)
           +"\n Total tips: "+std::to_string(myTips);
}
