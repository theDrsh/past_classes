#include<iostream>
#include<string>
#include<ctime>
#include<algorithm>
using namespace std;
#include "list.cpp"
#include "student.h"

int main(){
        List<Student* > alist;
        Student st;
        while(cin >> st){
                alist.insert(st);
        }
        alist.print();
        cout << "\nTesting copy-constructor:" << endl;
        List<Student* > second(alist);
        second.print();

        cout << "\nTestsing operator=" << endl;
        List<Student* > another = alist;
        another.print();

        cout << "\nTesting operator= on the list with items:" << endl;
        another = alist;
        another.print();

        cout << "\nTesting copy_sorted that uses insert_sorted:" << endl;
        another.copy_sorted(alist);
        another.print();

        Student at("Jasper", 1.85);
        bool is_removed = another.find_remove(at);
        if(!is_removed){
                cerr << "ERROR: was unable to remove " << at << endl;
        }
        else{
                cout << "\nTesting find_remove:" << endl;
                another.print();
        }
        //second.print();
        Student bt("Prat", 3.89);
        second.insert_back(bt);
        cout << "\nTesting insert_back:" << endl;
        second.print();

        is_removed = another.remove_back();
        if(!is_removed){
                cerr << "ERROR: was unable to remove back " << at << endl;
        }
        else{
                cout << "\nTesting remove_back:" << endl;
                another.print();
        }

        cout << "\nTesting insert_after at the back:" << endl;
        second.insert_after(bt, at);
        second.print();

        cout << "\nTesting insert_after:" << endl;
        Student ct("Jo", 2.0);
        another.insert_after(ct, bt);
        another.print();

        cout << "\nTesting print_greater:" << endl;
        second.print_greater(ct);

        return 0;
}//main()

