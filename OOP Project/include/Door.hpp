#pragma once
#include "raylib.h"
#include <vector>
#include <algorithm>

inline bool Vector3IsEqual(Vector3 a, Vector3 b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

class Door {
public:
    struct DoorData {
        Vector3 position;
        bool isMainGate;
        bool isOpen;
    };

    static void ToggleDoor(Vector3 position, bool hasKey);
    static bool IsOpen(Vector3 position);
    static bool IsMainGate(Vector3 position);
    static BoundingBox GetBoundingBox(Vector3 position);

    static std::vector<DoorData> allDoors;
};