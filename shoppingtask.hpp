//
//  shoppingtask.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/13/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef shoppingtask_hpp
#define shoppingtask_hpp

#include<stdio.h>
#include"date.hpp"
#include"task.hpp"
#include<ostream>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

    class shoppingtask:public Task{
    private:
        std::vector<std::string> d_items;
    public:
        shoppingtask(Date date,std::string description, std::vector<std::string>items, std::string type = "S"):Task (date,description, "S"),d_items(items){}
        
        inline std::vector<std::string> getitems()const{return d_items;}
        
        //virtual shoppingtask& operator=(const shoppingtask& rhs);
        
        void setitems(std::vector<std::string>items){d_items=items;}
        
        bool operator==(const shoppingtask&rhs){return getdescription()==rhs.getdescription() && getdate() == rhs.getdate() && d_items == rhs.d_items; }
        
        bool operator !=(const shoppingtask& rhs){return getdescription() != rhs.getdescription() || getdate() != rhs.getdate() || d_items!= rhs.d_items; }
        
       // virtual void outputdetail(std::ostream&out);
        
       // virtual void fileoutput(std::ofstream&out);
        
        virtual void itemlist(std::ostream&out);
        

        
       virtual void print()
    {
        cout << d_type;
        cout<< d_description;
        for(int i = 0; i < d_items.size(); ++i){
            cout <<d_items[i]<< " "<<endl;
        }
        d_date.printDDMMYYYY(cout);
        }
    };

#endif /* shoppingtask_hpp */
