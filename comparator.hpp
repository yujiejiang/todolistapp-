//
//  comparator.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/19/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef comparator_hpp
#define comparator_hpp
#include <stdio.h>
#include "task.hpp"


class comparator{
    public:
        bool operator() (Task* a, Task* b);
};


#endif /* comparator_hpp */
