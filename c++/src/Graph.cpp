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


using namespace std;

Graph::Graph(const V2D & playlist){
    numVertices=playlist.size();
    //vector<vector<int>> adjMat= new vector<vector<int>>;
    adjMat.resize(numVertices);
    for (unsigned i = 0; i < playlist.size(); i++){
        adjMat.push_back(std::vector<int>(playlist.size(), 0));
    }
    //nodes(playlist);
}
void Graph::addWeight(int x, int y, int z){
    adjMat[x][y] = z;
    adjMat[y][x] = z;
}
void Graph::addEdge(int x, int y){
    adjMat[x][y] = 1;
    adjMat[y][x] = 1;
}
void Graph::nodes(const V2D & playlist){
    for (int i=0;i<playlist.size();i++){
        std::cout << playlist[i][0] << std::endl;
        songs.push_back(playlist[i][0]);
    }
}
void Graph::displayMatrix() {
   size_t i, j;
   for(i = 0; i < adjMat.size(); i++) {
      for(j = 0; j < adjMat[i].size(); j++) {
         std::cout << adjMat[i][j] << "   ";
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

void Graph::make(const V2D & playlist){
    nodes(playlist);
    for (unsigned i = 0; i < songs.size(); i++){
        for(unsigned j = i; j < songs.size(); j++){
            if (playlist[j][0] == playlist[i][0]){
                continue;
            }
            for (unsigned k = 1; k < playlist[i].size(); k++){
                for(unsigned l = 1; l < playlist[i].size(); l++){
                    if (playlist[i][k] == playlist[j][l]){
                        adjMat[i][j] = 1;
                        adjMat[j][i] = 1;
                    }
                }
            }
        }
    }

}

