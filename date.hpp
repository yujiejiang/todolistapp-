//
//  date.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/11/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

#include <stdio.h>
#include<iostream>
#include <sstream>
#include <string>
#include<ostream>
#include<iomanip>

using namespace std; 

    class Date{
        
    private:
        int d_month;int d_day;int d_year;
        
    public:
        Date(int year=0,int month=0,int day=0):d_month(month),d_day(day),d_year(year){}
        Date(std::string date);
        
        //getter and setter
        int getday()const{return d_day;}
        int getmonth()const{return d_month;}
        int getyear()const{return d_year;}
        void setmonth(int month){d_month=month;}
        void setyear(int year){d_year=year;}
        void setday(int day){d_day=day;}
        
        Date& operator=(const Date&rhs){
            (*this).d_year = rhs.d_year;
            (*this).d_month = rhs.d_month;
            (*this).d_day = rhs.d_day;
            return *this;
        }
        
        bool operator==(const Date&rhs){return rhs.d_month== d_month && rhs.d_day == d_day && rhs.d_year == d_year; }
        bool operator!=(const Date&rhs){return rhs.d_month != d_month || rhs.d_day != d_day || rhs.d_year != d_year;}
        bool operator<(const Date&rhs);
        
    
        
        void printDDMMYYYY(std::ostream& out);//give ouput of MMDDYYYY format
        
    };



#endif /* date_hpp */
