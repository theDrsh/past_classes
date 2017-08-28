/*
*   Vector.cpp
*   Daniel Rush
*   Project 2
*/
#include<iostream>
using namespace std;
#include "student.h"
#include "Vector.h"

Vector::Vector(const Vector &rhs){
    this->copy(rhs);
}//copy constructor

Student* & Vector::at(unsigned int i){
   if(i >= my_size || i < 0)
   {
    cerr << "ERROR: trying to access out of range element." << endl;
    exit(0);
   }
   return ptr[i];
}
Student* & Vector::operator[](unsigned int index){
   if(index >= my_size || index < 0){
     cerr << "ERROR: trying to access out of range element." << endl;
     exit(0);
     }
   return ptr[index];
    
}//operator[]

bool Vector::operator==(const Vector &rhs){
    if(my_size == rhs.my_size){
        for(unsigned int i = 0; i < my_size; i++){
            if(*ptr[i] == *(rhs.ptr[i]))
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
    ptr = new Student*[rhs.capacity];
    capacity = rhs.capacity;
    my_size = rhs.my_size;
    for(unsigned int i = 0; i < rhs.my_size; i++){
        ptr[i] = new Student(*(rhs.ptr[i]));
    }//for
}//copy()

void Vector::push_back(Student st){
    if(capacity > my_size){
        ptr[my_size++] = new Student(st);
    }else{
        capacity  *= 2;
        Student* *temp = new Student*[capacity];
        for(unsigned int i = 0 ; i < my_size; i++){
            temp[i] = new Student(*ptr[i]);
        }
        for(unsigned int i = 0; i < my_size; i++)
            delete ptr[i];
        delete [] ptr;
        ptr = temp;
        temp = 0;
        ptr[my_size++] = new Student(st);
    }//else
}//push_back

//-----------------------New Functions---------------------
/*
* pop_back
*   Pops last element of the vector and deallocates that memory, then decrements size
*
* Return: Bool depending on whether there was something to be popped or not.
*/
bool Vector::pop_back()
{
    if(my_size == 0)
    {
        return false; 
    }
    else
    {
        delete ptr[my_size-1];
        my_size--;
        return true; 
    }
}

/*
* push_front
*   checks if there is room in the vector, if there's room it creates a new element
*   at the end of the vector and shifts all elements +1 index and inserts element at 0th element
*   if there isn't room it increases capacity and then does the above
*
* Parameters: Student object which is to be pushed into front of vector
*
*/
void Vector::push_front(Student st)
{   
    if(capacity > my_size)
    {   
        ptr[my_size] = new Student;
        for(unsigned int i = my_size; i>0; i--)
        {
            *ptr[i] = Student(*ptr[i-1]);
        }
        *ptr[0] = Student(st);
        my_size++;
    }
    else
    {
        capacity  *= 2;
        Student* *temp = new Student*[capacity];
        for(unsigned int i = 0 ; i < my_size; i++){
            temp[i] = new Student(*ptr[i]);
        }
        for(unsigned int i = 0; i < my_size; i++)
            delete ptr[i];
        delete [] ptr;
        ptr = temp;
        temp = 0;
        ptr[my_size] = new Student;
        for(unsigned int i = my_size; i>0; i--)
        {
            *ptr[i] = Student(*ptr[i-1]);
        }
        *ptr[0] = Student(st);
        my_size++;
    }
}

/*
* pop_front
*   pops first element of vector and shifts all elements -1 index
*
* Return: Bool value depending on whether vector was empty or not.
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
            *ptr[i]= Student(*ptr[i+1]);
        }
        delete ptr[my_size-1];
        my_size--;
        return true;
    }
}

/*
* insert_after
*   inserts passed element after passed index, checks for room and allocates more memory
*   if needed.
*
* Parameter: Student object to be inserted and integer index after which it is inserted
*
* Return: Boolean depending on whether the index passed was in range of vectors current size
*/
bool Vector::insert_after(Student st, int index)
{
    
    if(my_size >= 0 && index < my_size)
    {
        if(capacity > my_size)
        {
             ptr[my_size] = new Student;
             for(unsigned int i = my_size; i>index; i--)
             {
                 *ptr[i] = Student(*ptr[i-1]);
             }
             *ptr[index+1] = Student(st);
             my_size++;
             return true;
        }
        else
        {
            capacity  *= 2;
            Student* *temp = new Student*[capacity];
            for(unsigned int i = 0 ; i < my_size; i++){
                temp[i] = new Student(*ptr[i]);
            }
            for(unsigned int i = 0; i < my_size; i++)
                 delete ptr[i];
            delete [] ptr;
            ptr = temp;
            temp = 0;
            ptr[my_size] = new Student;
            for(unsigned int i = my_size; i>index; i--)
            {
                 *ptr[i] = Student(*ptr[i-1]);
            }
            *ptr[index+1] = Student(st);
            my_size++;
            return true;
        }
    }
    else
    {
        return false;
    }
}
