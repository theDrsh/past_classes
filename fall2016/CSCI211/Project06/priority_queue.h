/*
*   priority_queue.h
*   Daniel Rush
*   Project 5
*/
#include<iostream>
#include<string>
using namespace std;
#ifndef PRIORITYQUEUE_H 
#define PRIORITYQUEUE_H

#include "student.h"
#include "node.h"
#include "dlist.h"

template <typename T, typename K>
class PriorityQueue
{
        private:
                Dlist<T,K> queue;
                
        public:
                PriorityQueue(): queue() {}
                K peek_priority() {return queue.peek_priority();};
                T front() {return queue.front();};
                int size() {return queue.size();};
                bool empty() {return !queue.size();};
                bool pop() {return queue.remove();};
                void push(T st, K pr) {queue.insert_sorted(st, pr);};
                PriorityQueue operator=(const PriorityQueue<T,K> &rhs)
                {
                    if(!empty())
                        queue.clean();
                    queue.copy(rhs.queue);
                };
                PriorityQueue(const PriorityQueue<T,K> &rhs)
                {
                    if(!empty())
                        queue.clean();
                     queue.copy(rhs.queue); 
                 };
};
template <typename T, typename K>
class PriorityQueue<T*,K>
{
        private:
                Dlist<T*,K> queue;
        public:
                PriorityQueue(): queue() {}
                K peek_priority() {return queue.peek_priority();};
                T front() {return queue.front();};
                int size() {return queue.size();};
                bool empty() {return !queue.size();};
                bool pop() {return queue.remove();};
                void push(T st, K pr) {queue.insert_sorted(st, pr);};
                PriorityQueue& operator=(const PriorityQueue<T,K> &rhs)
                {
                    if(!empty())
                        queue.clean();
                    queue.copy(rhs.queue);  
                };
                PriorityQueue(const PriorityQueue<T*,K> &rhs)
                {
                    if(!empty())
                        queue.clean();
                    queue.copy(rhs.queue);
                };
};
#endif
