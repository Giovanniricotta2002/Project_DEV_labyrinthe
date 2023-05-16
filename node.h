#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>

struct sNode {
    int x;
    int y;
    int g;
    int h;
    int f;
    bool obstacle;
    sNode *parent;

    sNode(int _x, int _y)
        : x(_x), y(_y), g(0), h(0), f(0), obstacle(false), parent(nullptr) {}

    sNode()
        : x(0), y(0), g(0), h(0), f(0), obstacle(false), parent(nullptr) {}

    int calculateDistance(sNode *other) const { return std::max(std::abs(x - other->x), std::abs(y - other->y)); }
};

#endif
