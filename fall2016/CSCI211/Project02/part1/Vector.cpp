/*
*Vector.cpp
*Daniel Rush
*Project 2 Part 1
*/
#include<iostream>
using namespace std;
#include "student.h"
#include "Vector.h"

Vector::Vector(const Vector &rhs){
    copy(rhs);
}//copy constructor

Student& Vector::at(unsigned int i){
   if(i >= my_size || i < 0)
   {
    cerr << "ERROR: trying to access out of range element."
        << endl;
        exit(0);
   }
   return ptr[i];
}
Student& Vector::operator[](unsigned int index){
   if(index >= my_size || index < 0){
     cerr << "ERROR: trying to access out of range element."          << endl;
     exit(0);
     }
   return ptr[index];
    
}//operator[]

bool Vector::operator==(const Vector &rhs){
    if(my_size == rhs.my_size){
        for(unsigned int i = 0; i < my_size; i++){
            if(ptr[i] == rhs.ptr[i])
                continue;
            else
                return false;
        }//for
        return true;
    }//if
    return false;
}//operator==
        
Vector& Vector::operator=(const Vector &rhs){
    copy(rhs);
    return *this;
}

void Vector::copy(const Vector &rhs){
    if(ptr != NULL){
        delete [] ptr;
    }
    ptr = new Student[rhs.capacity];
    capacity = rhs.capacity;
    my_size = rhs.my_size;
    for(unsigned int i = 0; i < rhs.my_size; i++){
        ptr[i] = rhs.ptr[i];
    }//for
}//copy()

void Vector::reverse(){
    if(my_size > 0){
    int j = 0; 
   int i = my_size - 1;
   while(j < i){
    Student temp = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = temp;
    i--;
    j++;
   }
   }//if not empty
}//reverse()

void Vector::push_back(Student st){
    if(capacity > my_size){
        ptr[my_size++] = st;
    }else{
        capacity  *= 2;
        Student *temp = new Student[capacity];
        for(unsigned int i = 0 ; i < my_size; i++)
            temp[i] = ptr[i];
        delete [] ptr;
        ptr = temp;
        temp = 0;
        ptr[my_size++] = st;
    }//else
}//push_back

/******** New functions *****************/

/*
* pop_back
*   Pops the last element of the vector
*
* Return: Bool value depending on whether the function was sucessful
*/

bool Vector::pop_back()
{
    if(my_size == 0)
    {
        return false;
    }
    else
    {
        my_size--;
        return true;
    }
}

/*
* push_front
*   adds an element to the front of the vector by checking for extra capacity, shifting
*   all elements back one index and inserting new element at index 0
*
* Parameter: An object of type Student is passed in to be inserted at the 0th index of
* the vector.
*/
void Vector::push_front(Student st)
{
    if(capacity > my_size)
    {
      for(int i = my_size; i>0; i--)
      {
        ptr[i] = ptr[i-1];
      }
      ptr[0] = st;
      my_size++;
    }
    else
    {
        capacity *= 2;
        Student *temp = new Student[capacity];
        for(unsigned int i = 0; i < my_size; i++)
        {
            temp[i+1] = ptr[i];
        }
        temp[0] = st;
        delete [] ptr;
        ptr = temp;
        temp = 0;
        my_size++;
    }
}
/*
* pop_front
*   pops first element of the vector and shifts all elements forward or -1 index
*
* Return: bool value depending on the success of the function
*/
bool Vector::pop_front()
{
    if(my_size == 0)
    {
        return false;
    }
    else
    {
        for(unsigned int i = 0; i < my_size-1; i++)
        {
            ptr[i]=ptr[i+1];
        }
        my_size--;
        return true;
    }
}
/*
* insert_after
*   Inserts an element after an index which is passed by calling function
* 
* Parameters: Student object to be inserted, and index where object is to be inserted
*
* Return: Bool which depends on success of function
*/
bool Vector::insert_after(Student st, int index)
{
    if(index >= 0 && index < my_size)
    {
        my_size++;
        for(unsigned int i = my_size; i > index; i--)
        {
            ptr[i] = ptr[i-1];
        }
        ptr[index+1] = st;
        return true;
    }
    else
    {
        return false;
    }
}
