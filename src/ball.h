#ifndef BALL_H
#define BALL_H

#include <raylib.h>

#define BALL_SIZE 20

typedef struct {
    Vector2 position;
    Vector2 velocity;
} Ball;

Ball CreateBall();

void DrawBall(const Ball* ball);

Rectangle BallRectangle(const Ball* ball);

#endif
