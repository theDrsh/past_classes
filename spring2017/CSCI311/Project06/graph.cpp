/**
* @file graph.h An application which stores the data of the graph.
*
* @author Daniel Rush
* @date 5/9/2017
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include"graph.h"
using std::string;
using std::map;
using std::vector;
#define MAX_INT 2147483647

/**
* Adds a vertex to the graph and initializes it's values to a sentinel value.
*
* @param Name of the vertex to be added.
*/
void Graph::addVertex(string name)
{
    Vertex addVert;
    addVert.key = MAX_INT;
    addVert.pi ="";
    vertices[name] = addVert;
}
/**
* Adds an edge between two vertexes and assigns a weight to it.
*
* @param The names of the vertex from and to which the edge connects and 
*       the weight of the edge.
*/
void Graph::addEdge(string from, string to, int weight)
{
    Neighbor adj;
    adj.name = to;
    adj.weight = weight;
    adjList[from].push_back(adj);
    adj.name = from;
    adjList[to].push_back(adj);
    std::sort(adjList[to].begin(), adjList[to].end());
    std::sort(adjList[from].begin(), adjList[from].end());
}
/**
* Performs Prim's algorithm to find a minimum spanning tree rooted at start.
*
* @param the vertex labeled start is the starting vertex for an arbitrary
*       starting point.
*/
void Graph::mst(string start)
{
    string u;
    vertices[start].key = 0;
    vertices[start].pi = "NIL";
    int totalWeight = 0;
    for(map<string,Vertex>::iterator it = vertices.begin(); it != vertices.end(); ++it)
    {
        minQ.insert(it->first, it->second.key);
    }
    while((u = minQ.extractMin()) != "empty")
    {
        std::cout << u << " " << vertices[u].pi << " " << vertices[u].key << std::endl;
        totalWeight += vertices[u].key;
        for(vector<Neighbor>::iterator list = adjList[u].begin(); list != adjList[u].end(); ++list)
        {
            Neighbor v = *list;
            if(minQ.isMember(v.name) && v.weight < vertices[v.name].key)
            {
                vertices[v.name].pi = u;
                vertices[v.name].key = v.weight;
                minQ.decreaseKey(v.name, v.weight);
            }
        }
    }
    std::cout << totalWeight << std::endl;
}

