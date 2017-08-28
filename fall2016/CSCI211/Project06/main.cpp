/*
 *   Project06
 *   main.cpp
 *   Daniel Rush
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;
#include "student.h"
#include "bst.cpp"
int main(int argc, char* argv[])
{   
    BST<int> numbers;
    BST<Student*> students;
    string command;
    string type;
    string input;
    int num;
    //While commmands are being recieved they are decoded by <command> <type> <input>
    while(cin >> command)
    {
        if(command == "echo")   //each command is housed in it's own if statement
        {
            getline(cin, input);
            cout << input << endl;
        }
        else if(command == "insert")
        {
            cin >> type;
            if(type == "Student")   //execution of command can be broken up by type
            {
                Student ast;
                cin >> ast;         //<input> is read in and manipulated based on type
                if(!students.insert(ast))
                {
                    cerr << ast << " is in the tree." << endl; 
                }
            }
            else if(type == "int")
            {   
                cin >> num;
                if(!numbers.insert(num))
                {
                    cerr << num << " is in the tree." << endl; 
                }
            }
        }
        else if(command == "remove")
        {
            cin >> type;
            if(type == "Student")
            {
                Student ast;
                cin >> ast;
                if(!students.remove(ast))   //some commands have possible errors and are handled accordingly
                {
                    cerr << "Unable to remove " << ast << ". It was not found in the tree." << endl;
                }
            }
            else if(type == "int")
            {
                cin >> num;
                if(!numbers.remove(num))
                {
                    cerr << "Unable to remove " << num << ". It was not found in the tree." << endl;
                }
            }
        }
        else if(command == "print_inorder")
        {
            cin >> type;
            if(type == "Student")
            {
                students.print_inorder();
            }
            if(type == "int")
            {
                numbers.print_inorder();
            }
        }
        else if(command == "find")
        {
            cin >> type;
            if(type == "Student")
            {
                Student ast;
                cin >> ast;
                if(students.find(ast))
                {
                    cout << ast << " is found in the tree." << endl;
                }
                else
                {
                    cerr << ast << " is not found in the tree." << endl;
                }
            }
            if(type == "int")
            {
                cin >> num;
                if(numbers.find(num))
                {
                    cout << num << " is found in the tree." << endl;
                }
                else
                {
                    cerr << num << " is not found in the tree." << endl;
                }
            }
        }
        else if(command == "size")
        {
            cin >> type;
            if(type == "Student")
            {
                cout << "The number of items in the tree is " << students.size() << endl;
            }
            else if(type == "int")
            {
                cout << "The number of items in the tree is " << numbers.size() << endl;
            }
        }
        else if(command == "balanced")
        {
            cin >> type;
            if(type == "Student")
            {
                if(students.balanced())
                {
                    cout << "The tree is balanced." << endl;
                }
                else
                {
                    cout << "The tree is not balanced." << endl;
                }
            }
            else if(type == "int")
            {
                if(numbers.balanced())
                {
                    cout << "The tree is balanced." << endl;
                }
                else
                {
                    cout << "The tree is not balanced." << endl;
                }
            }
        }
        else if(command == "height")
        {
            cin >> type;
            if(type == "Student")
            {
                cout << "The height of the tree is " << students.height() << "." << endl;
            }
            else if(type == "int")
            {
                cout << "The height of the tree is " << numbers.height() << "." << endl;
            }
        }
        else if(command == "print_subtree")
        {
            cin >> type;
            if(type == "Student")
            {
                Student ast;
                cin >> ast;
                students.print_subtree(ast);
                cout << endl;
            }
            else if(type == "int")
            {
                cin>>num;
                numbers.print_subtree(num);
                cout << endl;
            }
        }
        else // if command is not defined user will get the following error
        {
            cerr << "The command " << command << " is not valid" << endl;
        }
    }
}
