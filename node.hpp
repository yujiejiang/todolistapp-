//
//  node.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/9/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef node_hpp
#define node_hpp
#include <stdio.h>
//#include"node.cpp"
#include<cstddef>


using namespace std;

template<class itemtype>

    struct Node{
    public:
        Node* current;
        Node* prev;
        Node* next;
      itemtype value;
    };

#include "node.cpp"
#endif /* node_hpp */
//date you can use struct as well

