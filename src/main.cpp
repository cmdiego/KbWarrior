#include "raylib.h"
#include "../inc/map.hpp"

#include <iostream>

using namespace std;

const struct
{
    int width = 800;
    int height = 800;
} windowScreen;

int main()
{
    InitWindow(windowScreen.width, windowScreen.height, "Hello, warrior!");

    SetTargetFPS(60);

    Map map;

    // Game loop
    while(!WindowShouldClose())
    {
        BeginDrawing();
        map.Draw();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}