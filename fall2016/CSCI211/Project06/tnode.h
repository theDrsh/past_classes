#include<iostream>
using namespace std;

#ifndef TNODE_H
#define TNODE_H

template <typename T>
class Tnode{
        public:
                Tnode():  value(T()), left(NULL), right(NULL) {};
                Tnode(T st): value(st), left(NULL), right(NULL) {};
                T value;
                Tnode* left;
                Tnode* right;
};
//partial specialization
template <typename T>
class Tnode<T*>{
        public:
                Tnode():  value(T()), left(NULL), right(NULL) {};
                Tnode(T* st): value(st), left(NULL), right(NULL) {};
                T* value;
                Tnode* left;
                Tnode* right;
};

#endif
