#include "raylib.h"
#include <string>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Координаты мыши");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        std::string text = "X: " + std::to_string(mouse.x) + "  Y: " + std::to_string(mouse.y);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(text.c_str(), 20, 20, 30, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
