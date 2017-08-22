#include"party.h"
#include"doublylinkedlist.h"
#include<string>
/*
* @file party.cc
*
* @brief
*   Definitions of member functions of Party class.
*
* @author Daniel Rush
* @date 1/28/2016
*/
using std::string;
/**
* @brief    Party Constructor
*/
Party::Party()
{
    numDiners = 0;
    timeRequired = 0;
}
/**
* @brief    Party destructor
*/
Party::~Party()
{
    delete reservationName;
}
/**
* @brief    Party Overloaded Constructor
*/
Party::Party(const string& reservationName, int numDiners, int timeRequired)
{
     this->reservationName = new string(reservationName);
     this->numDiners = numDiners;
     this->timeRequired = timeRequired;
}
