// Author: Sean Davis
#ifndef bloodH
#define bloodH

#include "bloodRunner.h"
#include "list.h"



///
/*
	this Vertex class represent a brain cell as a vertex
	in this class, it contains a list a vessels it can connect to.
*/
class Vertex
{
public:
	Vertex(){edges = new List();}
	int rank;	//rank is to represent the depth from it to the source (shortest path).
	int ID;
	List* edges;
  void insertVessel(Vessel vessel);
	bool operator<(Vertex rhs);
	void operator=(Vertex rhs);

	// the rest is the member for Dijkstra
	bool known;
	int prev;
	double score;	// in Dijstra, it could represent the reference.
} ;


///
/*
	this Graph class represent a graph consist of brain cells and vessels.
	To represent the graph, we use the adjacency list.

*/
class Graph
{
public:
	Vertex* vertex;
	int vertexCount;
	Graph(Vessel vessels[], int vesselCount, int cellCount);
	void calRank(); // this function is to calculate the rank for each vertex.
} ;


class Blood
{
	Graph* network;
	Graph* residualGraph;
	int* cellRanks;	// this is an array to store the rank of each cell.
	//int* sortedVertices;				// this is a sorted vertices array to help blood to gain a reference
	
public:
  Blood(Vessel vessels[], int vesselCount, int cellCount, int depth);
  int calcFlows(int fullFlows[], int emptyFlows[]);
}; // class Blood





#endif
