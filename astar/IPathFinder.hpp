//
//  IPathFinder.hpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#ifndef astar_IPathFinder_hpp
#define astar_IPathFinder_hpp

#include <stack>

class IPathFinder {
public:
    virtual ~IPathFinder() {}
    
    virtual std::stack<int> find(int from, int to) const = 0;
};

#endif
