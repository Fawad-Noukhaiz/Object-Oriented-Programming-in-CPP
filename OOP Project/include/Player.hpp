#pragma once
#include "raylib.h"

class Player {
public:
    bool hasKey = false;
    Player();
    void Update(const class Map& map);
    void Draw() const;
    Vector3 GetPosition() const;
    void SetPosition(Vector3 newPos);
    Camera3D GetCamera() const;
    BoundingBox GetBoundingBox() const;
private:
    Vector3 position;
    Camera3D camera;
    Vector2 angle = { 0.0f , 0.0f };
};