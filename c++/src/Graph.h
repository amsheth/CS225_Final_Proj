#pragma once

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

typedef std::vector<std::vector<std::string>> V2D;
class Graph{
    private:
        int numVertices;
        vector<vector<int>> adjMat;
        vector<string> songs;
        vector<string> popularity;
        int NO_PARENT = -1;
    public:
        Graph(const V2D & playlist);
        //~Graph();
        int introduction();
        void addEdge(int x, int y);
        void addWeight(int x, int y, int z);
        void nodes(const V2D & playlist);
        void make(const V2D & playlist);
        void displayMatrix();
        int bfsUnweightedPath(unsigned int start, unsigned int end);
        int BetweennessCentrality(int song);
        int miniDist(vector<int> distance, vector<bool>Tset);
        bool DijkstraAlgo(int src);
        void printSolution(int startVertex, vector<int> distances, vector<int> parents);
        void printDJK(vector<int> distance);

    int getNumVertices() const;

    const vector<vector<int>> &getAdjMat() const;

    const vector<string> &getSongs() const;

    const vector<string> &getPopularity() const;
};


V2D file_to_V2D(const std::string & filename);
void print(const V2D & playlist);
