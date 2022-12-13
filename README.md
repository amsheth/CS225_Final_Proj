# CS 225 Final Project

_See `Project Proposal.md` for project proposal details._

_See `Writeup.md` for post-project reflection writeup._

_Click [here](https://drive.google.com/file/d/1vsuZ0zzodvpXu9hEAfivc_sRUAMWCmeo/view?usp=sharing) for the presentation video._

---

# C++ Instructions
Presumes running with cmake and make installed and ready to go; then, similarly to our in-class usage:

Setup: `mkdir c++/build && cd c++/build && cmake .. && make`

Run: `./main <filename>`. Provide the filename of a file produced by the Python section of the project (eg. `../../Python/demofile1.txt`). 

Test: `./test`

Or, manually:
1. Make subdirectory of `c++/` for build output (eg. `c++/build`).
2. In that directory, run `cmake ..`
3. Compile using `make`, execute using `./main <filename>` (path relative to `build`), and test using `./test`
Note that if the file is supplied incorrectly, a blank output may be returned.

# Python Instructions
Requires Python 3 and pip. A couple example files have been provided if you prefer not to use this step.

0. `apt-get update && apt-get install -y pip` to install Python and pip if needed.
1. `cd Python && pip install -r requirements.txt`
2. Remain in the Python folder and run `python interactive_data_getter.py` or `python3 interactive_data_getter.py` depending on your install. Supply a filename of your choice and a Spotify playlist ID, or use the defaults (but that's boring).

# Specific Testing Instructions
Assumes test executable exists:

Testing BFS: `./test "BFS"`. 
Input to BFS test is a starting index and a destination index, inputted in that order. Returns, if available, the shortest unweighted path between start and end.

Testing Dijkstra's: `./test "Dijkstra's"`. 
Input to Dijkstra's test is a starting index. The output will show, if available, the shortest path available to all other vertices (songs).

Testing Betweenness Centrality: `./test "Betweenness Centrality"`. 
Input to Betweenness Centrality is the index of the song of interest. Returns the "centrality" of the inputted song index. The test case displays centrality for all songs.
