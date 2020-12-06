#pragma once

#include <queue>
#include "edge.h"
#include "graph.h"
#include "dijkstra.h"


class Landmark {
    public:
        vector<Vertex> findLandmarkPath(Graph& graph, vector<Vertex> airports);
};