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
#include <stack>

int main(int argc, const char * argv[])
{
    ListGraph graph(6);
    
    graph.addEdge(0, 1, 10.0);
    graph.addEdge(0, 2, 5.0);
    graph.addEdge(1, 3, 5.0);
    graph.addEdge(2, 4, 3.0);
    graph.addEdge(3, 5, 5.0);
    graph.addEdge(4, 3, 3.0);
    graph.addEdge(4, 5, 20.0);
    
    DijkstraAlgorithm pfinder(&graph);
    
    std::stack<int> path = pfinder.find(0, 5);

    while (!path.empty()) {
        int next = path.top();
        path.pop();
        std::cout << next << std::endl;
    }
    
    return 0;
}

