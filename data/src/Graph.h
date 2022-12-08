#include "utils.h"
#include <sstream>
#include <vector>
#include <fenv.h>
#include <signal.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <set>
#include <list>



using namespace std;
class Song{
    public:
        Song();
        string name;
        vector<string> genres;
        vector<string> artists;
        // 
        int popularity;
        
    
};
typedef std::vector<std::vector<std::string>> V2D;
class Graph{
    private:
        int numVertices;
        vector<vector<int>> adjMat;
        vector<string> songs;
    public:
        Graph(const V2D & playlist);
        void addEdge(int x, int y);
        void addWeight(int x, int y, int z);
        void nodes(const V2D & playlist);
        void make(const V2D & playlist);
        int edgeWeightAlgo(Song song1, Song song2);
        void displayMatrix();
};
V2D file_to_V2D(const std::string & filename);
void print(const V2D & playlist);




