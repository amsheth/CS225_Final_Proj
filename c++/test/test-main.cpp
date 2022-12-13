#include <catch2/catch_test_macros.hpp>

#include "../src/Graph.h"
#include "../src/utils.h"
#include <iostream>
#include <filesystem>


TEST_CASE("Basic Size Checks"){
    V2D playlist = file_to_V2D("../test/demofile1.txt");
    Graph g = Graph(playlist);
    REQUIRE(g.getNumVertices()==17);
    REQUIRE(g.getAdjMat().size()==17);
    REQUIRE(g.getSongs().size()==17);
}
TEST_CASE("Dijkstra's Algo"){
    V2D playlist = file_to_V2D("../test/demofile1.txt");
    Graph g = Graph(playlist);
    g.make(playlist);
    bool x=g.DijkstraAlgo(5);
    REQUIRE(x==true);
}


TEST_CASE("BFS - returns # edges in shortest path"){
    V2D playlist = file_to_V2D("../test/demofile1.txt");
    Graph g = Graph(playlist);
    g.make(playlist);
    int i, j;
    i = 0;
    j = g.getNumVertices()-6;
    cout << "TEST - BFS:" << endl << "There are " << j << " songs in the current graph. Please enter a starting index and an ending index (in this exact order and one at a time) from " << i << " and " << (j-1) << ": " << endl; 
    cin >> i;
    cin >> j;

    int bfs = g.bfsUnweightedPath(i, j);
    
    vector<string> songz = g.getSongs();
    if(bfs == -1)   {
        cout << "TEST - BFS Output: After thoroughly searching from the song '" << songz[i] << "', there was no genre similarity to song '" << songz[j] << "'." << endl;
    }
    else    {
        cout << "TEST - BFS Output: Genre similarity identified between song '" << songz[i] << "' and song '" << songz[j] << "'. " << "Number of genres jumped to get there: " << bfs << endl;
    }
    
    REQUIRE(g.bfsUnweightedPath(i, j) == bfs);
    }

TEST_CASE("Betweenness Centrality"){
    std::vector<std::vector<std::string>> playlist = file_to_V2D("../test/test-demofile-1.txt");

    Graph g = Graph(playlist);
    g.make(playlist);
    int l = g.BetweennessCentrality(4);
    REQUIRE(g.BetweennessCentrality(4) == l);

    }

