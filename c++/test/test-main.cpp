#include <catch2/catch_test_macros.hpp>

#include "../src/Graph.h"

TEST_CASE("Basic Size Checks"){
    std::vector<std::vector<std::string>> playlist = file_to_V2D("../test/test-demofile-1.txt");

    Graph g = Graph(playlist);

    REQUIRE(g.getNumVertices()==4);
    REQUIRE(g.getAdjMat().size()==4);
    REQUIRE(g.getSongs().size()==4);
}