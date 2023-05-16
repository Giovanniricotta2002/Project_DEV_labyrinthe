#include "node.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include "lib/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;




inline std::vector<sNode *> aStar(sNode *start, sNode *goal, std::vector<std::vector<sNode>> &graph) {
    int numRows = graph.size();
    int numCols = graph[0].size();

    std::vector<std::vector<bool>> closedSet(numRows, std::vector<bool>(numCols, false));

    auto compare = [](sNode *a, sNode *b) { return a->f > b->f; };
    std::priority_queue<sNode *, std::vector<sNode *>, decltype(compare)> openSet(compare);
    openSet.push(start);

    while (!openSet.empty()) {
        sNode *current = openSet.top();
        openSet.pop();

        if (current == goal) {
            std::vector<sNode *> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        closedSet[current->x][current->y] = true;

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int neighborX = current->x + dx;
                int neighborY = current->y + dy;

                if (neighborX >= 0 && neighborX < numRows && neighborY >= 0 && neighborY < numCols) {
                    sNode *neighbor = &graph[neighborX][neighborY];

                    if (!neighbor->obstacle && !closedSet[neighborX][neighborY]) {
                        int newG = current->g + 1;

                        if (newG < neighbor->g || neighbor->g == 0) {
                            neighbor->g = newG;
                            neighbor->h = neighbor->calculateDistance(goal);
                            neighbor->f = neighbor->g + neighbor->h;
                            neighbor->parent = current;
                            openSet.push(neighbor);
                        }
                    }
                }
            }
        }
    }

    return std::vector<sNode *>();
}

inline int pmap() {
    std::ifstream file("map.json");
    json data;
    file >> data;

    std::vector<std::vector<sNode>> graph;
    graph.resize(data["case_map"].size());

    for (size_t i = 0; i < graph.size(); ++i) {
        graph[i].resize(data["case_map"][i].size());

        for (size_t j = 0; j < graph[i].size(); ++j) {
            int x = data["case_map"][j][i]["x"];
            int y = data["case_map"][j][i]["y"];
            bool obstacle = data["case_map"][j][i]["obstacle"];


            sNode node(x, y);
            node.obstacle = obstacle;
            graph[i][j] = node;
        }
    }

    int numRows = graph.size();
    int numCols = graph[0].size();
    
    sNode *start = &graph[data["start"]["x"]][data["start"]["y"]];
    sNode *goal = &graph[data["end"]["x"]][data["end"]["y"]];
    std::vector<sNode *> path = aStar(start, goal, graph);

    if (!path.empty()) {
        std::cout << "Chemin trouve : ";
        for (const auto *node : path) { std::cout << "(" << node->x << ", " << node->y << ") "; }
        std::cout << std::endl;
    }
    else { std::cout << "Aucun chemin trouve." << std::endl; }

    return 0;
}
