# CS 225 Final Project

_See `Project Proposal.md` for project proposal details._

# C++ Instructions
Presumes running with cmake and make installed and ready to go; then, similarly to our in-class usage:

Setup: `mkdir c++/build && cd c++/build && cmake .. && make`

Run: `./main <filename>`. Provide the filename of a file produced by the Python section of the project (eg. `demofile*.txt`). 

Test: `./test`

Or, manually:
1. Make subdirectory of `c++/` for build output (eg. `c++/build`).
2. In that directory, run `cmake ..`
3. Compile using `make`, execute using `./main <filename>`, and test using `./test`

# Python Instructions
Requires Python 3 and pip.

1. `pip install -r requirements.txt`
2. Run `Python/spotify_data_getter.py` using Python

# Specific Testing Instructions
Assumes test executable exists:

Testing BFS: `./test "BFS"`.
Input to BFS test is a starting index and a destination index, inputted in that order. Returns, if available, the shortest unweighted path between start and end.

Testing Dijkstra's: `./test "Dijkstra's"`.
Input to Dijkstra's test is a starting index. The output will show, if available, the shortest path available to all other vertices (songs).

Testing Betweenness Centrality: `./test "Betweenness Centrality"`.
Input to Betweenness Centrality is the index of the song of interest. Returns the "centrality" of the inputted song index. The test case displays centrality for all songs.
