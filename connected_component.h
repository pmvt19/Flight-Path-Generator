#pragma once


#include <queue>
#include <fstream>
#include <iostream>
#include "edge.h"
#include "graph.h"

using namespace std;


class ConnectedComponents {

    private:
        vector<int> elems;
    public:
        void addelements(int num);

        int find(int elem);

        void setunion(int a, int b);

        void calculateConnectedComponents(unordered_map<int, Airport*>& map);
};