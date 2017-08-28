/*
*   node.h
*   Daniel Rush
*   Project 5
*/
#include<iostream>
using namespace std;
#include "student.h"

#ifndef NODE_H
#define NODE_H

template <typename T, typename K>
class Node{
        public:
                Node():  value(T()), prev(NULL), next(NULL), priority(K()) {};
                Node(T st, Node* pr, Node* n,  K prior): value(st), prev(pr), next(n), priority(prior) {};
                T value;
                Node* prev;
                Node* next;
                K priority;
};
//partial specialization
template <typename T, typename K>
class Node<T*,K>{
        public:
                Node():  value(T()), prev(NULL), next(NULL),  priority(K()) {};
                Node(T* st, Node* pr, Node* n,  K prior): value(st), prev(pr), next(n),  priority(prior) {};
                T* value;
                Node* prev;
                Node* next;
                K priority;
};

#endif
