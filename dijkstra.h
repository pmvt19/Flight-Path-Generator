// YEET
#pragma once

#include <queue>
#include "edge.h"
#include "graph.h"

using std::queue;
using std::priority_queue;

class Dijkstra {
    public:
        void DijkstraSSSP(Graph& graph, Vertex s);
        vector<Vertex> DijkstraSSSP(Graph& graph, Vertex s, Vertex d);

    class Compare {
        public:
            int operator()(const pair<Vertex, int> a, const pair<Vertex, int> b) {
                return a.second > b.second;
            }
    };
};