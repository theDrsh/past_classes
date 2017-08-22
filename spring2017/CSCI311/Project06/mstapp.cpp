/**
* @file Entry point of program and function definition runs Prims algorithm
*
* @author Daniel Rush
* 
* @date 5/9/2017
*/
#include<iostream>
#include"mstapp.h"
using std::cout;
using std::cin;
using std::endl;

/**
* Calls Read graph and starts Prims algorithm
*/
int main()
{
    MSTapp mstGraph;
    mstGraph.readGraph();
    return 0;
}
/**
* Read's graph from standard input and stores it then runs Prims algorithm.
*/
void MSTapp::readGraph()
{
    string first;
    string vertex;
    string neighbor;
    int weight;
    cin >> first;
    myGraph.addVertex(first);
    while(cin.peek() != '\n')
    {
        cin>>vertex;
        myGraph.addVertex(vertex);   
    }
    while(cin >> vertex)
    {
        cin >> neighbor >> weight;
        myGraph.addEdge(vertex, neighbor, weight);
    }
    myGraph.mst(first);
}
