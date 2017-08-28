/*
*       CSCI 211
*       Project 04
*       main.cpp
*       Daniel Rush
*/
#include <stdlib.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<cmath>
using namespace std;
#include "list.cpp"
#include "stack.h"
bool pop_op(Stack<double> &dStack, double &rhs, double &lhs);
int main(){
    Stack<double> dStack;
    double d;
    char ch;
    double rhs;
    double lhs;
    double res;
    while(cin.peek() != EOF)        
    {
        ch = cin.peek();
        if((isdigit(ch)) || (ch == '.'))                            //check if the input is a digit or a . signifying it is a double
        {
            cin>>d;                                                 //input that number
            dStack.push(d);
            ch = cin.peek();
            if(ch == '.')                                           //ensure that 2 numbers are separated by a space
            {
                cerr << "Error: Invalid expression." << endl;
                return 1;
            }
        }
        else if(isspace(ch))                                        //when there is a space separating numbers ignore it
        {       
            cin.ignore();
        }
        else
        { 
            cin >> ch;                                              //otherwise it is an operator case structure to handle arithmetic
            switch(ch)
            {
                case '+':                                           //addition case
                    if(pop_op(dStack, lhs, rhs))                    //call pop_op to read and pop lhs and rhs off of the stack
                    {
                        res = lhs + rhs; 
                        dStack.push(res);
                    }
                    else                                           
                    {
                        return 1;
                    }
                    break;
                case '-':                                           //subtraction
                    if(pop_op(dStack, lhs, rhs))
                    {
                        res = lhs - rhs;
                        dStack.push(res);
                    }
                    else
                    {
                        return 1;
                    }
                    break;
                case '/':                                           //division
                    if(pop_op(dStack, lhs, rhs))
                    {
                        if(rhs == 0)                                //don't allow division by 0
                        {
                            return 1;
                        }
                        res = lhs / rhs;
                        dStack.push(res);
                    }
                    else
                    {
                        return 1;
                    }
                    break;
                case '*':                                           //multiplication
                    if(pop_op(dStack, lhs, rhs))
                    {
                        res = lhs*rhs;
                        dStack.push(res);
                    }
                    else
                    {
                        return 1;
                    }
                    break;
                case '^':                                           //exponential
                    if(pop_op(dStack, lhs, rhs))
                    {   
                        if(lhs == 0 && rhs < 0)                     //don't allow 0^-2 which would be division by 0
                        {
                            return 1;
                        }
                        res = pow(lhs,rhs);
                        dStack.push(res);
                    }
                    else
                    {
                        return 1;
                    }
                    break;
                default:                                            //If it's not an accepted operator throw error
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
                    break;
            }
        }
    }
    if(dStack.empty())                                              //if the stack is empty throw error
    {
        cerr << "Error: Invalid expression." << endl;
        return 1;
    }
    res = dStack.top();
    dStack.pop();
    if(dStack.empty())                                              //make sure that there is nothing in the stack other than the result
    {
        cout << res << endl;
    }
    else
    {
        cerr<< "Error: Invalid expression." << endl;                //throw error if the stack isn't empty
        return 1;
    }
    return 0;
}//main
/*
*   pop_op
*       This function pops the rhs and lhs of the operation and returns them by reference to main this is useful because
*       it is a redundant piece of code between all cases in the calculator
*   
*   @param
*       The stack, the lhs and the rhs are passed by reference so that the function is able to manipulate them
*
*   @return
*       Returns a boolean so that the main function can tell if the operation can continue properly
*/
bool pop_op(Stack<double> &dStack, double &rhs, double &lhs)
{
    if(!dStack.empty())                                 //Check to make sure there is a value to pop, and put it into lhs
    {
        lhs = dStack.top();
        dStack.pop();
    }
    else                                                //if it is empty throw error
    {
        cerr << "Error: Invalid expression." << endl; 
        return false;
    }
    if(!dStack.empty())                                 //Check to make sure there is a value to pop, and put it into rhs
    {
        rhs = dStack.top();
        dStack.pop();
    }
    else                                                //if it is empty throw error
    {
        cerr << "Error: Invalid expression." << endl; 
        return false;
    }
    return true;                                        //if function is executed correctly return true
}
