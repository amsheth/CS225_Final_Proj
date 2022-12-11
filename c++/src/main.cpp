#include "Graph.h"
#include "utils.h"
#include <iostream>

int main() {
    //std::cout << "Hello, mp_schedule!" << std::endl;

    //Graph myGraph("rosterList.txt", "studentList.txt");

    
    V2D roster = file_to_V2D("../Python/demofile1.txt");
    //print(roster);
    Graph abc(roster);
    abc.make(roster);
    //abc.displayMatrix();
    //abc.hasCycle();
    abc.DijkstraAlgo(3);


}
