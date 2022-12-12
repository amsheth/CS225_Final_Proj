#include "Graph.h"
#include "utils.h"
#include <iostream>

int main() {
    std::cout << "Printing The Demofile:" << std::endl;

    //Graph myGraph("rosterList.txt", "studentList.txt");

    
    V2D roster = file_to_V2D("../../Python/demofile1.txt");
    print(roster);
    std::cout << "Printing The Adjacency Matrix:" << std::endl;
    std::cout<<std::endl;
    Graph abc(roster);
    abc.make(roster);
    abc.displayMatrix();
    std::cout<<std::endl;
    //abc.hasCycle();
    int x=3;
    std::cout << "Printing The Dijkstra's for node: " <<x<< std::endl;
    std::cout<<std::endl;
    abc.DijkstraAlgo(x);
    std::cout<<std::endl;
    int i=5; int j=4;
    //int val = abc.bfsUnweightedPath(i, j);
    //std::cout << val << " - The BFS Unweighted Path between points " <<i<<" & "<<j<< std::endl;
    int val = abc.BetweennessCentrality(2);
    std::cout << val << " - BC" << std::endl;
}

