#include "Player.hpp"
#include "Map.hpp"
#include "raymath.h"
#include "Door.hpp"
#include "Game.hpp"

Player::Player() {
    camera.up = { 0, 1, 0 };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    DisableCursor();
}

void Player::SetPosition(Vector3 newPos) {
    position = newPos;
    camera.position = position;
    Vector3 lookDirection = { 0, 0, 1 };
    camera.target = Vector3Add(position, lookDirection);
}

void Player::Update(const Map& map) {
    Vector3 oldPos = position;

    Vector2 mouseDelta = GetMouseDelta();
    angle.x -= mouseDelta.y * 0.001f;
    angle.y -= mouseDelta.x * 0.001f;
    angle.x = Clamp(angle.x, -PI / 2.2f, PI / 2.2f);

    Vector3 forward = {
        sinf(angle.y) * cosf(angle.x),
        sinf(angle.x),
        cosf(angle.y) * cosf(angle.x)
    };
    Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, { 0, 1, 0 }));
    Vector3 movement = { 0 };

    float moveSpeed = 5.0f * GetFrameTime();
    if (IsKeyDown(KEY_W)) movement = Vector3Add(movement, forward);
    if (IsKeyDown(KEY_S)) movement = Vector3Add(movement, Vector3Negate(forward));
    if (IsKeyDown(KEY_A)) movement = Vector3Add(movement, Vector3Negate(right));
    if (IsKeyDown(KEY_D)) movement = Vector3Add(movement, right);

    if (!Vector3IsEqual(movement, Vector3Zero())) {
        movement = Vector3Scale(Vector3Normalize(movement), moveSpeed);
        position = Vector3Add(position, movement);
        position.y = 1.0f;
    }

    camera.position = position;
    camera.target = Vector3Add(position, forward);

    BoundingBox playerBox = GetBoundingBox();
    bool collision = false;

    if (!Door::IsOpen(map.mainExitPosition)) {
        BoundingBox doorBox = Door::GetBoundingBox(map.mainExitPosition);
        if (CheckCollisionBoxes(playerBox, doorBox)) collision = true;
    }

    if (!collision) {
        for (const auto& wall : map.walls) {
            if (CheckCollisionBoxes(playerBox, wall)) {
                collision = true;
                break;
            }
        }
    }

    if (collision) {
        position = oldPos;
        camera.position = position;
    }
}

BoundingBox Player::GetBoundingBox() const {
    return {
        Vector3Subtract(position, {0.5f, 1.0f, 0.5f}),
        Vector3Add(position, {0.5f, 1.0f, 0.5f})
    };
}

Vector3 Player::GetPosition() const { return position; }
Camera3D Player::GetCamera() const { return camera; }
