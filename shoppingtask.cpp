//
//  shoppingtask.cpp
//  todolist
//
//  Created by YuJie Jiang on 4/13/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//
//using vector for shooping task is because there might be many items in the shopping task, vector should holds better.

#ifndef shoppingtask_cpp
#define shoppingtask_cpp


#include "shoppingtask.hpp"
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
  
   /* void shoppingtask::outputdetail(std::ostream &out){
        out<<" items to purchase: ";
        for(int i=0;i<d_items.size();++i){
            out<<" "<<d_items[i]<<" ";
            
        }
    }
    

   void shoppingtask::fileoutput(std::ofstream& out){
        for(int i=0; i<d_items.size();++i){
            out << "|" << d_items[i];
        }
       out<<" ";
   }*/
        
  void shoppingtask::itemlist(std::ostream &out){
           for(int i = 0; i < d_items.size(); ++i){
           out << " " << d_items[i];
       }
    }


#endif


