#include "raylib.h"
#include <math.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const float radius = 20.0f;
    const float acceleration = 500.0f;    

    Vector2 circlePos = { screenWidth/2, screenHeight/2 };
    Vector2 velocity = { 0, 0 };

    InitWindow(screenWidth, screenHeight, "Притяжение к мыши (постоянное ускорение)");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();
            Vector2 dir = { mousePos.x - circlePos.x, mousePos.y - circlePos.y };
            float len = sqrtf(dir.x*dir.x + dir.y*dir.y);
            if (len > 0.001f)
            {
                dir.x /= len;
                dir.y /= len;
                velocity.x += dir.x * acceleration * dt;
                velocity.y += dir.y * acceleration * dt;
            }
        }

        circlePos.x += velocity.x * dt;
        circlePos.y += velocity.y * dt;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(circlePos, radius, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
