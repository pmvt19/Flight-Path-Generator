#include "landmark_path.h"

vector<Vertex> Landmark::findLandmarkPath(Graph& graph, vector<Vertex> airports) {
    Dijkstra dijkstra;
    vector<Vertex> path;
    for (unsigned int i = 0; i < airports.size() - 1; i++) {
        vector<Vertex> segment = dijkstra.DijkstraSSSP(graph, airports[i], airports[i + 1]);
        path.insert(path.end(), segment.begin(), segment.end());
        //vector<Vertex> DijkstraSSSP(Graph& graph, Vertex s, Vertex d);
    }
    return path;
}