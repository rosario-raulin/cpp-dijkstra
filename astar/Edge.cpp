//
//  Edge.cpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#include "Edge.hpp"

Edge::Edge(int from, int to, double weight) : _from(from), _to(to), _weight(weight) {}

int
Edge::from() const {
    return _from;
}

int
Edge::to() const {
    return _to;
}

double
Edge::weight() const {
    return _weight;
}