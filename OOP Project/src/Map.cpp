#include "Map.hpp"  
#include "Door.hpp"  
#include "raylib.h"  
#include "raymath.h"  

int GetFrameCount() {  
   return (int)(GetTime() * 60);
}  

Map::Map() {

   keyPosition = { -13, 1, 12 };  
   mainExitPosition = { 13, 1, -12 };  

   for (int x = 0; x < 40; x++)  
       for (int z = 0; z < 40; z++)  
           grid[x][z] = false;  

   walls = {  
       {{-15, 0, -15}, {15, 3, -14}}, 
       {{-15, 0, 14}, {15, 3, 15}},
       {{-15, 0, -15}, {-14, 3, 15}},
       {{14, 0, -15}, {15, 3, 15}},
   };  

   walls.push_back({ {-10, 0, -12}, {-9, 3, -6} });
   walls.push_back({ {-6, 0, -13}, {6, 3, -12} });

   walls.push_back({ {5, 0, -11}, {6, 3, -2} });
   walls.push_back({ {5, 0, 2}, {6, 3, 6} });

   walls.push_back({ {-5, 0, 8}, {6, 3, 9} });

   walls.push_back({ {-2, 0, -2}, {-1, 3, 2} });

   walls.push_back({ {-13, 0, 5}, {-9, 3, 6} });
 
   walls.push_back({ {9, 0, -6}, {12, 3, -5} });

   walls.push_back({ {-6, 0, 12}, {-1, 3, 13} });

   Door::allDoors.clear();  
   Door::allDoors.push_back({ mainExitPosition, true, false });
}  

void Map::Draw() const {

    DrawPlane({ 0, 0, 0 }, { 30, 30 }, Color{ 60, 40, 30, 255 });

    DrawCube({ 0, 3.05f, 0 }, 30, 0.1f, 30, Color{ 50, 30, 25, 255 });

    int flicker = GetFrameCount() % 80;

    for (const auto& wall : walls) {
        Vector3 pos = Vector3Lerp(wall.min, wall.max, 0.5f);
        Vector3 size = Vector3Subtract(wall.max, wall.min);

        Color baseColor = (flicker > 75)
            ? Color{ 100, 0, 0, 255 }
        : Color{ 70, 50, 40, 255 };

        DrawCube(pos, size.x, size.y, size.z, baseColor);
        DrawCubeWires(pos, size.x, size.y, size.z, Color{ 20, 10, 10, 255 });
    }

    if (Vector3Distance(keyPosition, Vector3{ 1000, 1000, 1000 }) > 10) {
        DrawCylinderEx(
            Vector3Add(keyPosition, { 0, 0.0f, 0 }),
            Vector3Add(keyPosition, { 0, 0.3f, 0 }),
            0.1f, 0.1f, 8, GOLD
        );

        DrawCube(Vector3Add(keyPosition, { 0, 0.4f, 0 }), 0.3f, 0.1f, 0.3f, GOLD);
        DrawCube(Vector3Add(keyPosition, { 0.1f, 0.15f, 0 }), 0.1f, 0.1f, 0.05f, GOLD);
        DrawCube(Vector3Add(keyPosition, { -0.1f, 0.15f, 0 }), 0.1f, 0.1f, 0.05f, GOLD);

        DrawSphere(keyPosition, 0.5f, Color{ 255, 215, 0, 50 });
    }

    if (!Door::IsOpen(mainExitPosition)) {
        DrawCube(mainExitPosition, 1.2f, 2.0f, 0.2f, RED);
        DrawCube(Vector3Add(mainExitPosition, { 0, 2, 0 }), 0.3f, 0.3f, 0.3f, GREEN);
    }
    else {
        DrawSphere(mainExitPosition, 1.2f, Color{ 0, 255, 0, 100 });
    }
}

void Map::UpdateGrid() {  
   for (int x = 0; x < 40; x++)  
       for (int z = 0; z < 40; z++)  
           grid[x][z] = false;  
 
   for (const auto& wall : walls) {  
       int startX = static_cast<int>(wall.min.x + 20);  
       int endX = static_cast<int>(wall.max.x + 20);  
       int startZ = static_cast<int>(wall.min.z + 20);  
       int endZ = static_cast<int>(wall.max.z + 20);  

       for (int x = startX; x <= endX; x++)  
           for (int z = startZ; z <= endZ; z++)  
               if (x >= 0 && x < 40 && z >= 0 && z < 40)  
                   grid[x][z] = true;  
   }  

   const auto& gate = Door::allDoors[0];  
   if (!gate.isOpen) {  
       int gx = static_cast<int>(gate.position.x + 20);  
       int gz = static_cast<int>(gate.position.z + 20);  
       for (int dx = -1; dx <= 1; dx++)  
           for (int dz = -1; dz <= 1; dz++) {  
               int x = gx + dx;  
               int z = gz + dz;  
               if (x >= 0 && x < 40 && z >= 0 && z < 40)  
                   grid[x][z] = true;  
           }  
   }  
}  

Vector3 Map::FindFirstFreeTile() {  
   for (int x = 0; x < 40; x++) {  
       for (int z = 0; z < 40; z++) {  
           if (!grid[x][z]) {  
               return { x - 20 + 0.5f, 1.0f, z - 20 + 0.5f };  
           }  
       }  
   }  
   return { 0, 1, 0 };
}