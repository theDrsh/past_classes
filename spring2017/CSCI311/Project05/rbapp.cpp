/**
* @file rbapp.cpp definitions of RBapp class functions
*
* @author Daniel Rush <drush1@mail.csuchico.edu>
*
* @date 04/29/2017
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
#include"rbapp.h"
using std::cin;
using std::string;
using std::stringstream;
/**
* main
*/
int main()
{
    RBapp tree;
    tree.mainLoop();
    return 0;
}
/**
* Grabs line from standard input, and gives to process command while it's true.
*/
void RBapp::mainLoop()
{
    string input;
    getline(cin, input);
    while(processCommand(input))
    {
        getline(cin,input);
    }
}
/**
* Processes command and creates a string which holds key and or value.
*
* @param String input from standard input.
*
* @return Boolean value which is true while the command isn't quit.
*/
bool RBapp::processCommand(string& input)
{
    string command;
    string key;
    string value;
    string keyValue;
    stringstream ss;
    ss<<input;
    ss>>command;
    getline(ss, keyValue);
    if(command == "quit")
    {
        return false;
    }
    if(command == "insert")
    {
        processInsert(keyValue);   
        input = "";
        return true;
    }
    if(command == "find")
    {
        processFind(keyValue);
        input = "";
        return true;
    }
    if(command == "delete")
    {
        processDelete(keyValue);
        input = "";
        return true;
    }
    if(command == "print")
    {
        processPrint();
        input = "";
        return true;
    }
    else
    {
        return true;
    }
    return true;
}
/**
* Processes insert command, called by processCommand function
*
* @param input string which contains the key and the value separated by a space.
*/
void RBapp::processInsert(string& input)
{
    string key;
    string value;
    stringstream ss;
    ss<<input;
    ss>>key;
    ss.ignore();
    getline(ss, value);
    myRBT.rbInsert(key,value);
}
/**
* Processes print command, called by processCommand function
*/
void RBapp::processPrint()
{
    myRBT.rbPrintTree();
}
/**
* Processes find command, called by processCommand function
*
* @param input string which contains the key.
*/
void RBapp::processFind(string& input)
{
    vector<const string*>values;
    input.erase(input.begin(),input.begin()+1);
    values = myRBT.rbFind(input);
    for(int i = 0; i<(int)values.size(); i++)
    {
        std::cout<< *values[i] << std::endl;
    }
    for(int i = 0; i<(int)values.size(); i++)
    {
        delete(values[i]);
    }
}
/**
* Processes delete command, called by processCommand function
*
* @param input string which contains the key and the value separated by a space.
*/
void RBapp::processDelete(string& input)
{
    string key;
    string value;
    stringstream ss;
    ss<<input;
    ss>>key;
    ss.ignore();
    getline(ss,value);
    myRBT.rbDelete(key, value);
}
