/*
*   @file: main.cpp
*   @author: Daniel Rush
*   @date 4/15/2017
*/
#include<iostream>
#include<string>
#include<vector>
#include "minpriority.h"
using std::string;
using std::vector;

int main()
{
    MinPriorityQ pq;
    string op = "";
    string id = "";
    int key;
    while(op != "q")
    {
        std::cin >> op;
        if(op == "q")
        {
            return 0;
        }
        else if(op == "x")
        {
            std::cout << pq.extractMin() << std::endl;
        }
        else
        {
            std::cin >> id >> key;
            if(op == "a")
            {
                pq.insert(id,key); 
            }
            else if(op == "d")
            {
                pq.decreaseKey(id,key);
            }
            else
            {
                std::cout << "invalid command" << std::endl;
                op = "";
                id = "";
                key = 0;
                return 1;
            }
        }
    }
    return 0;
}
