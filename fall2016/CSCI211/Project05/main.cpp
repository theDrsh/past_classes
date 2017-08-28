/*
*   main.cpp
*   Daniel Rush
*   Project 5 
*/
#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

#include "dlist.cpp"
#include "student.h"
#include "priority_queue.h"

void readGroup(PriorityQueue<Student*,int> &group, std::string fileName);
void printGroup(PriorityQueue<Student*,int> &group);
void readDict(PriorityQueue<int,char> &dict, std::string fileName, int lines);
void printDict(PriorityQueue<int,char> &dictionary);

int main(int argc, char *argv[])
{
    PriorityQueue<Student*,int> group;
    PriorityQueue<int,char> dictionary;
    readGroup(group, argv[1]);
    printGroup(group);
    readDict(dictionary, argv[2], stoi(argv[3]));
    printDict(dictionary);
}
/*
*   readGroup
*       - Reads the first file in from the command line input, then
*           places these into a priority queue based on their given priority
*
*   @param
*       - A priority queue object passed by reference which is edited by the
*           and recovered by main, also a file name is passed in which is to be
*           read from
*/
void readGroup(PriorityQueue<Student*,int> &group, std::string fileName)
{
    int priority;
    Student st;
    string name;
    double gpa;
    string curline;
    ifstream in;
    in.open(fileName.c_str(), ios::in);
    istringstream cur;
    while(getline(in,curline))
    {
        istringstream cur(curline);
        cur >> priority >> name >> gpa;
        st.update_name(name);
        st.update_gpa(gpa);
        group.push(st, priority);
        cur.clear();
    }

}
/*
*   printGroup
*       - Prints the priority queue to the screen
*
*   @param
*       - Priority queue is passed in by reference, which is recovered empty because
*         of the way that the queue behaves
*/
void printGroup(PriorityQueue<Student*,int> &group)
{
    while(!group.empty())
    {   
        Student st;
        st = group.front();
        cout << st << endl;
        group.pop();
    }

}
/*
*   readDict
*       - Reads from file and counts occurances of each letter, then pushes
*         the character and count into a priority queue object.
*   
*   @param
*       - Priority queue object is passed in and then filled main recovers this object
*/
void readDict(PriorityQueue<int,char> &dict, std::string fileName, int lines)
{
    //char priority;
    //int value;
    int array[256];
    string curline;
    ifstream in;
    in.open(fileName.c_str(), ios::in);
    int lineCount = 0;
    for(unsigned int i = 0; i < 256; i++)
    {
        array[i] = 0;
    }
    while(lineCount < lines)
    {
        if(getline(in,curline));
        {
            for(unsigned int i = 0; i < curline.length(); i++)
            {
                array[(int)curline[i]]++;
            }
        }
        lineCount++;
    }
    for(int i = 0; i < 256; i++)
    {
        if(array[i] > 0)
        {
            dict.push(array[i],(char)i);
        }
    }
}
/*
*   printGroup
*       - Prints the priority queue to the screen
*
*   @param
*       - Priority queue is passed in by reference, which is recovered empty because
*         of the way that the queue behaves
*/
void printDict(PriorityQueue<int,char> &dictionary)
{
    while(!dictionary.empty())
    {
        cout << dictionary.peek_priority() << "\t" << dictionary.front() << endl;
        dictionary.pop();
    }
}
