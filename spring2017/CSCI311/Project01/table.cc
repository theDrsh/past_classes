#include<string>
#include"party.h"
#include"table.h"
/**
* @file table.cc
*
* @brief
*   Member function definitions for table class.
*
* @author Daniel Rush
* @date 1/28/2016
*/
using std::string;

/**
* @brief    Table Constructor
*/
Table::Table()
{
    numSeats=0;
    timer = 0;
    party = nullptr;
}

/**
* @brief    Table Destructor
*/
Table::~Table()
{
    delete tableID;
    delete serverName;
    delete party;
}

/**
* @brief    Table Overloaded Constructor
*/
Table::Table(const string& tableID, int numSeats, const string& serverName)
{
    this->tableID = new string(tableID); 
    this->numSeats = numSeats;
    this->serverName = new string(serverName);
}
/**
* @brief    Table Constructor
* @param    newParty A pointer to a new party which is to be pointed to by table's member variable party
* @return   void
*
* Points a table's party pointer to a pointer passed from caller.
*/
void Table::seatParty(const Party* newParty)
{
    party = newParty;
    timer = newParty->getTimeRequired();
}
