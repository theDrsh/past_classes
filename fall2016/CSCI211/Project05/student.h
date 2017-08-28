#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student{
    public:
    Student(): name(""), gpa(0){};
    Student(const Student &st){ name = st.name; gpa= st.gpa; };
    Student(string n, double g): name(n),
                    gpa(g){};
    string get_name(){ return name; };
    double get_gpa(){ return gpa; };
    void update_gpa(double g){ gpa = g; };
    void update_name(string s){ name = s;};
    private:
    string name;
    double gpa;
    public:
    friend istream& operator>>(istream &in, Student &st);
    friend ostream& operator<<(ostream& out, Student &st);
    bool operator==(const Student &st);
    bool operator<(const Student &st);
    bool operator>(const Student &st);
};

#endif
