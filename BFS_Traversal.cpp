#include "BFS_Traversal.h"

bool BFS::search(Graph& graph, int id) {
    visited.resize(graph.getVertices().size());
    //edges = graph.getEdges();

    for (Vertex v : graph.getVertices()) {
        v->label = "UNEXPLORED";
    }

    for (Edge* e : graph.getEdgesByPointer()) {
        e->setLabel("UNEXPLORED");
    }

    for (Vertex v : graph.getVertices()) {
        if (v->label == "UNEXPLORED") {
            bool result = search(graph, v, id);
            if (result) {
                return result;
            }
        }
    }

    return false;
}

bool BFS::search(Graph& graph, Vertex v, int id) {
    queue<Vertex> q;
    v->label = "VISITED";
    q.push(v);

    while(!q.empty()) {
        v = q.front();
        q.pop();
        if (v->id == id) {
            return true;
        }
        for (Vertex w : graph.getAdjacent(v)) {
            if (w->label == "UNEXPLORED") {
                graph.setEdgeLabel(v, w, "DISCOVERY");
                w->label = "VISITED";
                
                q.push(w);
                
            } else if (graph.getEdgeLabel(v, w) == "UNEXPLORED") {
                graph.setEdgeLabel(v, w, "CROSS");
            }
            
        }
    }

    return false;
}