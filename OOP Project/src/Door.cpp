#include "Door.hpp"
#include "raymath.h"

std::vector<Door::DoorData> Door::allDoors;

void Door::ToggleDoor(Vector3 pos, bool hasKey) {
    auto it = std::find_if(allDoors.begin(), allDoors.end(),
        [pos](const DoorData& d) { return Vector3IsEqual(d.position, pos); });

    if (it != allDoors.end()) {
        if (it->isMainGate && !hasKey) return;
        it->isOpen = !it->isOpen;
    }
}

bool Door::IsOpen(Vector3 pos) {
    auto it = std::find_if(allDoors.begin(), allDoors.end(),
        [pos](const DoorData& d) { return Vector3IsEqual(d.position, pos); });
    return (it != allDoors.end()) ? it->isOpen : false;
}

bool Door::IsMainGate(Vector3 pos) {
    auto it = std::find_if(allDoors.begin(), allDoors.end(),
        [pos](const DoorData& d) { return Vector3IsEqual(d.position, pos); });
    return (it != allDoors.end()) ? it->isMainGate : false;
}

BoundingBox Door::GetBoundingBox(Vector3 pos) {
    return IsOpen(pos) ?
        BoundingBox{ {0,0,0}, {0,0,0} } :
        BoundingBox{
            Vector3Subtract(pos, {1.0f, 2.0f, 1.0f}),
            Vector3Add(pos, {1.0f, 2.0f, 1.0f})
    };
}