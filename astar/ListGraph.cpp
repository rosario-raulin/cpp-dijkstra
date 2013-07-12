//
//  ListGraph.cpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#include "ListGraph.hpp"
#include <algorithm>


ListGraph::ListGraph(int size) : _v(size), _e(0), _adj(new std::vector<Edge>[size]) {
}

ListGraph::ListGraph(const ListGraph& other) : _v(other._v), _e(other._e), _adj(new std::vector<Edge>[other._v]) {
}

ListGraph::~ListGraph() {
    _adj.reset();
}

size_t
ListGraph::V() const {
    return _v;
}

size_t
ListGraph::E() const {
    return _e;
}

std::vector<Edge>*
ListGraph::adj(int from) const {
    return &(_adj[from]);
}

void
ListGraph::addEdge(int from, int to, double weight) {
    ++_e;
    _adj[from].push_back(Edge(from, to, weight));
}

bool
ListGraph::hasEdge(int from, int to) const {
    for (auto it = _adj[from].begin(); it != _adj[from].end(); ++it) {
        if (it->to() == to) {
            return true;
        }
    }
    return false;
}