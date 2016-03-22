// Driver.h
// by eifu

#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "Order.h"
#include "Time.h"

class Driver{
public:
    inline Driver(){};
    
    Driver(std::string name) throw (std::logic_error);
    /*
    Post: Creates a logged-in driver with the given name.
    */
    ~Driver();
    /*
    Pre: Driver is not logged in.
    Post: Logs the driver in.
    */
    void login()  throw (std::logic_error);
    /*
    Pre: Driver is logged in and at the restaurant.
    Post: Logs the driver out.
    */
    
    void logout();
    
    
    
    
    void depart(Time time, Order o) throw (std::logic_error);
    /*
    Pre: Driver is logged in and at the restaurant.
    Post: Driver is delivering. Departure time is recorded.
    */
    void deliver(Time time, float tip) throw(std::logic_error);
    /*
    Pre: Driver is delivering, tip >= 0.
    Post: Driver is not delivering. Driver’s stats are updated.
    */
    void arrive(Time time) throw (std::logic_error);
    /*
    Pre: Driver is driving but not delivering.
    Post: Driver is at the restaurant. Driver’s stats are updated.
    */
    inline std::string getName(){return myName;};
    /*
    Post: Returns the driver’s name.
    */

    inline bool isLoggedIn(){return myLog;};
    /*
    Post: Returns true if and only if the driver is logged in.
    */

    inline bool isDelivering(){return myDelivering;};

    inline int getTotalDeliveries(){return totalDeliveries;};
    /*
    Post: Returns the total number of completed deliveries.
    */

    inline int getTotalMinDelivering(){return totalMinDelivering;};
    /*
    Post: Returns the total minutes spent delivering (i.e., between “depart”
    and “deliver” commands).
    */

    inline int getTotalMinDriving(){return totalMinDriving;};
    /*
    Post: Returns the total minutes spent driving (i.e., between “depart” and
     “arrive” commands).
    */

    inline float getTotalTips(){return myTips;};
    /*
    Post: Returns the total tips received, in dollars.
    */

    Order getOrder() throw (std::logic_error);
    /*
    Pre: Driver is delivering.
    Post: Returns the order being delivered.
    */
    std::string toString();
    /*
    Post: Returns a string containing the driver’s name, state (e.g., not logged
     in), and, if the driver is delivering an order, the departure time and
     toString of the order being delivered.
    */
    
    void changeName(std::string newName) {myName = newName;};
private:
    float myTips;
    std::string myName;
    int totalDeliveries;
    int totalMinDelivering;
    int totalMinDriving;
    bool myLog;
    bool myDelivering;
    bool myDriving;
    Time departureTime;
    Order myOrder;


};
#endif
