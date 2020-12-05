#include "dijkstra.h"
#include <map>
#include <iostream>

void Dijkstra::DijkstraSSSP(Graph& graph, Vertex s) {
    return;
}

// bool Dijkstra::Compare(pair<Vertex, int> pair1, pair<Vertex, int> pair2) {
//     return pair1.second < pair2.second;
// }

vector<Vertex> Dijkstra::DijkstraSSSP(Graph& graph, Vertex s, Vertex d) {
    unordered_map<Vertex, double> distances;
    unordered_map<Vertex, Vertex> previous;
    //priority_queue<Vertex> q;
    priority_queue<pair<Vertex, double>, vector<pair<Vertex, double>>, Compare> pq;
    //priority_queue<pair<Vertex, int>> pq;
    unordered_map<Vertex, bool> visited;

    for (Vertex v : graph.getVertices()) {
        
        //q.push(v);
        /*if (v->name == s->name) {
            pair<Vertex, int> data = make_pair(v, 0);
            pq.push(data);
        } else {
            pair<Vertex, int> data = make_pair(v, INFINITY);
            pq.push(data);
        }*/

        distances[v] = 20090;
        previous[v] = NULL;
        visited[v] = false;
    }
    distances[s] = 0;
    pq.push(make_pair(s, 0));

    // Vertex current = q.top();
    
    // while(!q.empty() && current != d) {
    //     current = q.top();

    //     for (Vertex adj : graph.getAdjacent(current)) {
    //         Edge edge = graph.getEdge(current, adj);
    //         int newDistance = edge.getWeight() + distances[current];
    //         if (newDistance < distances[adj]) {
    //             distances[adj] = newDistance;
    //             previous[adj] = current;
    //         }
    //     }

    //     q.pop();
    //     visited[current] = true;
    // }

    // std::cout << "OVERHERE: " << pq.top().first->IATA << std::endl;
    

    pair<Vertex, double> curr = pq.top();
    while (!pq.empty() && curr.first != d) {
        curr = pq.top();
        curr.second = distances[curr.first];
        //std::cout << curr.first->name << " :WHILE" << std::endl;
        int i = 0;
        for (Vertex adj : graph.getAdjacent(curr.first)) {
            std::cout << curr.first->IATA << " :ADJ " << i++ << std::endl;
            //std::cout << adj->IATA << " :ADJ " << i++ << std::endl;
            if (visited[adj]) {
                continue;
            }
            Edge edge = graph.getEdge(curr.first, adj);
            double newDistance = edge.getWeight() + distances[curr.first];
            std::cout << "NEW DISTANCE: " << newDistance << std::endl;
            std::cout << "OLD DISTANCE: " << distances[adj] << std::endl;
            // pq.push(make_pair(adj, newDistance));
            if (newDistance < distances[adj]) {
                pq.push(make_pair(adj, newDistance));
                //std::cout << "ENTERED" << std::endl;
                distances[adj] = newDistance;
                previous[adj] = curr.first;
            }
        }
        
        pq.pop();
        visited[curr.first] = true;
    }

    // for (auto it = previous.begin(); it != previous.end(); ++it) {
    //     if (it->first->IATA == "\"ORD\"") {
    //         std::cout << "HELLO: " << it->second->IATA  << endl;
    //         break;
    //     }
    // }

    Vertex current = d;
    vector<Vertex> path;
    path.insert(path.begin(), d);
    int i = 0;
    bool pathExists = true;
    while (current != NULL && current != s) {
        //std::cout << "HOW YOU ENTER" << std::endl;
        //std::cout << current->IATA << " :FOR " << i++ << std::endl;
        path.insert(path.begin(), previous[current]);
        //std::cout << current->IATA << " :FOR " << i << std::endl;
        std::cout << current << " :WHILE " << i++ << std::endl;
        current = previous[current];
        if (current == NULL) {
            pathExists = false;
        }
        //std::cout << current << " :KEVIN " << i << std::endl;
        //std::cout << current->IATA << " :FOR " << i++ << std::endl;
        //std::cout << current->id << " :FOR" << std::endl;
    }

    if (!pathExists) {
        path.clear();
    }

    return path;
}

double Dijkstra::cost(Edge u, Edge v) {
    return 0.0;
}


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