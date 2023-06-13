#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

#include "consts.h"
#include "ball.h"
#include "bat.h"

int main() {
    InitWindow(WIDTH, HEIGHT, "First window!!");

    Ball ball = CreateBall();

    Bat bat1 = { BAT_OFFSET, (float)HEIGHT / 2 };
    Bat bat2 = { WIDTH - BAT_OFFSET, (float)HEIGHT / 2 };

    float collideTimer = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
            float delta = GetFrameTime();
            collideTimer -= delta;

            ClearBackground(RAYWHITE);

            DrawText("First window!!", 190, 200, 20, LIGHTGRAY);

            DrawBall(&ball);
            
            DrawBat(&bat1);
            DrawBat(&bat2);

            if (IsKeyDown(KEY_W)) {
                bat1.position.y -= BAT_SPEED * delta;
            }
            if (IsKeyDown(KEY_S)) {
                bat1.position.y += BAT_SPEED * delta;
            }

            if (IsKeyDown(KEY_UP)) {
                bat2.position.y -= BAT_SPEED * delta;
            }
            if (IsKeyDown(KEY_DOWN)) {
                bat2.position.y += BAT_SPEED * delta;
            }

            Vector2 ballOffset = Vector2Scale(ball.velocity, delta);
            ball.position = Vector2Add(ball.position, ballOffset);

            bool bat1Collide = CheckCollisionRecs(BatRectangle(&bat1), BallRectangle(&ball));
            bool bat2Collide = CheckCollisionRecs(BatRectangle(&bat2), BallRectangle(&ball));

            if ((bat1Collide || bat2Collide) && collideTimer <= 0) {
                ball.velocity.x *= -1;
                ball.position = Vector2Subtract(ball.position, ballOffset);
                collideTimer = 0.1;
            }

            if (ball.position.y <= (float)BALL_SIZE / 2 || ball.position.y >= HEIGHT - (float)BALL_SIZE / 2) {
                ball.velocity.y *= -1;
                ball.position = Vector2Subtract(ball.position, ballOffset);
            }

            for (int y = 0; y < HEIGHT; y += 60) {
                DrawRectangle(WIDTH / 2, y, 20, 30, LIGHTGRAY);
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
