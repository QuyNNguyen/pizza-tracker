//
//  main.cpp
//  Pizza
//
//  Created by Lab User on 12/2/15.
//  Copyright (c) 2015 Wooster. All rights reserved.
//

#include <iostream>
#include "Time.h"
#include "Driver.h"
#include "Restaurant.h"
#include "Order.h"
#include <string>
int main(int argc, const char * argv[]) {
 
   Restaurant r;

    Driver eifu;
    Driver quy;
    Driver zz;
    list<Driver> tempList{eifu, quy, zz};
    string tempName;

    int numDrivers;
    
    std::list<Driver>::iterator it= tempList.begin();
    
    cout <<"how many drivers(1-3) work for the restaurant?"<<endl;
    cin >> numDrivers;
    cout << "Enter their name with a space in between (Bev Kjr Olp)" <<endl;
    for (int i =0; i < numDrivers; i++) {
        cin >> tempName;
        (*it).changeName(tempName);
        r.addDriver(&(*it));
        it ++;
    }
    
    
    string s1,s2,s3,s4;
    string whitespace;
    Driver* temp;
    while(1){
        cout<< "input "<<endl;
        cin >> s1;
        if (s1.compare("login") == 0){
            cin >> s1;
            temp = r.getDriver(s1);
            temp->login();
        }
        else if(s1.compare("logout") == 0){
            cin >> s1;
            temp = r.getDriver(s1);
            temp->logout();
        }
        else if(s1.compare("order")== 0){
            cin >> s2;
            if(cin.peek() == ' ') getline(cin, whitespace); // Make sure user don't input redundant white space
            getline(cin, s3);
            Time t1;
            t1.setTime(s2);
            Order o(t1,s3);
            r.addOrder(&o);
        }
        else if(s1.compare("serve")==0){
            cin >> s2;
            Time t1;
            t1.setTime(s2);
            r.serveNextOrder();
            
        }else if(s1.compare("depart")==0){
            cin >> s2;
            Time t2;
            t2.setTime(s2);
            cin >> s3;
            Order* tempOrder = r.departNextOrder();
            Driver* tempDriver = r.getDriver(s3);
            tempDriver->depart(t2, *(tempOrder));
            
            
        }
        else if(s1.compare("deliver")==0){
            cin >> s2;
            Time t3;
            t3.setTime(s2);
            cin >> s3;
            Driver *d1 = r.getDriver(s3);
            cin >> s4;
            r.deliver(d1, t3, std::stof(s4));
        }
        else if(s1.compare("arrive")==0){
            cin >> s2;
            Time t4;
            t4.setTime(s2);
            cin >> s3;
            Driver *d1 = r.getDriver(s3);
            d1->arrive(t4);
        }
        else if(s1.compare("status")==0){
             r.status();
        }
        else if(s1.compare("summary")==0){
            r.summary();
        }
        else if(s1.compare("exit")==0){
            return EXIT_SUCCESS;
        }
        
        else cout << " INVALID COMMAND. PLEASE CHECK BACK THE COMMAND LIST ABOVE";
        
        
    }
    
    


}


