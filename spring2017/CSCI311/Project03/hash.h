/*
*   @file: hash.h
*   @author: Judy Challinger and Daniel Rush
*   @date: 4/5/2017
*/

#ifndef __HASH_H
#define __HASH_H

#include <string>
#include <list>
#define HASH_TABLE_SIZE 5000
using std::string;
using std::list;

class Hash {

public:
   Hash();                          // constructor
   void remove(string value);       // remove key from hash table
   void print();                    // print the entire hash table
   void processFile(string value);  // open file and add keys to hash table
   bool search(string value);       // search for a key in the hash table
   void output(string value);       // print entire hash table to a file
   void printStats();               // print statistics

private:
   // HASH_TABLE_SIZE should be defined using the -D option for g++
   list<string> hashTable [HASH_TABLE_SIZE];
   int collisions;                  // total number of collisions
   unsigned int longestList;        // longest list ever generated
   double runningAvgListLength;     // running average of average list length

   int hf(string);                  // the hash function
};

#endif
