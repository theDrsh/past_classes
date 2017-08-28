#include<iostream>
#include<string>
using namespace std;

#include "list.h"

//destructor of the class
//this function is called when List object is destroyed
template <typename T>
List<T>::~List(){
        Node<T> *ptr = head;
        while(ptr != NULL){
                Node<T> *temp = ptr;
                ptr = ptr->next;
                delete temp;//deletes Node object

        }//while
}//destructor
template <typename T>
List<T*>::~List(){
        Node<T*> *ptr = head;
        while(ptr != NULL){
                Node<T*> *temp = ptr;
                ptr = ptr->next;
                delete temp->value;
                delete temp;//deletes Node object

        }//while
}//destructor

//inserts a Node object into a list
template <typename T>
void List<T>::insert(T st){
        Node<T> *ptr_to_node = new Node<T>(st, head);
        head = ptr_to_node;

        ptr_to_node = NULL;

        length++;
}//insert
template <typename T>
void List<T*>::insert(T st){
        Node<T*> *ptr_to_node = new Node<T*>( new T(st), head);
        head = ptr_to_node;

        ptr_to_node = NULL;

        length++;
}//insert

//removes the front of the list
template <typename T>
bool List<T>::remove(){
        if(length == 0)
                return false;
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        length--;
        return true;
}//remove()
template <typename T>
bool List<T*>::remove(){
        if(length == 0)
                return false;
        Node<T*> * temp = head;
        head = head->next;
        delete temp->value;
        delete temp;
        temp = NULL;
        length--;
        return true;
}//remove()

template <typename T>
void List<T>::print(){
        Node<T> *ptr = head;
        while(ptr != NULL){
                cout << ptr->value << endl;//returns Student object
                ptr = ptr->next;
        }//while
}//print
template <typename T>
void List<T*>::print(){
        Node<T*> *ptr = head;
        while(ptr != NULL){
                cout << *(ptr->value) << endl;//returns Student object
                ptr = ptr->next;
        }//while
}//print

/*Students will define the following functions:*/
template <typename T>
void List<T>::clean(){
        if(head == NULL)
                return;
        Node<T> *cur = head;
        while(cur != NULL){
                Node<T> *temp = cur;
                cur = cur->next;
                delete temp;
        }//while
        head = NULL;
}//clean

template <typename T>
void List<T*>::clean(){
        if(head == NULL)
                return;
        Node<T*> *cur = head;
        while(cur != NULL){
                Node<T*> *temp = cur;
                cur = cur->next;
                delete temp->value;
                delete temp;
        }//while
        head = NULL;
}//clean

template <typename T>
void List<T>::copy(const List<T> &rhs){
        if(head != NULL){
                this->clean();
        }
        length = rhs.length;
        Node<T> *cur = rhs.head;
        Node<T> *temp = head;
        Node<T> *prev = head;
        while(cur != NULL){
                temp = new Node<T>(cur->value, NULL);
                if(prev == NULL){
                        prev = temp;
                        head = temp;//the first node
                }
                else
                        prev->next = temp;
                prev = temp;
                cur = cur->next;
        }//while
}

template <typename T>
void List<T*>::copy(const List<T*> &rhs){
        if(head != NULL)
                this->clean();
        length = rhs.length;
        Node<T*> *cur = rhs.head;
        Node<T*> *temp = head;
        Node<T*> *prev = head;
        while(cur != NULL){
                T *item_ptr = new T(*(cur->value));
                temp = new Node<T*>(item_ptr, NULL);
                if(prev == NULL)
                        head = temp;//the first node
                else
                        prev->next = temp;
                prev = temp;
                cur = cur->next;
        }//while
}

template <typename T>
List<T>::List(const List<T> &rhs){
        this->copy(rhs);
}
template <typename T>
List<T>& List<T>::operator=(const List<T> &rhs){
        this->copy(rhs);
        return *this;
}
template <typename T>
List<T*>::List(const List<T*> &rhs){
        this->copy(rhs);
}
template <typename T>
List<T*>& List<T*>::operator=(const List<T*> &rhs){
        this->copy(rhs);
        return *this;
}
template <typename T>
bool List<T>::find_remove(T item){
        if(head == NULL)
                return false;
        if(head->value == item){
                Node<T> *temp = head;
                head = head->next;
                delete temp;
                return true;
        }
        Node<T> *cur = head;
        while(cur != NULL){
                if(cur->next != NULL && cur->next->value == item){
                        Node<T> *temp = cur->next;
                        cur->next = cur->next->next;
                        delete temp;
                        return true;
                }
                cur = cur->next;
        }
        return false;
}//find_remove
template <typename T>
bool List<T*>::find_remove(T item){
        if(head == NULL)
                return false;
        if(head->value == item){
                Node<T*> *temp = head;
                head = head->next;
                delete temp;
                return true;
        }
        Node<T*> *cur = head;
        while(cur != NULL){
                if(cur->next != NULL && *(cur->next->value) == item){
                        Node<T*> *temp = cur->next;
                        cur->next = cur->next->next;
                        delete temp;
                        return true;
                }
                cur = cur->next;
        }

        return false;
}

