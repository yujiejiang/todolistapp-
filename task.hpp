//
//  task.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/11/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef task_hpp
#define task_hpp
#include<ostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include"date.hpp"

using namespace std;

class Task{
    
public:
    
    Task (Date date, std::string description, std::string type="G" ):d_date(date),d_description(description),d_type(type){}
    ~Task(){};
    
    //getter and setter
    inline std::string getdescription()const {return d_description;}
    
    inline Date getdate()const {return d_date;}
    
    inline  std::string gettype()const{return d_type;}
    
    inline void setdescription (std::string description){d_description=description;}
    
    inline void settype(std::string type){d_type=type;}
    
    inline void setdate(int month, int day, int year){d_date.setmonth(month);d_date.setday(day);d_date.setyear(year);}
    
    inline void setdate(Date date){d_date=date;}
    
    virtual Task& operator=(const Task& rhs);
    
    virtual inline bool operator ==(const Task& rhs){return getdescription()==rhs.getdescription()&&getdate()==rhs.getdate();}
    
    virtual inline  bool operator!=(const Task&rhs){return getdescription()!=rhs.getdescription() || getdate() != rhs.getdate(); }
    
    virtual void outputdetail(std::ostream& out){}//output task data
    
       virtual void fileoutput(std::ofstream& cout){ cout << "\n"; }
    
virtual void print()
    {
        cout << d_type<<"|"<<d_description<<" ";
        d_date.printDDMMYYYY(cout);
    }


    
protected:
    Date d_date;
    std::string d_description;
    std::string d_type;
    //bool completed{false}; //to check if the task is completed or not.
};

#endif /* task_hpp */
