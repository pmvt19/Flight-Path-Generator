#include "edge_parser.h"

bool EdgeParser::OpenFile(const string& file_path) {
    file.close();
    file.open(file_path);
    return file.is_open();
}

void EdgeParser::CreateEdges(Graph& graph, const unordered_map<int, Airport*> map) {
    string line;

    while(getline(file, line)) {
        stringstream s_stream(line);
        vector<string> results;
        while(s_stream.good()) {
            string sub;
            getline(s_stream, sub, ',');
            results.push_back(sub);
        }

        if (results.at(3) == "\\N" || results.at(5) == "\\N") {
            continue;
        }
        
        if (map.find(stoi(results.at(3))) == map.end() || map.find(stoi(results.at(5))) == map.end()) {
            continue;
        }

        Airport* firstAirport = map.at(stoi(results.at(3)));
        Airport* secondAirport = map.at(stoi(results.at(5)));

        if (!graph.edgeExists(firstAirport, secondAirport)) {
            graph.insertEdge(firstAirport, secondAirport);
            graph.setEdgeWeight(firstAirport, secondAirport, calculateDistance(firstAirport->latitude, firstAirport->longitude, secondAirport->latitude, secondAirport->longitude));
        }
    }
}

double EdgeParser::calculateDistance(double lat1, double long1, double lat2, double long2) {
    return 0.0;
}