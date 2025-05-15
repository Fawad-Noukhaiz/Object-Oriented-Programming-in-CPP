#pragma once
#include "Player.hpp"
#include "Warden.hpp"
#include "Map.hpp"

class Game {
public:
    Game();
    void Run();
    bool escaped = false;
    bool caught = false;

private:
    Player player;
    Warden warden;
    Map map;
    Vector3 keyPos = { 8,1,8 };
    bool hasKey = false;
    bool gameOver = false;
};