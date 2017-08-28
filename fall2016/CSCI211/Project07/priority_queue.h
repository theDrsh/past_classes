#include<iostream>
using namespace std;
#include "dlist.h"
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template <typename T, typename K> 
class PriorityQueue{
        public:
                PriorityQueue(){};
                bool empty(){ return dlist.size() == 0; };
                int size(){ return dlist.size(); };
                T front(){ return dlist.front(); };
                K peek_priority(){ return dlist.peek_priority(); };
                void push(T st, K pr){ dlist.insert_sorted(st, pr); };
                bool pop(){ return dlist.remove(); };
                PriorityQueue& operator=( const PriorityQueue &rhs){
                        dlist = rhs.dlist;
                };
                PriorityQueue(const PriorityQueue &rhs){
                        dlist = rhs.dlist;
                }
        private:
                Dlist<T,K> dlist;

};

template <typename T, typename K>
class PriorityQueue<T*, K>{
        public:
                PriorityQueue& operator=( const PriorityQueue &rhs){
                        dlist = rhs.dlist;
                };
                PriorityQueue(const PriorityQueue &rhs){
                        dlist = rhs.dlist;
                }

                PriorityQueue(){};
                bool empty(){ return dlist.size() == 0; };
                int size(){ return dlist.size(); };
                T front(){ return dlist.front(); };
                K peek_priority(){ return dlist.peek_priority(); };
                void push(T st, K pr){ dlist.insert_sorted(st, pr); };
                bool pop(){ return dlist.remove(); };
        private:
                Dlist<T*,K> dlist;

};

#endif
