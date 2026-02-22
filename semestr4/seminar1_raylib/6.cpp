#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    Rectangle rect = { 250, 200, 300, 200 };

    InitWindow(screenWidth, screenHeight, "Столкновение с прямоугольником");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        bool isInside = CheckCollisionPointRec(mouse, rect);

        Color color = isInside ? RED : GREEN;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(rect, color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
