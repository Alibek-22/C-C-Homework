#include "raylib.h"
#include <stdlib.h>   

#define MAX_CIRCLES 1000

typedef struct {
    Vector2 center;
    Color color;
} Circle;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const float radius = 20.0f;

    Circle circles[MAX_CIRCLES];
    int circleCount = 0;

    InitWindow(screenWidth, screenHeight, "Создание кругов");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && circleCount < MAX_CIRCLES)
        {
            circles[circleCount].center = GetMousePosition();
            circles[circleCount].color = WHITE;
            circleCount++;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            for (int i = 0; i < circleCount; i++)
            {
                circles[i].color = (Color){
                    GetRandomValue(0, 255),
                    GetRandomValue(0, 255),
                    GetRandomValue(0, 255),
                    255
                };
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);  

        for (int i = 0; i < circleCount; i++)
        {
            DrawCircleV(circles[i].center, radius, circles[i].color);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
