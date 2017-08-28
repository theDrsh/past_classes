#include<iostream>
#include<string>
using namespace std;
#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename T>
class List{
        private:
                Node<T> *head = NULL;
                int length;
        public:
                List(): head(NULL), length(0) {};
                ~List();
                int size(){ return length; };
                //inserts a Node in front of the list
                void insert(T st);
                //prints all Students in the list 
                void print();
                //removes the front of the list
                bool remove();
                /*Students will define the following functions:*/
                void copy(const List &rhs);
                void clean();
                List(const List &rhs);
                List& operator=(const List &rhs);
                bool find_remove(T item);
                bool empty(){return (length == 0); };
                T front(){ return head->value; };
};
template <typename T>
class List<T*>{
        private:
                Node<T*> *head = NULL;
                int length;
        public:
                List(): head(NULL), length(0) {};
                ~List();
                int size(){ return length; };
                //inserts a Node in front of the list
                void insert(T st);
                //prints all Students in the list 
                void print();
                //removes the front of the list
                bool remove();
                /*Students will define the following functions:*/
                void copy(const List &rhs);
                void clean();
                List(const List &rhs);
                List& operator=(const List &rhs);
                bool find_remove(T item);
                bool empty(){return (length == 0); };
                T front(){ return *(head->value); };                                
};

#endif
