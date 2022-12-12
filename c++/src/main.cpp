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
    std::cout<<filesystem::current_path()<<std::endl;
    char *filename = argv[1];

    std::cout << "Printing The Demofile:" << std::endl;
    //Graph myGraph("rosterList.txt", "studentList.txt");

    V2D roster = file_to_V2D("../../Python/demofile1.txt");
    print(roster);
    std::cout << "Printing The Adjacency Matrix:" << std::endl;
    std::cout << std::endl;
    Graph abc(roster);
    abc.make(roster);
    abc.displayMatrix();
    std::cout << std::endl;
    abc.displayMatrix();
    std::cout << std::endl;
    //abc.hasCycle();
    int x = 3;
    std::cout << "Printing The Dijkstra's for node: " << x << std::endl;
    std::cout << std::endl;
    abc.DijkstraAlgo(x);
    std::cout << std::endl;
    int i = 5;
    int j = 4;
    //int val = abc.bfsUnweightedPath(i, j);
    //std::cout << val << " - The BFS Unweighted Path between points " <<i<<" & "<<j<< std::endl;
    int val = abc.BetweennessCentrality(2);
    std::cout << val << " - Centrality of inputted song, determined by B.C. algorithm" << std::endl;

    return 0;
}

