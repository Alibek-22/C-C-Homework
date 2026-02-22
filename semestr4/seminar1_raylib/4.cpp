#include "raylib.h"
#include <math.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    const float orbitRadius = 200.0f;   
    const float smallRadius = 20.0f;    
    const float angularSpeed = 1.5f;   

    float angle = 0.0f;

    InitWindow(screenWidth, screenHeight, "Движение по окружности");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        angle += angularSpeed * dt;

        float x = screenWidth / 2 + orbitRadius * cosf(angle);
        float y = screenHeight / 2 + orbitRadius * sinf(angle);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircleLines(screenWidth / 2, screenHeight / 2, orbitRadius, LIGHTGRAY);

        DrawCircleV((Vector2){ x, y }, smallRadius, MAROON);

        DrawCircle(screenWidth / 2, screenHeight / 2, 3, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
