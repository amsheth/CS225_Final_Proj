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

    /**
     * runs a BFS search between two nodes in the graph
     * @param start starting node
     * @param end ending node
     * @return length between nodes
     */
    int bfsUnweightedPath(unsigned int start, unsigned int end);

    /**
     * runs the betweenness centrality analysis
     * @param song node to check
     * @return number of times the song was in a shortest path
     */
    int BetweennessCentrality(int song);

    /**
     * finds minimum distance between two node
     * @param distance saves into this
     * @param Tset whether the node has been visited
     * @return minimum distance
     */
    int miniDist(vector<int> distance, vector<bool>Tset);

    /**
     * Dijkstra's algorithm -- prints shortest path
     * @param src starting node
     * @return success or not
     */
    bool DijkstraAlgo(int src);

    /**
     * helper function for DijkstraAlgo() to print the output
     * @param distance output to print
     */
    void printDJK(vector<int> distance);

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

/**
 * creates a V2D from a file (in our modified format)
 * @param filename file to read in
 * @return the newly created V2D
 */
V2D file_to_V2D(const std::string &filename);

/**
 * prints a V2D
 * @param playlist V2D to print
 */
void print(const V2D &playlist);
