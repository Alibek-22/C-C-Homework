#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int radius = 40;
    const float speed = 200.0f;          

    float circleX = radius;
    float circleY = screenHeight / 2;

    InitWindow(screenWidth, screenHeight, "Движущийся круг");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        circleX += speed * dt;

        if (circleX - radius > screenWidth)
        {
            circleX = -radius;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle((int)circleX, (int)circleY, radius, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
