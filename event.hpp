//
//  event.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/13/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef event_hpp
#define event_hpp

#include <stdio.h>
#include"date.hpp"
#include"task.hpp"
#include<ostream>
#include<fstream>


using namespace std;

    class eventtask : public Task{
    public:
        eventtask(Date date, std::string description, std::string location, std::string time, std::string type="E"):Task(date,description,type), d_location(location),d_time(time){}
        
        //getter and setter
        inline std::string getlocation()const{return d_location;}
        
        inline void setlocation(std::string location){d_location=location;}
        
        inline std::string gettime()const{return d_time;}
        
        inline void settime(std::string time){d_time=time;}
        
        //virtual eventtask& operator=(const eventtask&rhs);
        virtual inline bool operator==(eventtask& rhs){return getdescription()==rhs.getdescription()&&getdate()==rhs.getdate()&&d_location==rhs.d_location&&d_time==rhs.d_time;}
        
        virtual inline bool operator!=( eventtask&rhs){return getdescription()!=rhs.getdescription()||getdate()!=rhs.getdate()||d_location!=rhs.d_location||d_time!=rhs.d_time;}
        
        virtual void outputdetailed(std::ostream& out);
        
        virtual void fileoutput(std::ofstream& cout){cout<<"|"<<d_location<<"|"<<d_time<<endl;}
        
        virtual void print()
        {
            
            cout << d_type <<"|"<<d_location<<" "<<d_time<<" ";
            d_date.printDDMMYYYY(cout);
            
        }
        
        
        
    private:
        std::string d_location;
        std::string d_time;
    };

#endif /* event_hpp */
