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

Graph::Graph(const V2D & playlist){
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
    //nodes(playlist);
}

// void Graph::addWeight(int x, int y, int z){
//     adjMat[x][y] = z;
//     adjMat[y][x] = z;
// }


void Graph::addWeight(const V2D & playlist,int x, int y){
    int weight = edgeWeightAlgo(playlist, x, y);
    adjMat[x][y] = weight;
    adjMat[y][x] = weight;
}


void Graph::addEdge(int x, int y){
    adjMat[x][y]++;
    adjMat[y][x]++;
}
void Graph::nodes(const V2D & playlist){
    for (size_t i=0;i<playlist.size();i++){
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
    // Your code here!
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
        //std::cout << roster[i][roster[i].size()-1] << "}, \\" << std::endl;
    }
}

int Graph::edgeWeightAlgo(const V2D &playlist, int input1, int input2){
    for (size_t i=0; i<playlist.size()-1;i++){
        for (size_t j=1; j<playlist[i].size()-1;j++){
            AG[i][j-1]=playlist[i][j];
            //artist and genre
        }
    }
    // vector called first = ["song", "artist", "genre"]

    // [["song", "artist1", "genre"]
    //  ["song", "artist", "genre"]
    //  ["song", "artist", "genre"]
    // ]
    /*vector<string> first, second;
    for(int i = 0; i<AG.size(); i++){
        
        for(int j = 0; j<AG[i].size(); j++){
            if(i == input1){
                first.push_back(AG[i][j]);
            }
            if(i == input2){
                second.push_back(AG[i][j]);
            }
        }
    }
    int weight = 100;
    //if one of the songs don't exist, return no weight
    if(second.empty() || first.empty()){
        return weight;
    }
    //if artists are same, 70% similarity can be assumed
    else if(second[0] == first[0]){
        weight -= 70;
    }
    int idx = min(first.size(), second.size());
    //add 10% similarity for each shared artist
    for(int i=1; i<idx; i++){
        for (int j = 1; j<idx;j++){
            if(first[i] == second[j]){
                weight -=10;
            }       
        } 
    }
    if(weight<=0){
        return 5;
    }
    return weight;*/
    
    


    



    return 0;
}

int Graph::bfsUnweightedPath(unsigned int start, unsigned int end)    {

    // some tinkering was done here before i committed so it may segfault or return wrong values; i've mostly been focusing on
    // betweenness centrality for the time being.

        int retval = 0;
        if(start == end)    {
            return retval;
        }
        
        unsigned int size = songs.size();            
        cout << size << endl;               // this line exists because on my side of things the graph was not
                                            // always populating, resulting in out-of-bounds access errors when
                                            // checking visited. i have no idea why that is happening
        vector<bool> visited;
        for(unsigned i = 0; i < size; i++) {
            visited.push_back(false);
        }
        
        visited[start] = true;

        std::queue<unsigned int> BFS;
        BFS.push(start);

        while(!BFS.empty()) {               // while the queue is not empty, continue checking every nearest non-visited node
                                            // basically the bfs from the mp but intended to find a specific node
            int frontVertex = BFS.front();
            BFS.pop();
            retval++;   
            bool cant_travel_flag = true;  // used to check if any nodes can be travelled to from current location (defaults to true)
                                           // if false, retval is decremented and the traversal backtracks by one vertex 

            for(unsigned int i = 0; i <= size; i++)  {          // loops through all possible edge connections, checks if travel is possible
                                                                // also checks if the inputted destination ("end") is within reach, and if so, returns
                                                                // the number of edges taken to get there using BFS
                if((cant_travel_flag = true) && i == size) {

                    retval--;       // if travel is not possible and all possible edges have been searched, return to
                    continue;       // the previous vertex
                }
                else if (i == size)   {
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

    // pseudocode steps (this part is correct):

    // 1.) go through every vertex in the graph, using the adjacency matrix.

    // 2.) at each vertex, run dijkstra's algorithm (must account for weighted edges) on every other
    // vertex. count how many times the shortest path ends up crossing over the input vertex "song".

    // 3.) increment retval each time a shortest path contains index "song".
    // the return value represents how centrally located the inputted song is relative to the rest of the graph. a
    // high return value means many of the shortest paths between nodes cross over the inputted song.

    // the actual implementation i am not sure is correct. completely unsure if the correct value is returned since
    // manually checking shortest paths with the demofiles i've been working with is tedious. could use a smaller playlist

    for(unsigned i = 0; i < adjMat.size(); i++) {       // outer for loop, goes through every vertex


            // runs an altered version of dijkstra's algorithm that includes a check for the inputted song
            // finds the shortest path between a given node and ALL other nodes, if possible
            
            int*  distance = new int[numVertices]; // compares distances
            bool* visited = new bool[numVertices]; // contains visited nodes
            for(int k = 0; k < numVertices; k++)
                {
                    distance[k] = INT_MAX;
                    visited[k] = false;    
                }
    
            distance[i] = 0;   // Source vertex (i) distance is set 0               
    
            for(int k = 0; k < numVertices; k++)                           
                {
                    int m = miniDist(distance, visited); 
                    if(m == song)   {       // not sure about this part. this is where the return value is being incremented.
                                            // may have to use some other version of dijkstra's algorithm for this to work
                        retval += 1;
                    }
                    visited[m] = true;
                    for(int k = 0; k < numVertices; k++)                  
                        {
                            if(!visited[k] && adjMat[m][k] && distance[m] != INT_MAX && distance[m] + adjMat[m][k] < distance[k]) {
                                distance[k] = distance[m] + adjMat[m][k];
                        }
                    }
                }
            }
        return retval;  // betweenness centrality of the inputted vertex
    }   

void Graph::make(const V2D &playlist){

    nodes(playlist);
    for (unsigned i = 0; i < songs.size(); i++){
        for(unsigned j = i; j < songs.size(); j++){
            if (songs[i]==songs[j]){
                continue;
            }
            for (unsigned k = 1; k < playlist[i].size()-1; k++){
                for(unsigned t = 1; t < playlist[j].size()-1; t++){
                    if (playlist[i][k] == playlist[j][t]){
                        //int w=((stoi(popularity[i])+stoi(popularity[j]))/2)+1;
                        addWeight(playlist, i, k);
                    }
                }
            }
        }
    }   

}
void Graph::makeartist(const V2D &playlist){
    nodes(playlist);
    for (unsigned i = 0; i < songs.size(); i++){
        for(unsigned j = i; j < songs.size(); j++){
            if (i!=j){
                continue;
            }
            for (unsigned k = 1; k < 1; k++){
                for(unsigned t = 1; t < 1; t++){
                    //std::cout<<playlist[j][t]<<';';
                    //std::cout << playlist[i][k] + " - Second " << std::endl;
                    if (playlist[i][k] == playlist[j][t]){
                        addEdge(i,k);
                    }
                }
            }
        }
    }   
}


void Graph::hasCycle()
{
    //vector<bool> visited(numVertices,false);
    /*for (int i = 0; i < numVertices; i++)
        visited[i] = false;
 
    for (int u = 0; u < numVertices; u++) {
        if (!visited[u])
            if (dfs(u, visited))
                return true;
    }
    return false;*/
    //dfs(0,visited);
}
 

void Graph::printCycles(int& cyclenumber)
{
 
    // print all the vertex with same cycle
    for (int i = 0; i < cyclenumber; i++) {
        // Print the i-th cycle
        cout << "Cycle Number " << i + 1 << ": ";
        for (int x : adjMat[i])
            cout << x << " ";
        cout << endl;
    }
}




int Graph::miniDist(int distance[], bool Tset[]) // finding minimum distance
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
void Graph::DijkstraAlgo(int src) // adjacency matrix 
{
    int*  distance = new int[numVertices]; // // array to calculate the minimum distance for each node
    bool *Tset = new bool[numVertices];// boolean array to mark visited and unvisited for each node
    
     
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
    int width =75;
    cout<<"Vertex\t\t\t\t\t\t\t\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<numVertices; k++)                      
    { 
        //char str=65+k; 
        cout<<left<<setw(width)<<songs[k]<<
        setw(width)<<distance[k]<<endl;
    }
}