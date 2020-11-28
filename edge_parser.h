#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include "airport.h"
#include "graph.h"


using std::string;
using std::ifstream;
using std::vector;
using std::stringstream;


class EdgeParser {
    private:
        ifstream file;

    public:
        bool OpenFile(const string& file_path);
        void CreateEdges(Graph& graph, const unordered_map<int, Airport*> map);
        double calculateDistance(double lat1, double long1, double lat2, double long2);
};