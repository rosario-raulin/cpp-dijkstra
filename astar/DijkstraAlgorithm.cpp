//
//  DijkstraAlgorithm.cpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#include "DijkstraAlgorithm.hpp"

#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <functional>

DijkstraAlgorithm::DijkstraAlgorithm(IGraph* graph) : _graph(graph), _distances(new double[_graph->V()]) {}

DijkstraAlgorithm::~DijkstraAlgorithm() {
    delete [] _distances;
}

DijkstraAlgorithm::DijkstraAlgorithm(const DijkstraAlgorithm& other) : _graph(other._graph), _distances(new double[_graph->V()]) {
    for (int i = 0; i < _graph->V(); ++i) {
        _distances[i] = other._distances[i];
    }
}

bool
DijkstraAlgorithm::compare(const int& x, const int& y) const {
    return _distances[x] < _distances[y];
}

std::stack<int>
DijkstraAlgorithm::find(int from, int to) const {
    int prev[_graph->V()];
    
    for (int i = 0; i < _graph->V(); ++i) {
        _distances[i] = INFINITY;
    }
    _distances[from] = 0;
    
    std::vector<int> open;
    open.push_back(from);

    while (!open.empty()) {
        auto fn = std::bind(&DijkstraAlgorithm::compare, this, std::placeholders::_1, std::placeholders::_2);
        
        std::make_heap(open.begin(), open.end(), fn);
        
        int curr = open[0];
        open.erase(open.begin());
        
        std::vector<Edge> adj = _graph->adj(curr);
        for (auto it = adj.begin(); it != adj.end(); ++it) {
            int next = (*it).to();
            if (_distances[next] > _distances[curr] + (*it).weight()) {
                _distances[next] = _distances[curr] + (*it).weight();
                prev[next] = curr;
                
                auto x = std::find(open.begin(), open.end(), next);
                if (x == open.end()) {
                    open.push_back(next);
                }
            }
        }
    }
    
    std::stack<int> out;
    int curr = to;
    while (curr != from) {
        out.push(curr);
        curr = prev[curr];
    }
    
    return out;
}