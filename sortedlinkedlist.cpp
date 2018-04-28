//
//  sortedlinkedlist.cpp
//  todolist
//
//  Created by YuJie Jiang on 4/9/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//
#ifndef _sortedlinkedlist_cpp
#define _sortedlinkedlist_cpp
#include "sortedlinkedlist.hpp"


    namespace {
        enum positioncode{goodposition=0, negativeposition=-1, outofposition=-2};
    }

template<class itemtype,class comparator>
void sortedlinkedlist<itemtype,comparator>::insertPos(int pos, const itemtype &data){
    Node<itemtype>* previouse=new Node<itemtype>; //do not need a new node here
    Node<itemtype>* current=head;//here
    Node<itemtype>*temp=new Node<itemtype>; //and here
    for(int i=0;i<pos;++i){
        previouse=current;
        current=current->next;
    }
    temp->value=data;
    previouse->next=temp;
    temp->next=current;
    ++d_size;
}


template<class itemtype,class comparator>
itemtype sortedlinkedlist<itemtype, comparator>::getPos(int pos){
    Node<itemtype>* current=head;//we create a new node called current, and set it equal to head
    int i = 0;
    //d_size=0;//and the size of the list is equals to 0
    while(current !=nullptr){
        if(i==pos)
            return (current->value);//
        ++i;
      current=current->next;
    }
    return nullptr;
}



template<class itemtype,class comparator>
void sortedlinkedlist<itemtype,comparator>::deletePos(int pos){
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        --d_size;
        return;
    }
    Node<itemtype>* current=head;//we create a new node called current
    if (pos == 0) {
        head = current->next;
        head->prev = nullptr;
        delete current;
        --d_size;
        return;
    }
    Node<itemtype>* previous = current;//we create a new node called previous
    for(int i=0;i<pos;++i){ //go through the list
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    if (current->next == nullptr) {
        tail = previous;
    } else {
        current->next->prev = previous;
    }
    delete current;
    //current->next = nullptr;
    --d_size;
}



template<class itemtype,class comparator>//display function
void sortedlinkedlist<itemtype, comparator>::display(){
    Node<itemtype> *temp=head;
    for (int i=0; i<d_size;++i){
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}
          

template<class itemtype,class comparator>
void sortedlinkedlist<itemtype,comparator>::deletelist(){
    head=NULL;
    d_size=0;
}

//extented from the excutedmandprint, because for 4 tasks, we are printting defferent variables
template<class itemtype,class comparator>
void sortedlinkedlist<itemtype,comparator>::print() {
    for(int i = 0; i < d_size; i++) {
        getPos(i)->print();
        cout << endl;
        ++d_size;
    }
}


//insert function, since we are not using push_back function in the sortedlinkedlist, but we still need to insert things in order to the list

template<class itemtype,class comparator>
void sortedlinkedlist<itemtype, comparator>::insert(const itemtype& data){
    Node<itemtype>* node = new Node<itemtype>;
    //Node<itemtype>* current=head;
    node->value = data;
    node->prev = nullptr;
    node->next = nullptr;

    comparator c;

    // Case 1: There are no nodes yet
    if (head == nullptr) {
        head = node;
        tail = head;
        return;
    }
    
    
    // case 2 - inserting at the head of the list
    if (c(node->value , head->value))
    {
        node->next = head;
        head = node;
        return;
    }
    
    // case 3 - inserting at the end of the list
    if (c(tail->value, node->value))
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
        return;
    }
    
    // general case - inserting into the middle
    Node<itemtype>* probe = head;
    while (probe && (c(probe->value, node->value)))
    {
        probe = probe->next;
        
    }
    if (probe)
    {
        node->next = probe;
        node->prev = probe->prev;
        probe->prev = node;
        return;
    }
    
    // error - we shouldnt' reach this point. If we did, it meant the list was out of order to begin with.
    return;

    
    
    
}


template<class itemtype,class comparator> //output the variables from the list
void sortedlinkedlist<itemtype, comparator>::getlist() {
    Node<itemtype>* current = head->next();
    for(int i = 0; i < d_size; ++i) {
        cout << current->getdata() << std::endl;
        current = current->next();
    }

}

//extented from the excutecomandsave  //*
template<class itemtype, class comparator>
void sortedlinkedlist<itemtype,comparator>::executesave(){
    if(!empty()){
        std::string filename;
        std::ofstream out;
        std::cout<<"where would you like to save your outstanding task?";
        std::getline(std::cin,filename);
        out.open(filename);
      Node<itemtype>* current = head;
      for(int i = 0; i < d_size; ++i){
        out << current->value->gettype() << "|";
            current->value->getdate().printDDMMYYYY(out);
            out << "|" ;
            out<< current->value->getdescription();

            current->value->getdate().printDDMMYYYY(out);
              // out << "|";
            current->value->fileoutput(out);
         //  current = current->next();*/
            }
            out.close();
            std::cout << "Tasks saved successfully!\n";
        return;
    }
            std::cout << "File failed to load. Please try again.\n";
}



#endif
