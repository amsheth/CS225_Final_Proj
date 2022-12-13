#include "Graph.h"
#include <sstream>
#include <vector>
#include <fenv.h>
#include <signal.h>
//#include <bits/stdc++.h>
#include <iostream>
//#include <adjMath>
//#include <cstdlib>
//#include <map>
//#include <unordered_map>
#include <list>
#include "utils.h"
#include <algorithm>
#include <string>
#include <set>
#include <limits.h>
#include <iomanip>  


using namespace std;

int Graph::introduction()   {
    cout << "Welcome to Songweb! Songweb is a disconnected graph that has songs from Spotify as vertices and a combined genre-popularity " << endl;
    cout << "factor as weighted edges. This data was all pulled from Spotify's API with the use of the spotipy library." << endl << endl;
    cout << "There are 3 algorithms that can be tested here: Dijkstra's algorithm for finding shortest paths (option 1), a BFS algorithm" << endl;
    cout << "for finding the shortest path between two nodes (option 2), and an algorithm that identifies the centrality of a given song in the" << endl;
    cout << "graph (Betweenness Centrality, option 3). Please type in which of the algorithms you would like to test below:" << endl;
    int ret;
    cin >> ret;
    return ret;
}

Graph::Graph(const V2D & playlist){     // constructor
    numVertices=playlist.size();
    numVertices=numVertices-1;
    //vector<vector<int>> adjMat= new vector<vector<int>>;
    adjMat.resize(numVertices);
    for (unsigned i = 0; i < playlist.size()-1; i++){
        adjMat[i].resize(numVertices);
        for (int j=0;j<numVertices;j++){
            adjMat[i][j]=0;
        }
        //adjMat.push_back(std::vector<int>(playlist.size(), 0));
    }
    nodes(playlist);
}

void Graph::addWeight(int x, int y,int value){
    adjMat[x][y] = value;
    adjMat[y][x] = value;
}


void Graph::addEdge(int x, int y){
    adjMat[x][y]++;
    adjMat[y][x]++;
}
void Graph::nodes(const V2D & playlist){
    for (int i=0;i<(int)playlist.size()-1;i++){
        //std::cout << playlist[i][0] << std::endl;
        songs.push_back(playlist[i][0]);
        int x=playlist[i].size() -1;
        popularity.push_back(playlist[i][x]);
        //std::cout << playlist[i][x] << std::endl;
        //std::cout << songs[songs.size()-1] + " - TEST " << std::endl;
    }
}
void Graph::displayMatrix() {
   size_t i, j;
   for(i = 0; i < adjMat.size(); i++) {
      for(j = 0; j < adjMat[i].size(); j++) {
         std::cout << adjMat[i][j] << ",";
      }
      std::cout << std::endl;
   }
}
V2D file_to_V2D(const std::string & filename){
    V2D xyz;    
    std::string str;
    std::string x;
    std::vector<std::string> abc;
    char semicolon=59;
    char nl=10;
    str=file_to_string(filename);
    x=Trim(str);
    int w=SplitString(x,nl,abc);
    for (int i=0;i<w;i++){
        std::vector<std::string> efg;
        int l=SplitString(abc[i],semicolon,efg);
        for (int j = 0; j < l; j++)
        {
            efg[j]=Trim(efg[j]);
        }
        
        xyz.push_back(efg);
    }

    return xyz;

};

void print(const V2D & playlist){
    for (int i = 0; i < (int) playlist.size(); i++){
        //std::cout << "{ ";
        for(int j = 0; j < (int) playlist[i].size()-1; j++){
        std::cout << playlist[i][j] << ";";
        }
        std::cout<<"\n";
        
    }
}




int Graph::bfsUnweightedPath(unsigned int start, unsigned int end)    {

        // returns the number of edges taken to reach the end vertex, or
        // -1 if not possible. since this accounts for unweighted edges only,
        // the return value indicates only genre similarity, as opposed to
        // genre + popularity similarity.

        int retval = 0;
        if(start == end)    {
            return retval;
        }
        
        unsigned int size = numVertices;            
        
        vector<bool> visited;
        for(unsigned i = 0; i < size; i++) {
            visited.push_back(false);
        }
        
        visited[start] = true;

        std::queue<unsigned int> BFS;
        BFS.push(start);

        while(!BFS.empty()) {               // while the queue is not empty, continue checking every nearest non-visited node
                                            // standard bfs search for a specific node
            int frontVertex = BFS.front();
            BFS.pop();
            retval++;   
            bool cant_travel_flag = true;  // used to check if any nodes can be travelled to from current location (defaults to true)
                                           // if true, retval is decremented and the traversal backtracks by one vertex 

            for(unsigned int i = 0; i < size; i++)  {          // loops through all possible edge connections, checks if travel is possible
                                                                // also checks if the inputted destination ("end") is within reach, and if so, returns
                                                                // the number of edges taken to get there using BFS
                if((cant_travel_flag = true) && i == size && adjMat[frontVertex][i] == 0) {

                    retval--;       // if travel is not possible and all possible edges have been searched, return to
                    continue;       // the previous vertex
                }
                else if (i == size && adjMat[frontVertex][i] == 0)   {
                    continue;       // same thing as above, but ignores the flag since in some cases you can travel while exhausting
                                    // all edge choices
                }
                else if(i == end && adjMat[frontVertex][i] != 0)    {
                    return retval;  // if end node is found, return retval
                }
                else if(!visited[i] && adjMat[frontVertex][i] != 0) {
                    cant_travel_flag = false;       // this statement adds unvisited neighbor nodes to the queue
                    visited[i] = true;              // sets to visited here since it's added to the queue anyways
                    BFS.push(i);
                }
            }
        }
    return -1;      // in this case, the BFS has failed to find the destination node. can return whatever but
                    // for now -1 implies no way to reach the end node from the source node
}

int Graph::BetweennessCentrality(int song)  {
    int retval = 0;

    // pseudocode steps:

    // 1.) go through every vertex in the graph, using the adjacency matrix.

    // 2.) at each vertex, run dijkstra's algorithm (must account for weighted edges) on every other
    // vertex. count how many times the shortest path ends up crossing over the input vertex "song".

    // 3.) increment retval each time a shortest path contains index "song".
    // the return value represents how centrally located the inputted song is relative to the rest of the graph. a
    // high return value means many of the shortest paths between nodes cross over the inputted song.


    for(int i = 0; i < numVertices; i++) {       // outer for loop, goes through every vertex


            // runs an altered version of dijkstra's algorithm that includes a check for the inputted song
            // finds the shortest path between the current node and ALL other nodes, if possible
            // if no paths are available from the input to this function, return value will be 0
            
            vector<int> distance (numVertices); // compares distances
            vector<bool> visited (numVertices); // contains visited nodes
            for(int k = 0; k < numVertices; k++)
                {
                    distance[k] = INT_MAX;
                    visited[k] = false;    
                }
    
                distance[i] = 0;   // Source vertex (i) distance is set 0               
    
                for(int k = 0; k < numVertices; k++)                           
                    {
                        int m = miniDist(distance, visited); 
                        visited[m] = true;
                        for(int k = 0; k < numVertices; k++)                  
                            {
                                if(!visited[k] && adjMat[m][k] && distance[m] != INT_MAX && distance[m] + adjMat[m][k] < distance[k]) {
                                    if(m == song)   {       
                                        retval += 1;        // if song m is a part of the shortest path, and if song m is the 
                                                            // inputted song, increment the return value
                                        }
                                    distance[k] = distance[m] + adjMat[m][k];      // updates distance of the current path
                            }
                        }
                    }
                }
            
            return retval;  // betweenness centrality of the inputted vertex
        }   

void Graph::make(const V2D &playlist){
    for (unsigned i = 0; i < songs.size(); i++){
        for(unsigned j = i; j < songs.size(); j++){
            if (songs[i]==songs[j]){
                continue;
            }
            for (unsigned k = 1; k < playlist[i].size()-1; k++){
                for(unsigned t = 1; t < playlist[j].size()-1; t++){
                    if (playlist[i][k] == playlist[j][t]){
                        int w=((stoi(popularity[i])+stoi(popularity[j]))/2)+1;
                        addWeight(i, j, w);
                    }
                }
            }
        }
    }   
}



int Graph::miniDist(vector<int> distance,vector<bool>Tset) // finding minimum distance
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<numVertices;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;     // returns index of song with lowest distance
}


bool Graph::DijkstraAlgo(int src) // adjacency matrix 
{
    vector<int> distance (numVertices); // // array to calculate the minimum distance for each node
    vector<bool>Tset (numVertices);// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<numVertices; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<numVertices; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<numVertices; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && adjMat[m][k] && distance[m]!=INT_MAX && distance[m]+adjMat[m][k]<distance[k])
                distance[k]=distance[m]+adjMat[m][k];
        }
    }
    printDJK(distance);
    return true;
}
void Graph::printDJK(vector<int> distance){
    int width =75;
    cout<<"Vertex\t\t\t\t\t\t\t\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<numVertices; k++)                      
    { 
        //char str=65+k; 
        cout<<left<<setw(width)<<songs[k]<<
        setw(width)<<distance[k]<<endl;
    }
}


int Graph::getNumVertices() const {
    return numVertices;
}

const vector<vector<int>> &Graph::getAdjMat() const {
    return adjMat;
}

const vector<string> &Graph::getSongs() const {
    return songs;
}

