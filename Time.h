//
//  Time.h
//  Pizza
//
//  Created by Zhirui on 12/2/15.
//  Copyright (c) 2015 Wooster. All rights reserved.
//

#ifndef __Pizza__Time__
#define __Pizza__Time__

#include <string>
#include <cstddef>


using namespace std;

class Time{
public:
    Time();
    /*
     Post: Creates a time with default values for data members.
     */
    Time(int hour, int min) throw (logic_error);
    /*
     Pre: 0 <= hour <= 23 and 0 <= min <= 59.
     Post: Creates a time with the given hour and minute.
     */
    static int elapsedMin(Time t1, Time t2);
    /*
     Post: Returns the difference in minutes between t1 and t2. Assumes t2 is
     between 00:00 and 23:59 hours after t1.
     */
    string toString();
    /*
     Post: Returns a string containing the hour and minute (e.g., “13:01”).
     */
    inline void setTime(string s){myHours = std::stoi(s.substr(0,2));myMinutes = std::stoi(s.substr(3,2));};
private:
    int myHours, myMinutes;
    
};

#endif /* defined(__Pizza__Time__) */
