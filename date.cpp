//
//  date.cpp
//  todolist
//
//  Created by YuJie Jiang on 4/11/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef date_cpp
#define date_cpp
#include "date.hpp"

/*std::ostream& Date::operator<<(std::ostream& out, const Date& date){
    out<<date.getday()<<'/'<<date.getmonth()<<'/'<<date.getyear();
    return out;
}*/

Date::Date(string date) {
    int month, day, year;
    stringstream ss(date);
    ss >> month;
    ss.ignore();
    ss >> day;
    ss.ignore();
    ss >> year;
    d_month = month;
    d_day=day;
    d_year=year;
    
}

//compare month, year and day
    bool Date::operator<(const Date& rhs){
        if(d_year<rhs.d_year){
            return true;
        }
        else if(d_year==rhs.d_year&&d_month<rhs.d_month){
            return true;
        }
        else if(d_year==rhs.d_year&&d_month==rhs.d_month&&d_day<rhs.d_day){
            return true;
        }
        else{
            return false;
        }
        };


    void Date::printDDMMYYYY(std::ostream& out){
        out<<d_day<<'/'<<d_month<<'/'<<d_year;
        
    }


#endif


