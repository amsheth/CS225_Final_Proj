#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include "Graph.h"
// A Java program for Dijkstra's
// single source shortest path
// algorithm. The program is for
// adjacency matrix representation
// of the graph.

/*int NO_PARENT = -1;

// Function to print shortest path
// from source to currentVertex
// using parents array
void printPath(int currentVertex, vector<int> parents)
{

	// Base case : Source node has
	// been processed
	if (currentVertex == NO_PARENT) {
		return;
	}
	printPath(parents[currentVertex], parents);
	cout << currentVertex << " ";
}

// A utility function to print
// the constructed distances
// array and shortest paths
void printSolution(int startVertex, vector<int> distances,
				vector<int> parents)
{
	int nVertices = distances.size();
	cout << "Vertex\t Distance\tPath";

	for (int vertexIndex = 0; vertexIndex < nVertices;
		vertexIndex++) {
		if (vertexIndex != startVertex) {
			cout << "\n" << startVertex << " -> ";
			cout << vertexIndex << " \t\t ";
			cout << distances[vertexIndex] << "\t\t";
			printPath(vertexIndex, parents);
		}
	}
}

// Function that implements Dijkstra's
// single source shortest path
// algorithm for a graph represented
// using adjacency matrix
// representation

void dijkstra(vector<vector<int> > adjacencyMatrix,
			int startVertex)
{
	int nVertices = adjacencyMatrix[0].size();

	// shortestDistances[i] will hold the
	// shortest distance from src to i
	vector<int> shortestDistances(nVertices);

	// added[i] will true if vertex i is
	// included / in shortest path tree
	// or shortest distance from src to
	// i is finalized
	vector<bool> added(nVertices);

	// Initialize all distances as
	// INFINITE and added[] as false
	for (int vertexIndex = 0; vertexIndex < nVertices;
		vertexIndex++) {
		shortestDistances[vertexIndex] = INT_MAX-1;
		added[vertexIndex] = false;
	}

	// Distance of source vertex from
	// itself is always 0
	shortestDistances[startVertex] = 0;

	// Parent array to store shortest
	// path tree
	vector<int> parents(nVertices);

	// The starting vertex does not
	// have a parent
	parents[startVertex] = NO_PARENT;

	// Find shortest path for all
	// vertices
	for (int i = 1; i < nVertices; i++) {

		// Pick the minimum distance vertex
		// from the set of vertices not yet
		// processed. nearestVertex is
		// always equal to startNode in
		// first iteration.
		int nearestVertex = -1;
		int shortestDistance = INT_MAX -1;
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			if (!added[vertexIndex]
				&& shortestDistances[vertexIndex]
					< shortestDistance) {
				nearestVertex = vertexIndex;
				shortestDistance
					= shortestDistances[vertexIndex];
			}
		}

		// Mark the picked vertex as
		// processed
		added[nearestVertex] = true;

		// Update dist value of the
		// adjacent vertices of the
		// picked vertex.
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			int edgeDistance
				= adjacencyMatrix[nearestVertex]
								[vertexIndex];

			if (edgeDistance > 0
				&& ((shortestDistance + edgeDistance)
					< shortestDistances[vertexIndex])) {
				parents[vertexIndex] = nearestVertex;
				shortestDistances[vertexIndex]
					= shortestDistance + edgeDistance;
			}
		}
	}

	printSolution(startVertex, shortestDistances, parents);
}

// Driver Code
int main()
{
	vector<vector<int> > adjacencyMatrix
		= { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 0, 0, 0, 0, 11, 0 },
			{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
			{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
			{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
			{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
			{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
			{ 0, 11, 0, 0, 0, 0, 1, 0, 7 },
			{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(adjacencyMatrix, 5);
	return 0;
}
*/
int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<17;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[17][17],int src) // adjacency matrix 
{
    int distance[17]; // // array to calculate the minimum distance for each node                             
    bool Tset[17];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<17; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<17; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<17; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<17; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{
    int graph[17][17]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,66,60,0,61,0,64,63,78,81,0,0,0,0,0,0},
			{0,66,72,69,74,81,73,70,73,78,81,0,69,0,0,72,0},
			{0,60,69,60,74,75,73,61,0,77,78,64,0,79,81,72,0},
			{0,0,74,74,73,0,0,61,65,77,81,0,0,79,0,0,0},
			{0,61,81,75,0,75,64,0,0,0,0,0,0,0,0,0,0},
			{0,0,73,73,0,64,64,67,67,0,0,0,0,0,0,0,0},
			{0,64,70,61,61,0,67,0,0,0,0,0,0,0,0,0,0},
			{0,63,73,0,65,0,67,0,0,0,0,0,0,0,0,0,0},
			{0,78,78,77,77,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,81,81,78,81,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,64,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,79,79,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,81,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,72,72,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}};
    DijkstraAlgo(graph,3);
    return 0;                           
}