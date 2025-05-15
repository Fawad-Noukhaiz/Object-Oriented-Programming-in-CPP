#pragma once
#include "raylib.h"

class Warden {
public:
    Warden();
    void Update(Vector3 playerPos, const class Map& map);
    void Draw() const;
    Vector3 GetPosition() const;
    BoundingBox GetBoundingBox() const;
    void SetPosition(Vector3 pos);

private:
    Vector3 position;
    float speed = 3.0f;
};