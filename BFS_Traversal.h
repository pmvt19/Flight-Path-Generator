#pragma once

#include <queue>
#include "edge.h"
#include "graph.h"

using std::queue;

class BFS {

    public:
    
        /**
         * @param graph - Graph to perfrom BFS on
         * @param id - Id of the airport to find
         * @return - True if vertex if found; False otherwise
         */ 
        bool search(Graph& graph, int id);

        /**
         * @param graph - Graph to perfrom BFS on
         * @param v - Vertex to explore adjacent edges on
         * @param id - Id of the airport to find
         * @return - True if vertex if found; False otherwise
         */ 
        bool search(Graph& graph, Vertex v, int id);

    private:
        vector<bool> visited;
        vector<Edge> edges;
};