//
//  main.cpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#include "ListGraph.hpp"
#include "DijkstraAlgorithm.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

int main(int argc, const char * argv[])
{
    if (argc >= 1) {
        std::stringstream os;
        
        os << argv[1];
        unsigned int vertices;
        os >> vertices;
        
        if (vertices > 0) {
            std::cout << "Generating graph with " << vertices << " vertices." << std::endl;
            
            srand((unsigned int) time(NULL));
            
            //int from = rand() % vertices;
            int from = 0;
            int to = rand() % vertices;
            
            ListGraph graph(vertices);
            
            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    if (j != i) {
                        int weight = rand() % 1000;
                        graph.addEdge(i, j, weight);
                    }
                }
            }
            
            assert(graph.V() == vertices);
            
            std::cout << "calculating path from " << from << " to " << to << std::endl;

            DijkstraAlgorithm pfinder(graph);
            auto path = pfinder.find(from, to);
            
            while (!path.empty()) {
                std::cout << path.top() << std::endl;
                path.pop();
            }
        } else {
            std::cerr << "error: graph can't be empty!" << std::endl;
        }
    } else {
        std::cerr << "usage: " << argv[0] << " number-of-vertices" << std::endl;
    }
    
    return 0;
}

