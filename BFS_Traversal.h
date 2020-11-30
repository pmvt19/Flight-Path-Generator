// YEET
#pragma once

#include <queue>
#include "edge.h"
#include "graph.h"

using std::queue;

class BFS {

    public:
        // BFS(Vertex vert, const Graph& graph);
        bool search(Graph& graph, int id);
        bool search(const Graph& graph, Vertex v, int id);


    private:
        vector<bool> visited;
        vector<Edge> edges;
        
        /*queue<Vertex> queue;
        Vertex startingPoint;
        Vertex currentPoint;
        const Graph* graph_;*/
};