#include "raylib.h"

#include <iostream>

using namespace std;

const struct
{
    int width = 800;
    int height = 700;
} windowScreen;

int main()
{
    InitWindow(windowScreen.width, windowScreen.height, "Hello, warrior!");

    SetTargetFPS(60);

    // Game loop
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}