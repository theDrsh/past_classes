/*
*   @file: hash_function.cpp
*   @author: Daniel Rush
*   @date: 4/5/2017
*/
 
#include <string>
#include "hash.h"

using std::string;

/*
*   @brief: Returns the index of the hash table where the string should be inserted
*   @about: I chose this hash function as when I looked around online most functions use
*           bit shifting to use all the information about their value to generate a key.
*           I use the beginning and end characters of the string as well as its length to
*           generate a key, this seems to work well, when testing test1.txt it produced a
*           load factor of 0.55 with a table size of 20 with only 3 collisions and a list
*           length of 2.
*   @param: String value which is to be inserted into table or to find the value in table.
*   @return: Index of hash table where value's key is located.
*/
int Hash::hf ( string ins ) 
{
  int hashIndex = ins[0]; 
  hashIndex = hashIndex<<8;
  hashIndex = hashIndex+ins[ins.length()-1];
  hashIndex += ins.length();
  for(int i = 0; i < ins.length()-1; i++) {
    hashIndex += (int)ins[i];
  }
  hashIndex = hashIndex<<8;
  hashIndex += ins[(ins.length()-1)/2];
  hashIndex = hashIndex%HASH_TABLE_SIZE;
  return hashIndex;
}

