/*
*   @file: hash.cpp
*   @author: Daniel Rush
*   @date: 4/5/2017
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <list>
#include "hash.h"

/*
*   @brief: Searches for a string in the hash table using the hash function
*   @param: String which is to be searched for
*   @return: Returns true if string is found, and false if not found
*/
bool Hash::search(string value)
{
    int hashIndex = hf(value);
    for(std::list<string>::iterator it = hashTable[hashIndex].begin(); it != hashTable[hashIndex].end(); ++it)
    {
        if(*it == value)
        {
            return true;
        }
    }
    return false;
}
/*
*   @brief: Default constructor for the Hash class
*   @param: void
*   @return: void
*/
Hash::Hash()
{
    collisions = 0;
    longestList = 0;
    runningAvgListLength = 0;
}

/*
*   @brief: Prints the hash table's contents to the screen
*   @param: void
*   @return: void
*/
void Hash::print()
{
   for(int i = 0; i < HASH_TABLE_SIZE; i++) 
   {
        std::cout << i << ":	";
        for(std::list<string>::iterator it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
        {
            std::cout << *it << ", ";
        }
        std::cout << std:: endl;
   }
}

/*
*   @brief: Remove the entry corresponding to the string passed into function
*   @param: String to be removed
*   @return: void
*/
void Hash::remove(string value)
{
    int hashIndex = hf(value);
    double elements = 0;
    double nonempty = 0;
    if(search(value))
    {
        hashTable[hashIndex].remove(value);
        double average = 0;
        for(int i = 0; i < HASH_TABLE_SIZE; i++)
        {
            elements += hashTable[i].size(); 
            if(!hashTable[i].empty())
            {
                nonempty++;
            }
        }
        average = elements/nonempty;
        runningAvgListLength = (runningAvgListLength+average)/2;
    }
}

/*
*   @brief: Sends contents of the hash table to a file before the program finishes execution
*   @param: String which is name of output file
*   @return: void
*/
void Hash::output(string fileName)
{
    std::ofstream outFile;
    outFile.open(fileName, std::ios::out);
    for(int i = 0; i < HASH_TABLE_SIZE; i++) 
    {
        outFile << i << ":	";
        for(std::list<string>::iterator it = hashTable[i].begin(); it != hashTable[i].end(); ++it)
        {
            outFile << *it << ", ";
        }
        outFile << std::endl;
    }
}

/*
*   @brief: Print's the statistics of the hash table like the average list length
*           and the longest list ever, as well as the load factor of the hash table
*   @param: void
*   @return: void
*/
void Hash::printStats()
{
    float n = 0;
    std::cout << "Total Collisions = " << collisions << std::endl;
    std::cout << "Longest List Ever = " << longestList << std::endl;
    std::cout << "Average List Length Over Time = " << runningAvgListLength << std::endl;
    for(int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        n += hashTable[i].size();
    }
    std::cout << std::setprecision(2) << "Load Factor = " << (float)n/HASH_TABLE_SIZE <<  std::endl;
}

/*
*   @brief: Processes input file putting all of the contents into the hash table
*   @param: fileName of the input file
*   @return: void
*/
void Hash::processFile(string fileName)
{
    int hashIndex = 0;
    std::ifstream inputFile;
    inputFile.open(fileName, std::ios::in);
    string input;
    while(getline(inputFile, input))
    {
        double elements = 0;
        double nonempty = 0;
        hashIndex = hf(input);
        if((hashTable[hashIndex].size()) > 0)
        {
            collisions++;
        }
        hashTable[hashIndex].push_back(input);
        if(hashTable[hashIndex].size() > longestList)
        {
            longestList = hashTable[hashIndex].size();
        }
        double average = 0;
        for(int i = 0; i < HASH_TABLE_SIZE; i++)
        {
            elements += hashTable[i].size(); 
            if(!hashTable[i].empty())
            {
                nonempty++;
            }
        }
        average = elements/nonempty;
        runningAvgListLength = (runningAvgListLength+average)/2;
    }
}
