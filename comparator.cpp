//
//  comparator.cpp
//  todolist
//
//  Created by YuJie Jiang on 4/19/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

//comparator class, we are compararing the date with two tasks
#ifndef comparator_cpp
#define comparator_cpp
#include "comparator.hpp"
bool comparator::operator()(Task* a, Task* b){
    return a->getdate() < b->getdate();
}
#endif
