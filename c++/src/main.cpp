#include "Graph.h"
#include "utils.h"
#include <iostream>
#include <filesystem>

int main(int argc, char *argv[]) {
    // handle filename argument
    if (argc < 2) {
        std::cerr << "Please provide filename" << std::endl;
        return -1;
    } else if (argc > 2) {
        std::cerr << "Provide only the filename as argument" << std::endl;
        return -1;
    }
    char *filename = argv[1];

    V2D roster = file_to_V2D(filename);
    print(roster);
    std::cout << "Printing The Adjacency Matrix:" << std::endl;
    std::cout << std::endl;
    Graph abc(roster);
    abc.make(roster);
    std::cout << std::endl;
    abc.displayMatrix();
    std::cout << std::endl;
    int x = 3;
    std::cout << "Printing The Dijkstra's for node: " << x << std::endl;
    std::cout << std::endl;
    abc.DijkstraAlgo(x);
    std::cout << std::endl;
    int i = 3;
    int j = 2;
    vector<string> s = abc.getSongs();
    for (int i=0;i<17;i++){
        int val = abc.BetweennessCentrality(i);
        std::cout << val << " - Centrality of " << s[i] <<", determined by B.C. algorithm" << std::endl;
    }
    return 0;
}

