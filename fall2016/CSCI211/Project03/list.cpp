/*
 *           List.cpp
 *           Project03
 *           Daniel Rush
 */
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

//copy-constructor
template <typename T>
List<T>::List(const List<T> &rhs){
        this->copy(rhs);
}
//overloaded operator=
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
//-----------------------New Functions------------------------------//
/*
 *   copy
 *   - This function performs a deep copy from a host list to a destination list
 *     creating a new list in the heap with identical objects.
 *
 *   @param
 *   - A host list is passed into the function to be copied from.
 *
 *   @return
 *   - void
 */
        template <typename T>
void List<T>::copy(const List &rhs)
{
        Node<T> *host = rhs.head;       //create a pointer to scan the values of the host list
        Node<T> *dest = head;           //create a pointer to handle insertion of destination list
        if(host == NULL)
        {
                return;                 //If host list is empty, return as there is nothing to copy
        }
        if(dest != NULL)
        {
                clean();                //If dest list is empty, call clean function to empty the list then continue        
        }
        head = new Node<T>((rhs.head->value), NULL);    //create the first element of the destination list
        dest = head;
        host = host->next;
        length++;
        while(host != NULL)
        {
                dest->next = new Node<T> (host->value,NULL);    //while there are elements in the host list, copy to dest.
                host = host->next;
                dest = dest->next;
                length++;
        }
}
/*
 *   copy(Partial Specialization)
 */
        template <typename T>
void List<T*>::copy(const List &rhs)
{   
        T *ptr_to_value;                //Create a pointer to the object held by list to match format of partial specialization
        Node<T*> *host = rhs.head;
        Node<T*> *dest = head;
        if(host == NULL)
        {
                return;
        }
        if(dest != NULL)
        {
                clean();
        }
        ptr_to_value = new T(*(host->value));       //create new object to be placed in dest
        head = new Node<T*> (ptr_to_value, NULL);   //create first element of list
        dest = head;
        host = host->next;
        length++;
        while(host != NULL)
        {
                ptr_to_value = new T(*(host->value));
                dest->next = new Node<T*> (ptr_to_value,NULL);
                host = host->next;
                dest = dest->next;
                length++;
        }
}
/*
 *   clean
 *   - deletes contents of a list
 *   
 *   @param
 *   void
 *   
 *   @return
 *   void
 */
        template <typename T>
void List<T>::clean()
{   //same code as destructor of class
        Node<T> *ptr = head;
        while(ptr != NULL)
        {
                Node<T> *temp = ptr;
                ptr = ptr->next;
                delete temp;
        }
        head = NULL;                //resets head and length to allow list to be used again
        length = 0;
}
/*
 *   clean(Partial Specialization)
 */
        template <typename T>
void List<T*>::clean()
{
        Node<T*> *ptr = head;
        while(ptr != NULL)
        {
                Node<T*> *temp = ptr;
                ptr = ptr->next;
                delete temp->value; //deletes object pointed to by value
                delete temp;
        }
        head = NULL;
        length = 0;
}
/*
 *   find_remove
 *   - Finds item passed in by caller, removes that item and maintains list structure
 *
 *   @param
 *   - An item of type T is passed in to be found in the list
 *
 *   @return
 *   - bool value to signify to caller if item was found or not.
 */
        template <typename T>
bool List<T>::find_remove(T item)
{
        Node<T> *cur = head;
        if(head == NULL)                                    //if list is empty return false
        {
                return false;
        }
        if(item == head->value)                             //if the item is the same as first item in list use existing function
        {
                remove();
                return true;
        }
        while(cur->next != NULL)
        {
                if(cur->next->value == item)                //scan list to find the matching item
                {
                        Node<T> *temp = cur->next->next;    //hold address temporarily
                        delete cur->next;                   //delete matching item
                        cur->next = temp;                   //fix list struture
                        length--;
                        return true;
                }
                cur=cur->next;
        }
        if(cur->value == item)                              //if last element of list is item use existing function
        {
                remove_back();
                return true;
        }
        return false;                                       //if no match is found return false;

}
/*
 *   find_remove(Partial Specialization)
 */
        template <typename T>
bool List<T*>::find_remove(T item)
{
        Node<T*> *cur = head;
        if(head == NULL)
        {
                return false;
        }
        if(item == *(head->value))                          //dereference to check the object pointed to by value
        {
                remove();
                return true;
        }
        while(cur->next != NULL)
        {
                if(*(cur->next->value) == item)             
                {
                        Node<T*> *temp = cur->next->next;
                        delete cur->next->value;            //delete object pointed to by value
                        delete cur->next;
                        cur->next = temp;
                        length--;
                        return true;
                }
                cur=cur->next;
        }
        if(*(cur->value) == item)
        {
                remove_back();
                return true;
        }
        return false;

}
/*
 *   insert_sorted
 *   - As items are inserted into the list, they are sorted to be in ascending order before being inserted into list.
 *
 *   @param
 *   - an item to be inserted called st is passed in
 *
 *   @return
 *   - void
 */
        template <typename T>
void List<T>::insert_sorted(T st)
{
        Node<T> *cur = head;                                //keeps track of position in list as it's scanned
        Node<T> *prev = head;                               //holds previous member of list so that structure can be maintained
        if(length == 0)                                     //if list is empty, insert the item into the list and return to caller
        {
                insert(st);
                return;
        }
        if(st < (cur->value))                               //if the item should be put at the front of the list use existing function
        {
                insert(st);
                return;
        }
        while(cur != NULL)                                  //step through list
        {
                if(st < (cur->value))                       //If st is to be before the current value insert it between the cur and prev
                {
                        prev->next = new Node<T>(st, cur);
                        length++;
                        return;
                }
                if((cur->next) == NULL)                     //If st belongs at the end of the list insert it at the end
                {
                        cur->next = new Node<T>(st,NULL);
                        length++;
                        return;
                }
                prev = cur;
                cur = cur->next;
        }
}
/*
 *   insert_sorted(Partial Specialization)
 */
        template <typename T>
void List<T*>::insert_sorted(T st)
{
        T *ptr_to_st = new T(st);                                       //Pointer to object to which value will point
        Node<T*> *cur = head;
        Node<T*> *prev = head;
        if(length == 0)
        {
                insert(st);
                return;
        }
        if(st < *(cur->value))
        {
                insert(st);
                return;
        }
        while(cur != NULL)
        {
                if(st < *(cur->value))
                {
                        prev->next = new Node<T*>(ptr_to_st, cur);      //Set value to point to object created earlier
                        length++;
                        return;
                }
                if((cur->next) == NULL)
                {
                        cur->next = new Node<T*>(ptr_to_st,NULL);
                        length++;
                        return;
                }
                prev = cur;
                cur = cur->next;
        }
}
/*
 *   insert_back
 *   - Insert a Node at the end of the list
 *   
 *   @param
 *   - object named st to be inserted
 *
 *   @return
 *   - void
 */
        template <typename T>
void List<T>::insert_back(T st)
{
        Node<T> *cur = head;                                //Pointer to step through the list
        if(cur == NULL)                                     //If the list is empty, insert item and return
        {
                insert(st);
                return;
        }
        while(cur != NULL)
        {
                if(cur->next == NULL)                       //if the end of the list is reached, insert the Node at the end
                {
                        cur->next = new Node<T>(st,NULL);
                        length++;
                        return;
                }
                cur = cur->next;
        }
}
/*
 *   insert_back(Partial Specialization)
 */

        template <typename T>
void List<T*>::insert_back(T st)
{
        T *ptr_to_value = new T(st);                                //Pointer to object to be passed to value
        Node<T*> *cur = head;
        if(cur == NULL)
        {
                insert(st);
                return;
        }
        while(cur != NULL)
        {
                if((cur->next) == NULL)
                {
                        cur->next = new Node<T*>(ptr_to_value,NULL);//Create new Node with pointer to object pointed at st
                        length++;
                        return;
                }
                cur = cur->next;
        }
}
/*
 *   remove_back
 *   - Remove the last Node in the list
 *
 *   @param
 *   - void
 *
 *   @return
 *   - bool which indicates whether the last Node is removed or not
 *
 */
        template <typename T>
bool List<T>::remove_back()
{
        Node<T> *cur = head;                //Pointer to keep track of current Node
        Node<T> *prev = head;               //Pointer to keep track of previous Node
        if(head == NULL)                    //If the list is empty return false
        {
                return false;
        }
        while(cur != NULL)
        {
                if(cur->next== NULL)        //once the end of the list is reached delete the last Node
                {
                        delete prev->next;  //delete the Node
                        prev->next = NULL;  //maintain the end of the list
                        length--;
                        return true;
                }
                prev = cur;
                cur = cur->next;
        }
        return false;                       //if the end is not found return false
}
/*
 *   remove_back(Partial Specialization)
 */
        template <typename T>
bool List<T*>::remove_back()
{
        Node<T*> *cur = head;
        Node<T*> *prev = head;
        if(head == NULL)
        {
                return false;
        }
        while(cur != NULL)
        {
                if(cur->next == NULL)
                {
                        delete prev->next->value;   //delete the object which value points to
                        delete prev->next;
                        prev->next = NULL;
                        length--;
                        return true;
                }
                prev = cur;
                cur = cur->next;
        }
        return false;
}
/*
 *   insert_after
 *   - Inserts item after an object whose value is passed in as existing, if "existing" doesn't exist the node is not inserted
 *
 *   @param
 *   - existing - an object which is to be searched for in the list
 *   - item - object to be inserted
 */
        template <typename T>
void List<T>::insert_after(T existing, T item)
{
        Node<T> *cur = head;
        if(head == NULL)                        //If list is empty return
        {
                return;
        }
        Node<T> *ins = new Node<T>(item, NULL); //create Node to be inserted
        while(cur!= NULL)
        {
                if(cur->value == existing)      //if existing is found insert the item after that node
                {
                        ins->next = cur->next;  // maintain list structure point new node at next node
                        cur->next = ins;        // point current node at inserted node
                        length++;               
                        return;
                }
                cur = cur->next;
        }
}
/*
 *   insert_after(Partial Specialization)
 */
        template <typename T>
void List<T*>::insert_after(T existing, T item)
{  
        T* ptr_to_item = new T(item);                       //pointer to item to be inserted
        Node<T*> *cur = head;
        if(head == NULL)
        {
                return;
        }
        Node<T*> *ins = new Node<T*>(ptr_to_item, NULL);    //use pointer to item rather than the item itself
        while(cur!= NULL)
        {
                if(*(cur->value) == existing)
                {
                        ins->next= cur->next;
                        cur->next = ins;
                        length++;
                        return;
                }
                cur = cur->next;
        }
}
/*
 *   copy_sorted
 *   - Copy's objects from a host list to a destination list and sorted them into ascending order at the same time
 *
 *   @param
 *   - Host list is passed in to be copied from
 *
 *   @return
 *   - void
 */
        template <typename T>
void List<T>::copy_sorted(const List<T> &rhs)
{
        Node<T> *host = rhs.head;               //create pointer to go through host list
        if(host == NULL)                        //If host is empty return
        {
                return;
        }
        if(head != NULL)                        //if destination list has items in, clean it
        {
                clean();
        }
        insert(host->value);                    //insert item from host list into destination list
        host = host->next;
        while(host != NULL)
        {
                insert_sorted(host->value);     //use insert_sorted function to sort the values as the list is stepped through
                host = host->next;
        }
}
/*
 *   copy_sorted(Partial Specialization)
 */
        template <typename T>
void List<T*>::copy_sorted(const List<T*> &rhs)
{   
        Node<T*> *host = rhs.head;
        if(host == NULL)
        {
                return;
        }
        if(head != NULL)
        {
                clean();
        }
        insert(*(host->value));                 //Dereferences host pointer to pass the value to the function not a pointer
        host = host->next;
        while(host != NULL)
        {
                insert_sorted(*(host->value));
                host = host->next;
        }  
}
/*
 *   print_greater
 *   - Print out values that are greater than a dummy value that is passed into function
 *   
 *   @param
 *   - Dummy value to create threshold
 *
 *   @return
 *   - void
 */
        template <typename T>
void List<T>::print_greater(T st)
{
        Node<T> *cur = head;
        if(head == NULL)                            //if list is empty, return
        {
                return;
        }
        while(cur != NULL)
        {
                if((cur->value) > st)               //if list value is greater than threshold print it out
                {
                        cout << cur->value << endl;
                }
                cur = cur->next;
        }
}
/*
 *   print_greater(Partial Specialization)
 */
        template <typename T>
void List<T*>::print_greater(T st)
{
        Node<T*> *cur = head;
        if(head == NULL)
                return;
        while(cur != NULL)
        {
                if(*(cur->value) > st)                  //compare threshold with value pointed to by the Node
                {
                        cout << *(cur->value) << endl;  //cout value pointed to by node
                }
                cur = cur->next;
        }
}


