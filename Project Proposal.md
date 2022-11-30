# CS225_Final_Proj
## Leading Question 
How can we visualize Spotify data? We want to create a graph that organizes Spotify data in a way that gives insight to how albums are linked between artists and/or users. Spotify has a popular API for developers that returns data for artists, albums, and individual songs - we will be using this data in our graph to create connections between artists and/or users. Number of liked songs, collaborative albums, user playlists, etc. can be pulled using the API and may be used to help create our graph. 

The primary graph traversal algorithm that we use (likely BFS) will find the shortest path between a pair of vertices in the graph, which will convey some kind of relation between the two objects. We may use another shortest-path algorithm (Dijkstra's) if we implement our graph with weighted edges. Lastly, we also want to explore betweenness centrality by determining how much "info" travels through a given node on the graph - that node may be an artist, an album, a song, or something else. 
## Dataset Acquisition
We are using Spotify's public API and planning on pulling data using a Python script. 
## Data Format
Data will be received as a list of JSON objects with identifiers for artist names, songs, genres, and albums and we will be formatting it and unpacking it to put it into a data structure. We don't plan to use all of the identifiers of the JSON object; we will be only using the genre and song name as identifiers in our algorithm. 
## Data Correction
For the actual pulling of the data, we think we can run a Python script to retrieve data. As for error prevention, Spotify's API has several checks that will output error messages in the case of holes. It looks like the API is very convenient for error *prevention*. For example - error 404:

"Not Found - The requested resource could not be found. This error can be due to a temporary or permanent condition."

If an error like this arises, we will simply pull data somewhere else. There are vast amounts of artists, albums, and songs on spotify that we can use. If data is missing from one song in an album, then we can probably afford to look elsewhere for data.
## Data Storage
We will probably store the info from our dataset into an adjacency list, which itself will represent our graph. This should have a space complexity of O(V+E), where V represents vertexes and E represents edges.
## Algorithm 
The primary algorithms we will use are BFS for general traversal and dijkstra's algorithm (both would serve the same purpose, which is finding the shortest path between vertices). For example, if we have artists as nodes and genres as edges (if we can find a way to represent that info) we can compare similarities in the artist's style. 

Our third algorithm will be the Betweenness Algorithm where we can measure the centrality of the graph based on the shortest paths. This Algorithm can help us find the most important node in the graph. Lets assume that a node is a genre and the edges are the famous songs which merge genres. We can use this algorithm to find our which node(genre) is the most important. It could give us the relation between that genre and development of music (This is a tentative idea where it depends on how the Spotify API gives the info).

The target time complexity for all of these algorithms is ideally O(V), where V represents vertices. With each additional step in these algorithms, one more vertex is traversed in each call. 

The space complexity for all algorithms should be O(n), where n represents the total number of vertices in the graph. All algorithms should require the full graph in order to traverse or identify the shortest path properly.
## Timeline
Tasks:
For 1st Part:

1.) Set up API file I/O through preferably a python script

2.) We have to make the makefile.

3.) Get the data sorted and setup in the program.

4) Create a Psuedocode and figure out which identifier acts as the best node and which identifier acts as the best edge.

For the 2nd part:

1) Finish the writing the algorithms

2) Debuggging the code to get the right values.

3) Testing the code multiples times

4) Createing a user interface

5) Last but not the Least Submitting the Code.
