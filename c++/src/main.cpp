#include "Graph.h"
#include <iostream>

int main() {
    //std::cout << "Hello, mp_schedule!" << std::endl;

    //Graph myGraph("rosterList.txt", "studentList.txt");

    
    V2D roster = file_to_V2D("../PY/demofile1.txt");
    //print(roster);
    Graph abc(roster);
    abc.makeartist(roster);
    abc.displayMatrix();
    bool res;
    res = abc.hasCycle();
    if(res)
        std::cout << "The graph has cycle." << std::endl;
    else
        std::cout << "The graph has no cycle." << std::endl;
    

}
