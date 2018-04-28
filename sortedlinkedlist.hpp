//
//  sortedlinkedlist.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/9/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef sortedlinkedlist_hpp
#define sortedlinkedlist_hpp
#include <ostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "node.hpp"
//#include"task.hpp"

//#include"sortedlinkedlist.cpp"


using namespace std;

template<class itemtype,class comparator=less<itemtype>>
class sortedlinkedlist{

public:

    sortedlinkedlist() {
        head = nullptr;
        tail = nullptr;
        d_size = 0;
    }
    ~sortedlinkedlist(){
        deletelist();
    }
    
    //const sortedlinkedlist<itemtype>&operator=(const sortedlinkedlist<itemtype>& rhs);
    
    int size()const{return d_size;}
    
    bool empty()const{return d_size==0;}
    
    itemtype getPos(int pos);//output the specific position
    
    //int retrieve(int pos);//find if this is a valid position
    
    void insertPos(int pos, const itemtype&data);//insert a data into a specific pos
    
    void deletePos(int pos); //delete a position
    
    void display();
    
    void deletelist();
    
    void insert(const itemtype &data);
    
    void getlist();
    
    void print();
    
    void executesave();
    

private:
    int d_size;
    Node<itemtype>* head,* tail;
    void initializeSetinals();//helper function
    void increnmentsize(){++d_size;}
    itemtype data;

};

#include "sortedlinkedlist.cpp"

#endif /* sortedlinkedlist_hpp */
