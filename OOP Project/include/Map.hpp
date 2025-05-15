#pragma once
#include <vector>
#include "raylib.h"

class Map {
public:
    std::vector<BoundingBox> walls;
    bool grid[40][40] = { false };

    Vector3 mainExitPosition;
    Vector3 keyPosition;

    Map();
    void Draw() const;
    void UpdateGrid();
    Vector3 FindFirstFreeTile();

    Model keyModel;
    bool keyModelLoaded = false;
};