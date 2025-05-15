#include "Warden.hpp"
#include "Map.hpp"
#include "Door.hpp"
#include "raymath.h"
#include <algorithm>

Warden::Warden() : position{ 10.0f, 1.0f, 10.0f }, speed{ 3.5f } {}

void Warden::Update(Vector3 playerPos, const Map& map) {
    Vector3 directionToPlayer = Vector3Normalize(Vector3Subtract(playerPos, position));
    Ray pathRay = { position, directionToPlayer };

    float nearestCollision = FLT_MAX;
    Vector3 obstacleNormal{ 0 };

    for (const auto& wall : map.walls) {
        RayCollision hit = GetRayCollisionBox(pathRay, wall);
        if (hit.hit && hit.distance < nearestCollision) {
            nearestCollision = hit.distance;
            obstacleNormal = hit.normal;
        }
    }

    for (const auto& door : Door::allDoors) {
        if (!Door::IsOpen(door.position)) {
            RayCollision hit = GetRayCollisionBox(pathRay, Door::GetBoundingBox(door.position));
            if (hit.hit && hit.distance < nearestCollision) {
                nearestCollision = hit.distance;
                obstacleNormal = hit.normal;
            }
        }
    }

    if (nearestCollision < 2.0f) {
        Vector3 avoidanceDirection = Vector3Normalize(Vector3CrossProduct(obstacleNormal, Vector3{ 0,1,0 }));
        position = Vector3Add(position, Vector3Scale(avoidanceDirection, speed * GetFrameTime()));
        position.y = 1.0f;
    }

    else {
        position = Vector3Add(position, Vector3Scale(directionToPlayer, speed * GetFrameTime()));
		position.y = 1.0f;
    }

    BoundingBox wardenBounds = {
        Vector3Subtract(position, {0.5f, 1.0f, 0.5f}),
        Vector3Add(position, {0.5f, 1.0f, 0.5f})
    };

    for (auto& door : Door::allDoors) {
        if (!Door::IsOpen(door.position)) {
            BoundingBox doorBox = Door::GetBoundingBox(door.position);
            if (CheckCollisionBoxes(wardenBounds, doorBox)) {
                if (!Door::IsMainGate(door.position)) {
                    Door::ToggleDoor(door.position, false);
                }
            }
        }
    }
}

BoundingBox Warden::GetBoundingBox() const {
    return {
        Vector3Subtract(position, {0.5f, 1.0f, 0.5f}),
        Vector3Add(position, {0.5f, 1.0f, 0.5f})
    };
}

void Warden::Draw() const {
    Vector3 base = Vector3Add(position, Vector3{ 0, -1.0f, 0 });

    DrawCube(Vector3Add(base, { 0.0f, 0.5f, 0.0f }), 0.4f, 1.0f, 0.4f, Color{ 80, 0, 0, 255 });

    DrawCube(Vector3Add(base, { 0.0f, 1.5f, 0.0f }), 0.6f, 1.0f, 0.4f, Color{ 100, 0, 0, 255 });

    DrawSphere(Vector3Add(base, { 0.0f, 2.3f, 0.0f }), 0.3f, Color{ 220, 220, 220, 255 });

    DrawSphere(Vector3Add(base, { -0.1f, 2.35f, 0.25f }), 0.05f, RED);
    DrawSphere(Vector3Add(base, { 0.1f, 2.35f, 0.25f }), 0.05f, RED);

    DrawCube(Vector3Add(base, { -0.45f, 1.5f, 0.0f }), 0.2f, 0.8f, 0.2f, Color{ 139, 0, 0, 255 });
    DrawCube(Vector3Add(base, { 0.45f, 1.5f, 0.0f }), 0.2f, 0.8f, 0.2f, Color{ 139, 0, 0, 255 });
}

Vector3 Warden::GetPosition() const {
    return position;
}

void Warden::SetPosition(Vector3 pos) {
	position = pos;
}