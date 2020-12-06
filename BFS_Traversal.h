#pragma once

#include <queue>
#include "edge.h"
#include "graph.h"

using std::queue;

class BFS {

    public:
        bool search(Graph& graph, int id);
        bool search(Graph& graph, Vertex v, int id);

    private:
        vector<bool> visited;
        vector<Edge> edges;
};