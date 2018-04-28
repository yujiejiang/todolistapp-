//
//  event.cpp
//  todolist
//
//  Created by YuJie Jiang on 4/13/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//
#include "event.hpp"
#include<ostream>
#include<string>
using namespace std;

void eventtask::outputdetailed(std::ostream &out){
    out<<"where: "<<d_location<<" "<<"when: "<<d_time;
}

