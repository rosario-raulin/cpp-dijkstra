//
//  IGraph.hpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#ifndef astar_IGraph_hpp
#define astar_IGraph_hpp

#include <vector>

#include "Edge.hpp"

class IGraph {
public:
    virtual ~IGraph() {}
    
    virtual size_t V() const = 0;
    virtual size_t E() const = 0;
    virtual const std::vector<Edge> adj(int node) const = 0;
    virtual void addEdge(int from, int to, double weight) = 0;
    virtual bool hasEdge(int from, int to) const = 0;
};

#endif
