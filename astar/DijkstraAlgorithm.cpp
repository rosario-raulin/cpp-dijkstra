//
//  DijkstraAlgorithm.cpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#include "DijkstraAlgorithm.hpp"
#include "BinaryHeap.hpp"

#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <functional>

//#include <iostream>

DijkstraAlgorithm::DijkstraAlgorithm(std::shared_ptr<IGraph> graph) : _graph(graph), _distances(new double[_graph->V()]) {}

DijkstraAlgorithm::~DijkstraAlgorithm() {
    _distances.reset();
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

std::shared_ptr<std::stack<int> >
DijkstraAlgorithm::find(int from, int to) const {
    
    int prev[_graph->V()];
    int pos[_graph->V()];
    
    for (int i = 0; i < _graph->V(); ++i) {
        _distances[i] = INFINITY;
        pos[i] = 0;
        prev[i] = -1;
    }
    _distances[from] = 0;

    auto fn = std::bind(&DijkstraAlgorithm::compare, this, std::placeholders::_1, std::placeholders::_2);
    BinaryHeap<int, std::function<bool(const int&, const int&)>> open(_graph->V(), fn);
    pos[from] = open.insert(from);

    size_t decreaseKey = 0;
    size_t iterations = 0;
    while (!open.empty()) {
        ++iterations;
        int curr = open.extractMin();
        
        std::vector<Edge>* adj = _graph->adj(curr);
        for (auto it = adj->begin(); it != adj->end(); ++it) {
            int next = (*it).to();
            if (_distances[next] > _distances[curr] + (*it).weight()) {
                _distances[next] = _distances[curr] + (*it).weight();
                prev[next] = curr;
                
                if (pos[next] > 0 && open.contains(pos[next])) {
                    ++decreaseKey;
                    open.decreaseKey(pos[next], next);
                } else {
                    pos[next] = open.insert(next);
                }
            }
        }
    }
    
//    std::cout << "iterations: " << iterations << std::endl;
//    std::cout << "decrease key: " << decreaseKey << std::endl;
    
    auto out = std::make_shared<std::stack<int> >();
    int curr = to;
    while (curr != -1) {
        out->push(curr);
        curr = prev[curr];
    }
    
    return out;
}