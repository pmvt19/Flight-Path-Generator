#include <vector>
#include <iostream>

#include "graph.h"
#include "edge.h"
#include "vertex_parser.h"

int main() {
  VertexParser parser;
  
  parser.OpenFile("data/airports.dat");
  parser.GenerateVertices();

  std::cout << "HELLO" << std::endl;
  return 0;
}
