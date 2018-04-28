//
//  ToDoListApp.cpp
//  todolist
//
//  Created by YuJie Jiang on 4/14/18.
//  Copyright © 2018 YuJie Jiang. All rights reserved.
//

#ifndef ToDoListApp_cpp
#define ToDoListApp_cpp

#include "ToDoListApp.hpp"


void ToDoListApp::run() {
    
    //NOTE: we are using out/in streams from the class level, not cin/cout
    //      directly. All your functions should do this.
    out << "Welcome to your To-Do List! You may begin to enter commands.";
    out << endl;
    
    string command;
    do {
        out << "> ";
        getline(in, command);
        
        //Convert entire command to uppercase for easy compares
        transform(command.begin(), command.end(), command.begin(), ::toupper);
        
        if (command == "PRINT") {
            executeCommandPrint();
        } else if (command == "DETAILED") {
            executeCommandPrint(false, true);
        } else if (command == "COMPLETED") {
            executeCommandPrint(true);
        } else if (command == "ADD") {
            executeCommandAddTask();
        } else if (command == "REMOVE") {
            executeCommandRemoveTask();
        } else if (command == "COMPLETE") {
            executeCommandCompleteTask();
        } else if (command == "SAVE") {
            executeCommandSave();
       } else if (command == "LOAD") {
            executeCommandLoad();
        } else if (command == "EXIT") {
            out << "Thank you for using To-Do List!\n";
           break;
        } else {
            out << "Unknown Command (" << command << "). Try Again.\n";
        }
        out << "\n";
   } while (true);
}


//print function to print out the list
void ToDoListApp::executeCommandPrint(bool completed, bool detailed) {
    if(!tasks.empty()) {
        tasks.print();
  //  out << "list " << endl;
    }
    else if(tasks.empty()){
        out<<"There is nothing in the list, please enter something to the list.";
    }
}


//addtask function to add the task to the list by order, we have 4tasks
void ToDoListApp::executeCommandAddTask(){
    string d, description,course,type,location,time;
    Date date;
    Task* task;
    std::cout<<"what type of task is this? [G:Generic,S:shopping,E:event,H:homework]";
       std::getline(cin, type);
    while (type!="G"&&type!="S"&&type!="E"&&type!="H"){
        std::cout<<"that was not a wavid respinse, please enter onf of the following choices: "<<std::endl;
        std::cout<<"[G:generic, S:shopping, E:event, H:homework ]";
        std::getline(std::cin,type);
    }

    
    if(type=="G"){
        std::cout<<"when is task due? ";
        std::getline(std::cin, d);
        date = Date(d);
        std::cout<<"How would you like to describe this task? ";
        std::getline(std::cin, description);
        task=new Task(date,description);
        //std::cout<<"task added successfully.";
    }
    else if (type == "H") {
        std::string course;
        std::cout<<"what subject is this homework task for ";
        std::getline(std::cin, course);
        std::cout<<"when is this homework due? ";
        std::getline(std::cin, d);
        date = Date(d);
        std::cout<<"how would you describe the homework? ";
        std::getline(std::cin, description);
        task = new Homeworktask(date, description, course);
        //tasks.comparator(homework,comparator())
    }
    else if(type=="E"){
        std::string location, time;
        std::cout<<"when is this event takes place? ";
        std::getline(std::cin, d);
        date = Date(d);
        std::cout<<"where is this event located? ";
        std::getline(std::cin, location);
        std::cout<<"how would you describe the event? ";
        std::getline(std::cin, description);
        std::cout<<"what time?";
        std::getline(std::cin, time);
        task = new eventtask(date, description, location,time);
    }
    else if(type=="S"){
        std::vector<std::string>itemlist;
        std::cout<<"when do you want to go shopping? ";
        std::getline(std::cin, d);
        date = Date(d);
        std::string input;
        std::cout<<"what items do you need to buy?";
        std::cout<<"[type your item and press enter to add anpother item. type done to complete the list ]";
        while(input!="done"){
        std::getline(std::cin,input);
            if(input=="done"){
                std::cout<<"added successfully.";
                task = new shoppingtask(date, description,itemlist);
            } else {
                itemlist.push_back(input);
            }
        }
        task = new shoppingtask(date, description, itemlist);
    }
   else
    {
        cout << "not supposed to get here ERROR [adding task in exec command]" << endl;
    }
    tasks.insert(task);
    std::cout<<"task added successfully.";
}


//removetask function to remove the tasks
void ToDoListApp::executeCommandRemoveTask(){
    if(!tasks.empty()){
        std::string stringPos;
        int pos;
        std::cout<<"what task would you like to remove?"<<endl;
        std::getline(std::cin, stringPos);
        pos = stoi(stringPos);
        
        while(pos < 0 || pos > tasks.size()-1) {                   //Check for valid input
            std::cout << "That was not a valid number. Please try again.\n";
            std::cout << "Which task would you like to remove?\n";
            std::getline(std::cin, stringPos);
            pos = atoi(stringPos.c_str());                      //convert string input to int value
        }
       tasks.deletePos(pos);                                     //Remove task
        std::cout << "Task removed successfully.\n";
    }
    else if(tasks.empty()){
        cout<<"there is nothing to remove."<<endl;
    }
}

//completetask function
void ToDoListApp::executeCommandCompleteTask(){
         if(!tasks.empty()){
            int pos;
            std::string stringPos;
            std::cout<<"which task would ytou like to complete? please enter the position."<<endl;
            std::getline(std::cin, stringPos);
            pos=atoi(stringPos.c_str());
        
            while(pos < 0||pos > tasks.size()){
                std::cout<<"not a valid number, retry.";
                std::cout<<"which task would you like to complete?";
                std::getline(std::cin,stringPos);
                pos=atoi(stringPos.c_str());
            }
            completed_tasks.insert(tasks.getPos(pos-1));
            tasks.deletePos(pos-1);
            std::cout<<"task complete successfully"<<endl;
         }
    else
    {
        cout << "there are no tasks to execute" << endl;
    }
}
    
void ToDoListApp::executeCommandSave(){
    tasks.executesave();
  // completed_tasks.executesave();

}

//load function
void ToDoListApp::executeCommandLoad(){
    Date date;
    std::string filename, tasktype, line, description, datestring;
    char delimiter='|';
    std::ifstream file;
    
    std::cout<<"what file woule you like to load outstanding task from?"<<endl;
    getline(std::cin,filename);
    file.open(filename.c_str());
    
    if (!file.bad()){
        tasks.deletelist();
        while(!file.eof()){
            getline(file, tasktype,delimiter);
            getline(file,datestring,delimiter);
           // date=getdateinput(datestring);
            if(tasktype=="G"){
                getline(file,description);
                Task* newtask=new Task(date,description);
                tasks.insert(newtask);
            }
            else{
                getline(file, description,delimiter);
                if(tasktype=="S"){
                    std::vector<std::string>shoppinglist;
                    
                    getline(file,line);
                    std::string item;
                    std::string::size_type begin=0;
                    std::string::size_type found=line.find_first_of(delimiter);
                    while(found!=std::string::npos){
                        item=line.substr(begin,(found-begin));
                        shoppinglist.push_back(item);
                        begin=found+1;
                        found=line.find_first_of(delimiter,begin);
                    }
                    item=line.substr(begin,(found-begin));
                    shoppinglist.push_back(item);
                    shoppingtask* shopping=new shoppingtask(date,description, shoppinglist);
                    tasks.insert(shopping);
                }
                if(tasktype=="E"){
                    std::string location,time;
                    getline(file,location,delimiter);
                    getline(file,time);
                   eventtask* event=new eventtask(date, description,location, time);
                    tasks.insert(event);
                }
                if(tasktype=="H"){
                    std::string course;
                    getline(file, course,delimiter);
                    Homeworktask* homeworktask=new Homeworktask(date, description, course);
                    tasks.insert(homeworktask);
                }
            }
        }
        file.close();
        std::cout<<"tasks loaded successfully."<<endl;
    }
    else {
        std::cout<<"failed to load,try again."<<endl;
    }
    
}






#endif




