/**
* @file graph.h An application which stores the data of the graph
*
* @author Daniel Rush
*
* @date 5/9/2017
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"minpriority.h"
using std::vector;
using std::map;
using std::string;

class Graph
{
    public:
    void addVertex(string name);
    void addEdge(string from, string to, int weight);
    void mst(string start);

    private:
    class Vertex
    {
        public:
        string pi;
        int key;
    };
    class Neighbor
    {
        public:
        string name;
        int weight;
        bool operator<(const Neighbor&n) const {return name< n.name;}
    };
    map<string,Vertex> vertices; 
    map<string,vector<Neighbor>> adjList;
    MinPriorityQ minQ;
};
