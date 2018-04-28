
//
//  homeworktask.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/12/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef homeworktask_hpp
#define homeworktask_hpp
#include <stdio.h>
#include"date.hpp"
#include"task.hpp"
#include<ostream>
#include<fstream>

using namespace std;
    
    class Homeworktask:public Task{
        
    private:
        std::string d_course;
        
    public:
        Homeworktask(Date date, std::string description, std::string course, std::string type="H"):Task(date, description, type),d_course(course){}
        
        //inherit all base class frm task, getter and setter
        inline std::string getcourse()const{return d_course;}
        
        inline void setcourse(std::string course){d_course=course;}
        
        bool operator ==(const Homeworktask&rhs){return getdescription() == rhs.getdescription() && getdate() == rhs.getdate() && d_course == rhs.d_course; }
        
        bool operator !=(const Homeworktask&rhs){return getdescription()!= rhs.getdescription()||getdate() !=rhs.getdate()||d_course!=rhs.d_course;}
        
        void outputdetailed(std::ostream &out);
        
        void fileoutput(std::ofstream& out){ out << "|" << d_course<< " "; }
        
        virtual void print()
        {
          
            cout << d_type <<"|"<<d_course;
            cout<<d_description; 
              d_date.printDDMMYYYY(cout);
    
           
        }
        
    

    };


#endif /* homeworktask_hpp */
