#include <catch2/catch_test_macros.hpp>

#include "../src/Graph.h"

TEST_CASE("Test Case 1"){
    V2D playlist = file_to_V2D("../Python/demofile1.txt");

    Graph g = Graph(playlist);

    int x = 0;
    REQUIRE(x==1);
}