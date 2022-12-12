# CS 225 Final Project

_See `Project Proposal.md` for project proposal details._

# C++ Instructions
Presumes running with cmake and make installed and ready to go; then, similarly to our in-class usage:

Setup: `mkdir c++/build && cd c++/build && cmake .. && make`

Run: `./main <filename>`. Provide the filename of a file produced by the Python section of the project (eg. `demofile*.txt`). 

Or, manually:
1. Make subdirectory of `c++/` for build output (eg. `c++/build`).
2. In that directory, run `cmake ..`
3. Compile using `make` and execute using `./main <filename>` 

# Python Instructions
Requires Python 3 and pip.

1. `pip install -r requirements.txt`
2. Run `Python/spotify_data_getter.py` using Python