#include <vector>
#include <iostream>

#include "graph.h"
#include "edge.h"
#include "vertex_parser.h"

int main() {
  VertexParser parser;

  parser.OpenFile("data/airports.dat");
  vector<Airport*> airports = parser.GenerateVertices();

  std::cout << airports[0]->name << std::endl;
  return 0;
}
