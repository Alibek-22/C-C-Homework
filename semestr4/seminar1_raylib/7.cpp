#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const float radius = 30.0f;
    const float speed = 300.0f;          

    float circleX = screenWidth / 2.0f;
    float circleY = screenHeight / 2.0f;
    Color circleColor = RED;

    InitWindow(screenWidth, screenHeight, "Двигающийся кружок");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT)) circleX += speed * dt;
        if (IsKeyDown(KEY_LEFT)) circleX -= speed * dt;
        if (IsKeyDown(KEY_UP)) circleY -= speed * dt;
        if (IsKeyDown(KEY_DOWN)) circleY += speed * dt;

        if (IsKeyPressed(KEY_SPACE))
        {
            circleColor = (Color){
                GetRandomValue(0, 255),
                GetRandomValue(0, 255),
                GetRandomValue(0, 255),
                255
            };
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle((int)circleX, (int)circleY, radius, circleColor);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
