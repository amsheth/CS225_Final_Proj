#include <catch2/catch_test_macros.hpp>

#include "../src/Graph.h"

TEST_CASE("Basic Test Cases"){
    std::vector<std::vector<std::string>> playlist = file_to_V2D("test/demofile1.txt");

    Graph g = Graph(playlist);

    REQUIRE(g.getAdjMat().size()==4);
}