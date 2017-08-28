#include<iostream>
using namespace std;
#include "student.h"

#ifndef VECTOR_H
#define VECTOR_H
class Vector{
    public:
    Vector(){ my_size = 0; capacity = 5; 
        ptr = new Student[capacity]; };
    Vector(int s){
        my_size = s;
        capacity = 2*s;
        ptr = new Student[capacity];
    };
    Vector(const Vector&);
    ~Vector(){ delete [] ptr; ptr = NULL; };
    unsigned int get_capacity(){ return capacity; };
    Student& at(unsigned int i);
    Student& operator[](unsigned int index);
    bool operator==(const Vector &rhs);
    Vector& operator=(const Vector &rhs);
    void copy(const Vector &rhs);
    void reverse();
    void push_back(Student st);
    unsigned int size(){return my_size;}
    
    private:
    unsigned int my_size;
    unsigned int capacity;
    Student* ptr= NULL;

    //You need to write the following functions:
    public:
    bool pop_back();//removes the last element
    bool pop_front();//removes the first element
    void push_front(Student st);//inserts element in front
    bool insert_after(Student st, int index);


};
#endif
