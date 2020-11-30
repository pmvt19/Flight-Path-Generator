#include "BFS_Traversal.h"

bool BFS::search(Graph& graph, int id) {
    visited.resize(graph.getVertices().size());
    edges = graph.getEdges();

    for (Edge e : edges) {
        e.setLabel("UNEXPLORED");
    }

    for (int i = 0; i < (int) graph.getVertices().size(); i++) {
        if (!visited[i]) {
            bool result = search(graph, graph.getVertices().at(i), id);
            
            if (result) {
                return result;
            }

        }
    }

    return false;
}

bool BFS::search(const Graph& graph, Vertex v, int id) {
    queue<Vertex> q;
    
}