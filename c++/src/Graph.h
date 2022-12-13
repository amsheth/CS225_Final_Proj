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

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMat;
    vector<string> songs;
    vector<string> popularity;
    int NO_PARENT = -1;

public:

    /**
     * Creates a new Graph object.
     * @param playlist playlist to build the graph out of
     */
    Graph(const V2D &playlist);

    int introduction();

    /**
     * adds edge between two nodes in the graph
     * @param x node to connect
     * @param y node to connect to
     */
    void addEdge(int x, int y);

    /**
     * adds weighting
     * @param x first node
     * @param y second node
     * @param value weight value to set
     */
    void addWeight(int x, int y, int value);

    /**
     * populates vectors
     * @param playlist playlist provided to the graph
     */
    void nodes(const V2D &playlist);

    /**
     * populates the graph
     * @param playlist playlist provided to the graph
     */
    void make(const V2D &playlist);

    /**
     * outputs to stdout matrix
     */
    void displayMatrix();


    int bfsUnweightedPath(unsigned int start, unsigned int end);

    int BetweennessCentrality(int song);

    int miniDist(int dist[], bool sptSet[]);

    bool DijkstraAlgo(int src);

    void printDJK(int *distance);

    /**
     * returns the number of vertices in the graph
     * @return number of vertices in the graph
     */
    int getNumVertices() const;

    /**
     * returns the adjacency matrix
     * @return the adjacency matrix
     */
    const vector<vector<int>> &getAdjMat() const;

    /**
     * returns the songs vector
     * @return the songs vector
     */
    const vector<string> &getSongs() const;

};

V2D file_to_V2D(const std::string &filename);

void print(const V2D &playlist);
