#include<iostream>
#include"restaurant.h"
#include"doublylinkedlist.h"
#include"party.h"
#include"table.h"
/**
 * @file restaurant.cc
 *
 * @brief
 *    Definition of member functions of the Restaurant class and main() which is the entry point for program.
 *
 * @author Daniel Rush
 * @date 1/28/16
 */
using std::string;
using std::cin;
using std::cout;
using std::endl;
/**
 * @brief   Entry point of program, creates Restaurant object and calls getInput and serveParties
 * @param   none
 * @return  none
 */
int main()
{
    Restaurant atEndOfUniverse; 
    atEndOfUniverse.getInput();
    atEndOfUniverse.serveParties();
    return 0;
}
/**
 * @brief   Gets user input and places it into corresponding doubly linked lists to be used later
 * @param   none
 * @return  none
 *
 * Grabs user input and places it into lists as long as it follows correct format
 */
void Restaurant::getInput()
{
    string curLine;
    string command;
    string tableName;
    int seats;
    int time;
    string serverName;
    Table* curTable;
    Party* curParty;
    while(cin>>curLine)
    {
        if(curLine == "table")
        {
            cin >> tableName >> seats >> serverName;
            curTable = new Table(tableName, seats, serverName);
            servers[serverName] = 0;
            available.append(curTable);
        }
        if(curLine == "party")
        {
           cin >> seats >> tableName >> time;
           curParty = new Party(tableName, seats, time);
           waiting.append(curParty);
        }
    }
}
/**
 * @brief   Algorithmically seats and serves diners.
 * @param   none
 * @return  none
 *
 * First iterates through occupied tables checking how long they have left at the table and decrements timers moves
 * finished tables to available lists, deletes finished parties, iterates through waiting parties and seats them at
 * tables which are capable of holding their party until there are no more waiting diners and no seated diners
 */
void Restaurant::serveParties()
{
    unsigned int i = 0;
    Table* occTable = nullptr;
    Table* avTable = available.first();
    Party* waitParty = waiting.first();
    const Party*  tableParty;
    bool removed = false;
    while(!waiting.empty() || !occupied.empty())
    {
        avTable = available.first();
        waitParty = waiting.first();
        occTable = occupied.first();
        while(occTable != nullptr)
        {
            occTable->decrementTimer();
            if(occTable->getTimer() == 0)
            {
                tableParty = occTable->getParty();
                cout << *tableParty->getReservationName() << " finished at " << *occTable->getTableID() << endl;
                occTable->clearTable();
                available.append(occTable);                
                occTable = occupied.remove();
                delete tableParty;
            }
            else
            {
                occTable = occupied.next();
            }
        }
        while(waitParty != nullptr)
        {
            avTable = available.first();
            removed = false;
            while(avTable != nullptr)
            {
                if(avTable->getNumSeats() >= waitParty->getNumDiners())
                {
                    cout << *waitParty->getReservationName() << " seated at " << *avTable->getTableID() << endl;
                    avTable->seatParty(waitParty);
                    servers[*avTable->getServerName()] += waitParty->getNumDiners();
                    occupied.append(avTable);
                    avTable = available.remove();
                    waitParty = waiting.remove();
                    removed = true;
                    break;
                }
                else
                {
                    avTable = available.next();
                    removed = false;
                }
                
            }
            if(!removed)
            {
                waitParty = waiting.next();
            }
        }
    }
    std::map<string,int>::const_iterator it;
    for(it = servers.begin(); it != servers.end(); it++)
    {
        cout << it->first << " served " << it->second;
        if(i < servers.size()-1)
        {
            cout << endl;
        }
        i++;
    }
}
