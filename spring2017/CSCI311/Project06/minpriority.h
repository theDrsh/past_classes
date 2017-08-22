/*
*   Class declaration of a min-heap structure
*
*   @author: Daniel Rush
*
*   @date: 4/15/2017
*/
#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

class MinPriorityQ
{
    public:
    MinPriorityQ();                             //constructor
    ~MinPriorityQ();                            //destructor
    void insert(string id, int key);            //insert element
    void decreaseKey(string id, int newKey);    //decrease element key
    string extractMin();                        //dequeue lowest key
    bool isMember(string id);                   //check if element is member of heap

    private:
    void buildMinHeap();                        //build minheap from existing vector
    void minHeapify(int i);                     //make index root of minheap
    int parent(int i);                          //return parent of index
    int left(int i);                            //return left child of index
    int right(int i);                           //return right child of index
    class Element                       
    {
        public:
        string id;
        int key;
    };
    vector<Element> minHeap;
};
