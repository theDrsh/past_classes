#include<iostream>
#include<string>
using namespace std;

#include "dlist.h"

//destructor of the class
//this function is called when Dlist object is destroyed
template <typename T, typename K>
Dlist<T,K>::~Dlist(){
        Node<T,K> *ptr = head;
        while(ptr != NULL){
                Node<T,K> *temp = ptr;
                ptr = ptr->next;
                delete temp;//deletes Node object

        }//while
}//destructor
template <typename T, typename K>
Dlist<T*,K>::~Dlist(){
        Node<T*,K> *ptr = head;
        while(ptr != NULL){
                Node<T*,K> *temp = ptr;
                ptr = ptr->next;
                delete temp->value;
                delete temp;//deletes Node object

        }//while
}//destructor

//inserts a Node object into a list
template <typename T, typename K>
void Dlist<T,K>::insert(T st, K pr){

        Node<T,K> *ptr_to_node = new Node<T,K>(st, NULL, head, pr);
        if(head == NULL)
                tail = ptr_to_node;
        else
                head->prev = ptr_to_node;
        head = ptr_to_node;

        ptr_to_node = NULL;

        length++;
}//insert
template <typename T, typename K>
void Dlist<T*,K>::insert(T st, K pr){
        Node<T*,K> *ptr_to_node = new Node<T*,K>( new T(st), NULL,  head, pr);
        if(head == NULL)
                tail = ptr_to_node;
        else 
                head->prev = ptr_to_node;
        head = ptr_to_node;

        ptr_to_node = NULL;

        length++;
}//insert

//removes the front of the list
template <typename T, typename K>
bool Dlist<T,K>::remove(){
        if(length == 0)
                return false;
        Node<T,K> * temp = head;
        if(head->next != NULL){
                head->next->prev = NULL;
        }
        head = head->next;
        if(head == NULL)
                tail = NULL;
        delete temp;
        temp = NULL;
        length--;
        return true;
}//remove()
template <typename T, typename K>
bool Dlist<T*,K>::remove(){
        if(length == 0)
                return false;
        if(head->next != NULL)
                head->next->prev = NULL;
        Node<T*,K> * temp = head;
        head = head->next;
        if(head == NULL)
                tail = NULL;
        delete temp->value;
        delete temp;
        temp = NULL;
        length--;
        return true;
}//remove()
template <typename T, typename K>
void Dlist<T,K>::print_reverse(){
    Node<T,K> *ptr = tail;
    while(ptr != NULL){
        cout << ptr->value << endl;
        ptr = ptr->prev;
    }
}
template< typename T, typename K>
void Dlist<T*,K>::print_reverse(){
    Node<T*,K> *ptr = tail;
    while(ptr != NULL){
        cout << *(ptr->value) << endl;
        ptr = ptr->prev;
    }
}
template <typename T, typename K>
void Dlist<T,K>::print(){
        Node<T,K> *ptr = head;
        print_recursive(ptr);
}//print
template<typename T, typename K> 
void Dlist<T,K>::print_recursive(Node<T,K> *cur){
        if(cur == NULL)
                return;
        cout << cur->value << endl;
        print_recursive(cur->next);
}
template <typename T, typename K>
void Dlist<T*,K>::print(){
        Node<T*,K> *ptr = head;
        print_recursive(ptr);
}//print
template <typename T, typename K>
void Dlist<T*,K>::print_recursive(Node<T*,K> *cur){
        if(cur == NULL)
                return;
        cout << *(cur->value) << endl;
        print_recursive(cur->next);
}
//copy-constructor
template <typename T, typename K>
Dlist<T,K>::Dlist(const Dlist<T,K> &rhs){
        this->copy(rhs);
}
//overloaded operator=
template <typename T, typename K>
Dlist<T,K>& Dlist<T,K>::operator=(const Dlist<T,K> &rhs){
        this->copy(rhs);
        return *this;
}
template <typename T, typename K>
Dlist<T*,K>::Dlist(const Dlist<T*,K> &rhs){
        this->copy(rhs);
}
template <typename T, typename K>
Dlist<T*,K>& Dlist<T*,K>::operator=(const Dlist<T*,K> &rhs){
        this->copy(rhs);
        return *this;
}
//insert_back and remove_back:

template <typename T, typename K>
void Dlist<T,K>::insert_back(T st, K pr)
{
        if (length == 0)
        {
                insert(st, pr);
                return;
        }
        tail->next = new Node<T,K>(st, tail, NULL, pr);
        tail = tail->next;
        length++; 
}

template <typename T, typename K>
void Dlist<T*,K>::insert_back(T st, K pr)
{
        if (length == 0)
        {
                insert(st, pr);
                return;
        }
        tail->next = new Node<T*,K>(new T(st), tail, NULL, pr);
        tail = tail->next;
        length++; 
}

template <typename T, typename K>
bool Dlist<T,K>::remove_back()
{
        if (length < 2)
        {
                return remove();
        }
        Node<T,K> *toRemove = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete toRemove;
        length--;
        return true;
}

template <typename T, typename K>
bool Dlist<T*,K>::remove_back()
{
        if (length < 2)
        {
                return remove();
        }
        Node<T*,K> *toRemove = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete toRemove;
        length--;
        return true;
}

template <typename T, typename K>
void Dlist<T,K>::insert_sorted(T st, K pr)
{
        if (length == 0)
        {
                insert(st, pr);
                return;
        }
        
        Node<T,K> *less = find_less(pr, head);
        if (less == NULL)
        {
                insert_back(st, pr);
        }
        else if (less == head)
        {
                insert(st, pr);
        }
        else
        {
                // BEFORE
                // | PREVIOUS | - > | LESS |
                // |          | < - |      |

                // AFTER
                // | PREVIOUS | - > | NEW | - > | LESS |
                // |          | < - |     | < - |      |

                Node<T,K>* previous = less->prev;
                previous->next = new Node<T,K>(st, previous, less, pr);
                less->prev = previous->next;
                length++;
        }//else
}

template <typename T, typename K>
void Dlist<T*,K>::insert_sorted(T st, K pr)
{
        if (length == 0)
        {
                insert(st, pr);
                return;
        }
        
        Node<T*,K> *less = find_less(pr, head);
        if (less == NULL)
        {
                insert_back(st, pr);
        }
        else if (less == head)
        {
                insert(st, pr);
        }
        else
        {
                // BEFORE
                // | PREVIOUS | - > | LESS |
                // |          | < - |      |

                // AFTER
                // | PREVIOUS | - > | NEW | - > | LESS |
                // |          | < - |     | < - |      |

                Node<T*,K>* previous = less->prev;
//debug

                previous->next = new Node<T*,K>(new T(st), previous, less, pr);
                less->prev = previous->next;
                length++;
    }
}

template <typename T, typename K>
Node<T,K>* Dlist<T,K>::find_less(K st, Node<T,K>* cur)
{
        if (cur == NULL || st < cur->priority)
                return cur;
        else
                return find_less(st, cur->next);
}

template <typename T, typename K>
Node<T*,K>* Dlist<T*,K>::find_less(K st, Node<T*,K>* cur)
{
        if (cur == NULL || st < (cur->priority))
                return cur;
        else
                return find_less(st, cur->next);
}

template <typename T, typename K>
void Dlist<T,K>::clean()
{
        Node<T,K> *ptr = head;
        while(ptr != NULL){
                Node<T,K> *temp = ptr;
                ptr = ptr->next;
                delete temp;//deletes Node object

        }//while

        head = NULL;
        tail = NULL;
        length = 0;
}

template <typename T, typename K>
void Dlist<T*,K>::clean()
{
        Node<T*,K> *ptr = head;
        while(ptr != NULL){
                Node<T*,K> *temp = ptr;
                ptr = ptr->next;
                delete temp->value;
                delete temp;//deletes Node object

        }//while

        head = NULL;
        tail = NULL;
        length = 0;
}

template <typename T, typename K>
void Dlist<T,K>::copy(const Dlist<T,K> &rhs)
{
        if (length != 0)
                clean();
        
        head = copy_recursive(rhs.head, NULL);
}

template <typename T, typename K>
void Dlist<T*,K>::copy(const Dlist<T*, K> &rhs)
{
        if (length != 0)
                clean();

        head = copy_recursive(rhs.head, NULL);
}

template <typename T, typename K>
Node<T,K>* Dlist<T,K>::copy_recursive(Node<T,K>* rhs_cur, Node<T,K>* lhs_prev)
{
        if (rhs_cur == NULL)
        {
                tail = lhs_prev;
                return NULL;
        }
        Node<T,K>* cur = new Node<T,K>(rhs_cur->value, lhs_prev, NULL, rhs_cur->priority);
        cur->next = copy_recursive(rhs_cur->next, cur);
        return cur;
}

template <typename T, typename K>
Node<T*,K>* Dlist<T*,K>::copy_recursive(Node<T*,K>* rhs_cur, Node<T*,K>* lhs_prev)
{
        if (rhs_cur == NULL)
        {
                tail = lhs_prev;
                return NULL;
        }
        Node<T*,K>* cur = new Node<T*,K>(new T(*(rhs_cur->value)), lhs_prev, NULL, rhs_cur->priority);
        cur->next = copy_recursive(rhs_cur->next, cur);
        return cur;
}
