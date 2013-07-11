//
//  ListGraph.cpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#include "ListGraph.hpp"


ListGraph::ListGraph(int size) : _v(size), _e(0), _adj(new std::vector<Edge>[size]) {
}

ListGraph::ListGraph(const ListGraph& other) : _v(other._v), _e(other._e), _adj(new std::vector<Edge>[other._v]) {
}

ListGraph::~ListGraph() {
    delete [] _adj;
}

size_t
ListGraph::V() const {
    return _v;
}

size_t
ListGraph::E() const {
    return _e;
}

std::vector<Edge>
ListGraph::adj(int from) const {
    auto begin = _adj[from].begin();
    auto end = _adj[from].end();
    
    return std::vector<Edge>(begin, end);
}

void
ListGraph::addEdge(int from, int to, double weight) {
    ++_e;
    _adj[from].push_back(Edge(from, to, weight));
}