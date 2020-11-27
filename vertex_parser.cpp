#include "vertex_parser.h"


bool VertexParser::OpenFile(const string& file_path) {
    file.close();
    file.open(file_path);
    return file.is_open();
}

vector<Airport> VertexParser::GenerateVertices() {
    vector<Airport> airports;

    for (int i = 0; i < 10; i++) {
        //std::cout << file.getline() << std::endl;
        string line;
        getline(file, line);

        std::cout << line << std::endl;
    }


    return airports;
}