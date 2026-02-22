#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const float side = 100.0f;
    const float rotationSpeed = 2.0f; 

    float angle = 0.0f;

    InitWindow(screenWidth, screenHeight, "Вращающийся квадрат");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        angle += rotationSpeed * GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        rlPushMatrix();
        rlTranslatef(screenWidth / 2, screenHeight / 2, 0);
        rlRotatef(angle * RAD2DEG, 0, 0, 1); 
        DrawRectangle(0, 0, side, side, BLUE);
        rlPopMatrix();

        DrawCircle(screenWidth / 2, screenHeight / 2, 5, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
