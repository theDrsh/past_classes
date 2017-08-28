#include<iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
        public:
                Node():  value(T()), next(NULL) {};
                Node(T st, Node* ptr): value(st), next(ptr) {};
                T value;
                Node* next;
};
//partial specialization
template <typename T>
class Node<T*>{
        public:
                Node():  value(T()), next(NULL) {};
                Node(T* st, Node* ptr): value(st), next(ptr) {};
                T* value;
                Node* next;
};

#endif
