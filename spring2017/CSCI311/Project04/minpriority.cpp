/*
*   @file: minpriority.cpp
*   @author: Daniel Rush
*   @date: 4/15/2017
*/
#include<iostream>
#include<string>
#include<vector>
#include "minpriority.h"
#define MAXINT 2147483647
using std::string;
using std::vector;

/*
*   @brief: Default constructor for MinPriorityQ
*   @param: NONE
*   @return: NONE
*/
MinPriorityQ::MinPriorityQ()
{

}
/*
*   @brief: Deconstructor for MinPriorityQ
*   @param: NONE
*   @return: NONE
*/
MinPriorityQ::~MinPriorityQ()
{

}
/*
*   @brief: Inserts an object of type Element into the heap/vector
*   @param: The id and key of the Element to be inserted
*   @return: NONE
*/
void MinPriorityQ::insert(string id, int key)
{
    Element el;
    el.id = id;
    el.key = MAXINT;
    minHeap.push_back(el);
    decreaseKey(id, key);
}
/*
*   @brief: Decreases the key value of an Element and maintains minheap structure
*   @param: id and new key of the element
*   @return: NONE
*/
void MinPriorityQ::decreaseKey(string id, int newKey)
{
    int i = 0;
    for(i = 0; i < (int)minHeap.size(); i++)
    {
        if(minHeap[i].id == id)
        {
            if(newKey > minHeap[i].key)
            {
                std::cerr << "ERROR: New Key is greater than previous key." << std::endl;
                return;
            }
            minHeap[i].key = newKey;
            while(i>0 && (minHeap[parent(i)].key > minHeap[i].key))
            {
                std::swap(minHeap[i], minHeap[parent(i)]);
                i = parent(i);
            }
        }
    }
}
/*
*   @brief: Returns and deletes the Element with lowest key value
*   @param: NONE
*   @return: Returns the string from Element with lowest key value
*/
string MinPriorityQ::extractMin()
{
    if(minHeap.size()>0)
    {
        string min = minHeap[0].id;
        std::swap(minHeap[0], minHeap[minHeap.size()-1]);
        //minHeap.erase(minHeap.end());
        minHeap.pop_back();
        minHeapify(0);
        return min;
    }
    return "empty";
}
/*
*   @brief: Returns true if passed value is found in heap false if not found
*   @param: id to be searched for
*   @return: Boolean true if found false if not
*/
bool MinPriorityQ::isMember(string id)
{
    for(int i = 0; i < (int)minHeap.size(); i++)
    {
        if(minHeap[i].id == id)
        {
            return true;
        }
    }
    return false;
}
/*
*   @brief: Builds a min heap from an existing vector
*   @param: NONE
*   @return: NONE
*/
void MinPriorityQ::buildMinHeap()
{
    for(int i = (int)minHeap.size()-1; i >= 0; i--)
    {
        minHeapify(i);
    }
}
/*
*   @brief: Ensures that element that it is called on is root of minheap
*   @param: Element of vector to be made root of minheap
*   @return: NONE
*/
void MinPriorityQ::minHeapify(int i)
{
    int l = left(i);
    int r = right(i); 
    int minimum = i;
    if(l < (int)minHeap.size() && minHeap[l].key < minHeap[i].key)
    {
        minimum = l;
    }
    else
    {
        minimum = i; 
    }
    if(r < (int)minHeap.size() && minHeap[r].key < minHeap[minimum].key)
    {
        minimum = r;
    }
    if(minimum != i)
    {
        std::swap(minHeap[i], minHeap[minimum]);
        minHeapify(minimum);
    }
}
/*
*   @brief: Returns parent of given index
*   @param: Index of interest
*   @return: Parent of index i
*/
int MinPriorityQ::parent(int i)
{
    return (i-1)/2;
}
/*
*   @brief: Returns left child index of index i
*   @param: Index of interest
*   @return: Left child of index i
*/
int MinPriorityQ::left(int i)
{
    return (i*2)+1;
}
/*
*   @brief: Returns right child of index i
*   @param: Index of interest
*   @return: Right child of index i
*/
int MinPriorityQ::right(int i)
{
    return (i*2)+2;
}
