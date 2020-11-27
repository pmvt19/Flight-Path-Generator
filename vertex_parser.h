#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "airport.h"

using std::string;
using std::ifstream;
using std::vector;


class VertexParser {
    private:
        ifstream file;

    public:
        bool OpenFile(const string& file_path);
        vector<Airport> GenerateVertices();
};