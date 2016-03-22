//
//  Time.cpp
//  Pizza
//
//  Created by Zhirui on 12/2/15.
//  Copyright (c) 2015 Wooster. All rights reserved.
//
#include <string>
#include "Time.h"

Time::Time(){
    myHours = 0;
    myMinutes = 0;
}

Time::Time(int hour, int min) throw (logic_error){
    if(hour <0  || hour >23 || min < 0|| min >59) throw std::logic_error("error");
    else{
    myHours = hour;
    myMinutes = min;
    }
}

 int Time::elapsedMin(Time t1, Time t2){
     int difHour, difMin, elapseMin;
     difHour = t2.myHours - t1.myHours;
     difMin = t2.myMinutes - t1.myMinutes;
     elapseMin = difHour * 60 + difMin;
     return elapseMin;
}

string Time::toString(){
    string h = (myHours < 10)? "0" +std::to_string(myHours):std::to_string(myHours);
    string m = (myMinutes < 10)? "0" +std::to_string(myMinutes):std::to_string(myMinutes);
    
    return h + ":" + m;
}