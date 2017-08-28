#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
#include "priority_queue.h"
#include "tnode.h"
#include "tree.cpp"
#include "dlist.cpp"
int main(int argc, char*argv[])
{
    int totalBits = 0;
    int encodedBits = 0;
    //use command line input to open a specified file
    string input = argv[1];
    ifstream in;
    in.open(input.c_str(), ios::in);
    //if file cannot be opened throw error message
    if(!in.is_open())
    {
        cerr << "ERROR: could not open file " << input << endl;
        return 1;
    }  
    int array[256];
    string curline;
    PriorityQueue<Tree*,int> pq;
    //go initialize elements of array to 0
    for(unsigned int i = 0; i < 256; i++)
    {
        array[i] = 0;
    }
    //read all characters in file, capitalize them, and count frequency of characters
    while(getline(in,curline))
    {
        for(unsigned int i = 0; i < curline.length(); i++)
        {
            curline[i] = toupper(curline[i]);
            array[(int)curline[i]]++;
        }
    }
    //create a priority queue element and tree for each character with frequency as priorty
    for(int i = 0; i < 256; i++)
    {
        if(array[i] > 0)
        {
            Tree nt((char) i);
            pq.push(nt, array[i]);
        }
    }
    //run huffman code merging algorithm
    while(pq.size() > 1)
    {
       Tree tr1 = pq.front();
       int pr1 = pq.peek_priority();
       pq.pop();
       Tree tr2 = pq.front();
       int pr2 = pq.peek_priority();
       pq.pop();
       tr1.merge(tr2);
       int newpr = pr1+pr2;
       pq.push(tr1,newpr);
    }
    //find the depth of each element and multiply by frequency to calculate length of encoded file
    for(int i = 0; i < 256; i++)
    {
        if(array[i] > 0)
        {
           encodedBits += ((pq.front()).encoded_depth((char) i))*array[i]; 
           totalBits += 8*array[i];
        }
    }
    //print the encoding for each character
    (pq.front()).print_encoding();
    //print length of encoded file
    cout << encodedBits << endl;
    //print length of original file
    cout << totalBits << endl; 
    return 0;
}

