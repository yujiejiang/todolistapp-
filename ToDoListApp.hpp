//
//  ToDoListApp.hpp
//  todolist
//
//  Created by YuJie Jiang on 4/14/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef ToDoListApp_hpp
#define ToDoListApp_hpp

#include <iostream>
#include<string>
#include<fstream>
#include <algorithm>
#include"shoppingtask.hpp"
#include"homeworktask.hpp"
#include"task.hpp"
#include"event.hpp"
#include"date.hpp"
#include "sortedlinkedlist.hpp"
#include "comparator.hpp"


// ToDoList Application Class - This class will handle the commands entered from the
// user. It is initialized with an input/output stream, which is by default cout/cin.

// Any functions implemented should make use of out/in instead of cout/cin directly.
class ToDoListApp {
public:
    void run();
    
    ToDoListApp(std::istream& in = std::cin,
                std::ostream& out = std::cout) :
    in(in), out(out) {}
protected:
    
    enum TaskType { SHOPPING = 'S', EVENT = 'E', HOMEWORK = 'H', GENERIC = 'G' };
    
    
    // You will implement all of the following functions
    void executeCommandPrint(bool completed = false, bool detailed = false);
    void executeCommandAddTask() ;
    void executeCommandRemoveTask();
    void executeCommandCompleteTask() ;
    void executeCommandSave();
    void executeCommandLoad();
    
private:
    // Remember: you may add additional member variables
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
    sortedlinkedlist<Task*, comparator> tasks;
    sortedlinkedlist<Task*, comparator> completed_tasks;
    
    
    
};



#endif /* ToDoListApp_hpp */
