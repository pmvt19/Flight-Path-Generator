#include <vector>
#include <iostream>
#include <unordered_map>

#include "graph.h"
#include "edge.h"
#include "vertex_parser.h"
#include "edge_parser.h"
#include "BFS_Traversal.h"
#include "dijkstra.h"

void test_case() {
  Graph graph(true, true);

  VertexParser parser;
  parser.OpenFile("data/test_airports.dat");
  vector<Airport*> airports = parser.GenerateVertices();
  unordered_map<int, Airport*> map;

  for (int i = 0; i < (int) airports.size(); i++) {
    if (!graph.vertexExists(airports.at(i))) {
      graph.insertVertex(airports.at(i));
      //map.insert(airports.at(i)->id, airports.at(i));
      map[airports.at(i)->id] = airports.at(i);
    }
  }

  EdgeParser edge_parser;
  edge_parser.OpenFile("data/test_routes.dat");
  edge_parser.CreateEdges(graph, map);

  std::cout << graph.getNumVertices() << std::endl;
  std::cout << "NUM OF AIRPORTS: " << airports.size() << std::endl;
  //std::cout << airports[3131]->name << std::endl;
  std::cout << map[3131]->name << std::endl;

  std::cout << "GRAPH EDGE TEST: " << graph.edgeExists(map[3830], map[3093]) << std::endl;
  std::cout << "GRAPH EDGE TEST: " << graph.edgeExists(map[3093], map[3131]) << std::endl;

  Dijkstra dijkstra;
  vector<Vertex> path = dijkstra.DijkstraSSSP(graph, map[3830], map[3131]);

  for (Vertex v : path) {
    std::cout << v->name << std::endl;
  }

}


int main() {
  
  Graph graph(true, true);

  VertexParser parser;
  parser.OpenFile("data/airports.dat");
  vector<Airport*> airports = parser.GenerateVertices();
  unordered_map<int, Airport*> map;

  for (int i = 0; i < (int) airports.size(); i++) {
    if (!graph.vertexExists(airports.at(i))) {
      graph.insertVertex(airports.at(i));
      //map.insert(airports.at(i)->id, airports.at(i));
      map[airports.at(i)->id] = airports.at(i);
    }
  }

  EdgeParser edge_parser;
  edge_parser.OpenFile("data/routes.dat");
  edge_parser.CreateEdges(graph, map);
  

  std::cout << graph.getNumVertices() << std::endl;
  std::cout << "NUM OF AIRPORTS: " << airports.size() << std::endl;
  std::cout << airports[7697]->name << std::endl;
  std::cout << map[4063]->name << std::endl;

  std::cout << graph.getEdgeWeight(map[3797], map[3670]) << std::endl;
  std::cout << "EDGE SHOULD EXIST: " << graph.edgeExists(map[3797], map[3670]) << std::endl;
  // std::cout << airports[2965]->name << std::endl;

  // BFS bfs;
  // std::cout << "BFS FIND: " << bfs.search(graph, 8853) << std::endl;

  // std::cout << graph.getEdgeWeight(map[1], map[2]) << std::endl;

  Dijkstra dijkstra; 
  vector<Vertex> path = dijkstra.DijkstraSSSP(graph, map[3830], map[5404]);
  int total_distance = 0;
  for (Vertex v : path) {
    std::cout << v->name << std::endl;
  }

  for (int i = 0; i < (int) path.size() - 1; i++) {
    total_distance += edge_parser.calculateDistance(path[i]->latitude, path[i]->longitude, path[i+1]->latitude, path[i + 1]->longitude);
  }

  std::cout << "TOTAL DISTANCE: " << total_distance << std::endl;
  
  

  // test_case();

  
  
  
  return 0;
}
