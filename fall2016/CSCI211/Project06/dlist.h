/*
*   dlist.h 
*   Daniel Rush
*   Project 5
*/
#include<iostream>
#include<string>
using namespace std;
#ifndef DLIST_H
#define DLIST_H

#include "student.h"
#include "node.h"

template <typename T, typename K>
class Dlist{
        private:
                Node<T,K> *head = NULL;
                Node<T,K> *tail = NULL;
                int length;
                Node<T,K> *find_less(K pr, Node<T,K>* cur);
                Node<T,K> *copy_recursive(Node<T,K>* rhs_cur, Node<T,K>* lhs_prev);
        public:
                Dlist(): head(NULL), length(0) {};
                ~Dlist();
                int size(){ return length; };
                //inserts a Node in front of the list
                void insert(T st, K pr);
                //prints all Students in the list 
                void print();
                void print_recursive(Node<T,K>* cur);                         
                void print_reverse();
                //removes the front of the list
                bool remove();
                /*Students will define the following functions:*/
                void copy(const Dlist &rhs);
                void clean();
                Dlist(const Dlist &rhs);
                Dlist& operator=(const Dlist &rhs);
                void insert_sorted(T st, K pr);
                void insert_back(T st, K pr);
                bool remove_back();
                T front(){ if(head != NULL)
                            return head->value;
                            else return T() ; };
                K peek_priority() {if(head!=NULL)
                                    {
                                        return head->priority;
                                    }
                                    return 0;
                                    };
};
template <typename T, typename K>
class Dlist<T*,K>{
        private:
                Node<T*,K> *head = NULL;
                Node<T*,K> *tail = NULL;
                int length;
                Node<T*,K> *find_less(K pr, Node<T*,K>* cur);
                Node<T*,K> *copy_recursive(Node<T*,K>* rhs_cur, Node<T*,K>* lhs_prev);
        public:
                Dlist(): head(NULL), length(0) {};
                ~Dlist();
                int size(){ return length; };
                //inserts a Node in front of the list
                void insert(T st, K pr);
                //prints all Students in the list 
                void print();
                void print_recursive(Node<T*,K> *cur);
                void print_reverse();
                //removes the front of the list
                bool remove();
                /*Students will define the following functions:*/
                void copy(const Dlist &rhs);
                void clean();
                Dlist(const Dlist &rhs);
                Dlist& operator=(const Dlist &rhs);
                void insert_sorted(T st, K pr);
                void insert_back(T st, K pr);
                bool remove_back();
                void print_greater(T st);
                T front(){ if(head != NULL) return *(head->value);
                else return T(); }
                K peek_priority() {if(head!=NULL)
                                    {
                                        return head->priority;
                                    }
                                    return 0;
                                    };
              
};

#endif
