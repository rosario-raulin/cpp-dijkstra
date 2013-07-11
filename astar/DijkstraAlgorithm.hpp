//
//  DijkstraAlgorithm.hpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#ifndef __astar__DijkstraAlgorithm__
#define __astar__DijkstraAlgorithm__

#include "IPathFinder.hpp"
#include "IGraph.hpp"

#include <stack>

class DijkstraAlgorithm : public IPathFinder {
private:
    IGraph* _graph;
    double* _distances;
    
    bool compare(const int& x, const int& y) const;
    
public:
    DijkstraAlgorithm(IGraph* graph);
    DijkstraAlgorithm(const DijkstraAlgorithm& other);
    ~DijkstraAlgorithm();
    
    std::stack<int> find(int from, int to) const;
};

#endif /* defined(__astar__DijkstraAlgorithm__) */
