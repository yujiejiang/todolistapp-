//
//  task.cpp
//  todolist
//
//  Created by YuJie Jiang on 4/11/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef task_cpp
#define task_cpp

//using Inheritance from generic task to the homework, shopping and event task.

#include "task.hpp"

    
    Task& Task::operator=(const Task &rhs){
        d_description=rhs.d_description;
        d_date=rhs.d_date;
        return *this;
    }


#endif
