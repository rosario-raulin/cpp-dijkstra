//
//  Edge.hpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#ifndef __astar__Edge__
#define __astar__Edge__

class Edge {
private:
    int _from;
    int _to;
    double _weight;
    
public:
    Edge(int from, int to, double weight);
    
    int from() const;
    int to() const;
    double weight() const;
};

#endif /* defined(__astar__Edge__) */
