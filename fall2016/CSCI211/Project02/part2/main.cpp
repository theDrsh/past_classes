#include<iostream>
#include<string>
using namespace std;

#include "student.h"
#include "Vector.h"

void print(Vector &v){
    int asize = v.size();
    for(int i = 0; i < asize; i++){
        cout << *(v.at(i)) << endl;
    }
}
void read(Vector &v){
    Student st;
    while(cin >> st){
        v.push_back(st);
    }//while
}
int main(){
    Vector v;
    read(v);
    cout << "Vector is initialized with " << v.size()
        << " students; capacity = " << v.get_capacity() << endl;
    if(v.size() > 0){
    print(v);
    cout << endl;
    }

    cout << "Testing push_front function:" << endl;
    v.push_front(Student("Great", 3.9));
    cout << "Capacity = " << v.get_capacity()
        << ", size = " << v.size() << endl;
    print(v);
    cout << endl;

    cout << "Testing pop_front function:" << endl;
    bool success = v.pop_front();
    if(success){
        print(v);
    }
    else{
        cerr <<  "Error: can't remove element from an empty vector." << endl;
    }
    cout << endl;
    cout << "Testing pop_back function:" << endl;
    success = v.pop_back();
    if(success)
        print(v);
    else{
            cerr <<  "Error: can't remove element from an empty vector." << endl;
                }
    cout << endl;
    cout << "Testing insert_after with index = 3" << endl;
    success = v.insert_after(Student("Terrific", 2.9), 3);
    if(success)
        print(v);
    else{
        cerr << "ERROR: index must be 0...size-1." << endl;
    }
    cout << endl;
    cout << "Testing insert_after with invalid index" << endl;
    success = v.insert_after(Student("Wonder", 3.89), -1);
    if(success)
        print(v);
    else{
        cerr << "ERROR: index must be 0...size-1." << endl;
    }
    cout << endl;
    //debugging
    /*cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.get_capacity() << endl;
    for(int i = 0; i < v.size()-1; i++)
    {
        cout << "Vector at index " << i << "= " << *v[i] << endl;
    }*/
    //end debug
    if(v.size() > 0){
        cout << "Testing [] operator:" << endl;
        *v[0] = Student("STAR", 3.33);
        print(v);
    }
return 0;
}//main()


