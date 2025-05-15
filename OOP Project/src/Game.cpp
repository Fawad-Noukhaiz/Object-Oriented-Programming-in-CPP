#include "Game.hpp"
#include "raylib.h"
#include "raymath.h"
#include "Door.hpp"
#include "Player.hpp"
#include "Warden.hpp"
#include "Map.hpp"

Game::Game() {
    InitWindow(1360, 768, "Haunted Asylum Escape");
    SetTargetFPS(60);
    DisableCursor();

    player.SetPosition(Vector3Add(map.mainExitPosition, Vector3{ -1.5f, 1.0f, 0.0f }));

    Vector3 wardenOffset = { 1.5f, 1.0f, 0.0f };
    warden.SetPosition(Vector3Add(map.keyPosition, wardenOffset));

}

void Game::Run() {
    Texture2D doorTexture = { 0 };

    while (!WindowShouldClose()) {
        if (escaped || caught) {
            if (IsKeyPressed(KEY_ENTER)) break;
        }
        else {
            player.Update(map);
            warden.Update(player.GetPosition(), map);
            map.UpdateGrid();

            if (!player.hasKey) {
                BoundingBox keyBox = {
                    Vector3Subtract(map.keyPosition, {0.5f, 0.5f, 0.5f}),
                    Vector3Add(map.keyPosition, {0.5f, 0.5f, 0.5f})
                };
                if (CheckCollisionBoxes(player.GetBoundingBox(), keyBox)) {
                    player.hasKey = true;
                    map.keyPosition = { 1000, 1000, 1000 };
                    PlaySound(LoadSound("resources/pickup.wav"));
                }
            }

            if (IsKeyPressed(KEY_F)) {
                BoundingBox interactionZone = {
                    Vector3Subtract(map.mainExitPosition, {2, 2, 2}),
                    Vector3Add(map.mainExitPosition, {2, 2, 2})
                };
                if (CheckCollisionBoxes(player.GetBoundingBox(), interactionZone)) {
                    Door::ToggleDoor(map.mainExitPosition, player.hasKey);
                    PlaySound(LoadSound(player.hasKey ? "resources/unlock.wav" : "resources/door.wav"));
                }
            }

            if (player.hasKey) {
                BoundingBox exitBox = {
                    Vector3Subtract(map.mainExitPosition, {2, 2, 2}),
                    Vector3Add(map.mainExitPosition, {2, 2, 2})
                };
                if (CheckCollisionBoxes(player.GetBoundingBox(), exitBox) &&
                    Door::IsOpen(map.mainExitPosition)) {
                    escaped = true;
                    PlaySound(LoadSound("resources/win.wav"));
                }
            }

            if (CheckCollisionBoxes(player.GetBoundingBox(), warden.GetBoundingBox())) {
                caught = true;
                PlaySound(LoadSound("resources/caught.wav"));
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(player.GetCamera());

        map.Draw();
        warden.Draw();

        const Vector3& pos = map.mainExitPosition;
        bool isOpen = Door::IsOpen(pos);
        Color doorColor = isOpen ? GRAY : (player.hasKey ? GREEN : RED);
        DrawCube(pos, 2.0f, 4.0f, 1.0f, doorColor);
        DrawSphere(Vector3Add(pos, { 0.6f, 0.0f, 0.0f }), 0.15f, BLACK);

        EndMode3D();

        DrawRectangle(680, 10, 20, 20, WHITE);

        if (escaped) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{ 0, 0, 0, 200 });
            DrawText("CONGRATULATIONS! YOU ESCAPED!", 300, 300, 40, GREEN);
            DrawText("Press ENTER to exit", 500, 380, 20, WHITE);
        }
        else if (caught) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{ 0, 0, 0, 200 });
            DrawText("YOU WERE CAUGHT! GAME OVER!", 320, 300, 40, RED);
            DrawText("Press ENTER to exit", 500, 380, 20, WHITE);
        }
        else {
            DrawRectangle(10, 10, 200, 30, Color{ 0, 0, 0, 150 });
            DrawText(player.hasKey ? "Key: Found! Find the exit!" : "Find the key!", 20, 15, 20, player.hasKey ? YELLOW : WHITE);
            DrawRectangle(10, GetScreenHeight() - 40, 320, 30, Color{ 0, 0, 0, 150 });
            DrawText("WASD: Move | F: Open Door | ESC: Exit", 20, GetScreenHeight() - 35, 20, LIGHTGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
}
