#include <vector>
#include <iostream>
#include <unordered_map>

#include "graph.h"
#include "edge.h"
#include "vertex_parser.h"
#include "edge_parser.h"

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

  std::cout << "EDGE SHOULD EXIST: " << graph.edgeExists(map[12087], map[3131]) << std::endl; 
  // std::cout << airports[2965]->name << std::endl;
  return 0;
}
