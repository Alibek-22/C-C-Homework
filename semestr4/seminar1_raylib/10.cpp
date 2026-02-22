#include "raylib.h"
#include <math.h>

#define MAX_BALLS 100
#define MIN_DIST 10.0f

typedef struct {
    Vector2 pos;
    Vector2 vel;
    float mass;
    float charge;
} Ball;

float getRadius(float mass) {
    return 5.0f + mass * 0.5f;   
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "n-body simulation with Coulomb force");
    SetTargetFPS(60);

    Ball balls[MAX_BALLS];
    int ballCount = 0;

    // Несколько случайных шариков для начала
    for (int i = 0; i < 5; i++) {
        if (ballCount < MAX_BALLS) {
            float mass = (float)GetRandomValue(1, 5);
            float r = getRadius(mass);
            balls[ballCount].pos.x = (float)GetRandomValue((int)r, screenWidth - (int)r);
            balls[ballCount].pos.y = (float)GetRandomValue((int)r, screenHeight - (int)r);
            balls[ballCount].vel.x = 0.0f;
            balls[ballCount].vel.y = 0.0f;
            balls[ballCount].mass = mass;
            balls[ballCount].charge = (float)GetRandomValue(-20, 20) / 10.0f; // [-2.0, 2.0]
            ballCount++;
        }
    }

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // Добавление шариков мышью
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && ballCount < MAX_BALLS) {
            Vector2 mouse = GetMousePosition();
            balls[ballCount].pos = mouse;
            balls[ballCount].vel = (Vector2){0, 0};
            balls[ballCount].mass = 1.0f;
            balls[ballCount].charge = -1.0f;
            ballCount++;
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && ballCount < MAX_BALLS) {
            Vector2 mouse = GetMousePosition();
            balls[ballCount].pos = mouse;
            balls[ballCount].vel = (Vector2){0, 0};
            balls[ballCount].mass = 10.0f;
            balls[ballCount].charge = 1.0f;
            ballCount++;
        }

        Vector2 force[MAX_BALLS] = {0};
        for (int i = 0; i < ballCount; i++) {
            force[i].x = force[i].y = 0.0f;
        }

        for (int i = 0; i < ballCount; i++) {
            for (int j = i + 1; j < ballCount; j++) {
                Vector2 dr = { balls[i].pos.x - balls[j].pos.x, balls[i].pos.y - balls[j].pos.y };
                float r2 = dr.x * dr.x + dr.y * dr.y;
                float r = sqrtf(r2);
                if (r < MIN_DIST) continue;              
                float f = (balls[i].charge * balls[j].charge) / r2; // (q1*q2)/r^2
                force[i].x += f * dr.x;
                force[i].y += f * dr.y;
                force[j].x -= f * dr.x;
                force[j].y -= f * dr.y;
            }
        }

        // Обновление скоростей и положений
        for (int i = 0; i < ballCount; i++) {
            Vector2 acc = { force[i].x / balls[i].mass, force[i].y / balls[i].mass };
            balls[i].vel.x += acc.x * dt;
            balls[i].vel.y += acc.y * dt;
            balls[i].pos.x += balls[i].vel.x * dt;
            balls[i].pos.y += balls[i].vel.y * dt;
        }

        // Отскок от стенок (упругий)
        for (int i = 0; i < ballCount; i++) {
            float r = getRadius(balls[i].mass);
            if (balls[i].pos.x - r < 0) {
                balls[i].pos.x = r;
                balls[i].vel.x = -balls[i].vel.x;
            }
            if (balls[i].pos.x + r > screenWidth) {
                balls[i].pos.x = screenWidth - r;
                balls[i].vel.x = -balls[i].vel.x;
            }
            if (balls[i].pos.y - r < 0) {
                balls[i].pos.y = r;
                balls[i].vel.y = -balls[i].vel.y;
            }
            if (balls[i].pos.y + r > screenHeight) {
                balls[i].pos.y = screenHeight - r;
                balls[i].vel.y = -balls[i].vel.y;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < ballCount; i++) {
            Color color;
            if (balls[i].charge > 0) color = RED;
            else if (balls[i].charge < 0) color = BLUE;
            else color = GREEN;
            float r = getRadius(balls[i].mass);
            DrawCircleV(balls[i].pos, r, color);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
