#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
#include "list.h"

template <typename T>
class Stack{
        private:
                List<T> alist;
        public:
                void push(T val){ alist.insert(val); };
                void pop(){ if(!empty()) alist.remove(); };
                bool empty(){ return alist.empty(); };
                T top(){ return alist.front(); };
                int size(){ return alist.size(); }
};
template <typename T>
class Stack<T*>{
        private:
                List<T> alist;
        public:
                void push(T val){ alist.insert(val); };
                void pop(){ if(!empty()) alist.remove(); };
                bool empty(){ return alist.empty(); };
                T top(){ return alist.front(); };
                int size(){ return alist.size(); };
};

#endif
