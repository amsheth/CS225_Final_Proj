#include "graph.h"
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


using namespace std;

Graph::Graph(const V2D & playlist){
    numVertices=playlist.size();
    //vector<vector<int>> adjMat= new vector<vector<int>>;
    adjMat.resize(numVertices-1);
    for (unsigned i = 0; i < playlist.size()-1; i++){
        adjMat[i].resize(numVertices-1);
        for (int j=0;j<numVertices-1;j++){
            adjMat[i][j]=0;
        }
        //adjMat.push_back(std::vector<int>(playlist.size(), 0));
    }
    //nodes(playlist);
}

void Graph::addWeight(int x, int y, int z){
    adjMat[x][y] = z;
    adjMat[y][x] = z;
}
void Graph::addEdge(int x, int y){
    adjMat[x][y]++;
    adjMat[y][x]++;
}
void Graph::nodes(const V2D & playlist){
    for (int i=0;i<playlist.size();i++){
        //std::cout << playlist[i][0] << std::endl;
        songs.push_back(playlist[i][0]);
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
        std::cout << playlist[i][j] << "; ";
        }
        std::cout<<"\n";
        //std::cout << roster[i][roster[i].size()-1] << "}, \\" << std::endl;
    }
}

void Graph::make(const V2D &playlist){
    nodes(playlist);
    for (unsigned i = 0; i < songs.size(); i++){
        for(unsigned j = i; j < songs.size(); j++){
            if (i!=j){
                continue;
            }
            for (unsigned k = 1; k < playlist[i].size()-1; k++){
                for(unsigned t = 1; t < playlist[j].size()-1; t++){
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

bool Graph::dfs(int vertex, set<int>&visited, int parent) {
   visited.insert(vertex);
   for(int v = 0; v<numVertices; v++) {
      if(adjMat[vertex][v]) {
         if(v == parent)    
         if(visited.find(v) != visited.end())
            std::cout<<songs[v]<<std::endl;
            return true;
         if(dfs(v++, visited, vertex))
            std::cout<<songs[v]<<std::endl;
            return true;
      }
   }
   return false;
}
bool Graph::hasCycle() {
   set<int> visited; 
   for(int v = 0; v<numVertices; v++) {
      std::cout<<songs[v]<<std::endl;
      if(visited.find(v) != visited.end())
        continue;
      if(dfs(v, visited, -1)) {        
        return true;
      }
   }
   return false;
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