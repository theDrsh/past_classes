#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

#include "student.h"

istream& operator>>(istream &in, Student &st){
    in >> st.name >> st.gpa;
    return in;
}
ostream& operator<<(ostream &out, Student &st){
    out << st.get_name()<<" " << fixed 
        << setprecision(2)
        << st.get_gpa() ;
    return out;
}

bool Student::operator==(const Student &st){
    if(name == st.name)
        return true;
    else 
        return false;
}
bool Student::operator<(const Student &st){
    if(name < st.name)
        return true;
    else
        return false;
}
bool Student::operator>(const Student &st){
    if(gpa > st.gpa)
        return true;
    else
        return false;
    
}
