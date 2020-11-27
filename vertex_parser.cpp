#include "vertex_parser.h"


bool VertexParser::OpenFile(const string& file_path) {
    file.close();
    file.open(file_path);
    return file.is_open();
}

vector<Airport*> VertexParser::GenerateVertices() {
    vector<Airport*> airports;

    string line;
    int j = 0;
    while(getline(file, line)) {

        stringstream s_stream(line);
        vector<string> results;
        while(s_stream.good()) {
            string sub;
            getline(s_stream, sub, ',');
            results.push_back(sub);
            std::cout << sub << std::endl;
        }
        std::cout << "RESULTS SIZE: " << results.size() << std::endl;
        //std::cout << line << std::endl;
        Airport* airport = new Airport();
        airport->id = stoi(results.at(0));
        airport->name = results.at(1);
        airport->city = results.at(2);
        airport->country = results.at(3);
        airport->IATA = results.at(4);
        airport->ICAO = results.at(5);
        airport->latitude = stod(results.at(6));
        airport->longitude = stod(results.at(7));
        airport->altitude = stod(results.at(8));
        airport->time_zone = stod(results.at(9));
        airport->DST = results.at(10);
        airport->TZ_database_time = results.at(11);
        airport->type = results.at(12);
        airport->source = results.at(13);

        /*for (int i = 0; i < (int) results.size(); i++) {
            
        
        }*/
        airports.push_back(airport);
    }


    //vector<string> row;

    /*string line;
    getline(file, line);
    stringstream s(line);
    string word;

    while (getline(s, word, ', ')) { 

        // add all the column data 
        // of a row to a vector 
        row.push_back(word); 
    }*/

    /*while (getline(file, line)) {
        
    }*/



    /*for (int i = 0; i < 10; i++) {
        //std::cout << file.getline() << std::endl;
        string line;
        getline(file, line);

        std::cout << line << std::endl;
    }*/


    return airports;
}