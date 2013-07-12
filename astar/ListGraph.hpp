//
//  ListGraph.hpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#ifndef __astar__ListGraph__
#define __astar__ListGraph__

#include <vector>

#include "IGraph.hpp"

class ListGraph : public IGraph {
private:
    size_t _v;
    size_t _e;
    std::unique_ptr<std::vector<Edge>[]> _adj;
    
public:
    ListGraph(int size);
    ListGraph(const ListGraph& other);
    ~ListGraph();
    
    size_t V() const;
    size_t E() const;
    std::vector<Edge>* adj(int from) const;

    void addEdge(int from, int to, double weight);
    bool hasEdge(int from, int to) const;
};

#endif /* defined(__astar__ListGraph__) */
