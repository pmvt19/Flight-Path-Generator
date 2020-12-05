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

    private:
        double cost(Edge u, Edge v);
        //bool Compare(pair<Vertex, int> pair1, pair<Vertex, int> pair2)

    class Compare {
        public:
            int operator()(const pair<Vertex, int> a, const pair<Vertex, int> b) {
                return a.second > b.second;
            }
    };
};


// Dijkstra(Graph, source, destination):

//   initialize distances  // initialize tentative distance value
//   initialize previous   // initialize a map that maps current node -> its previous node
//   initialize priority_queue   // initialize the priority queue
//   initialize visited

//   while the top of priority_queue is not destination:
//       get the current_node from priority_queue
//       for neighbor in current_node's neighbors and not in visited:
//           if update its neighbor's distances:
//               previous[neighbor] = current_node
//       save current_node into visited

//   extract path from previous
//   return path and distance