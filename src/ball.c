#include "ball.h"

#include <raymath.h>

#include "consts.h"

Ball CreateBall() {
    return (Ball) { { (float)WIDTH / 2, (float)HEIGHT / 2 }, { 400, -100 } };
}

void DrawBall(const Ball* ball) {
    Vector2 topLeft = Vector2SubtractValue(ball->position, (float)BALL_SIZE / 2);
    DrawRectangleV(topLeft, (Vector2) { BALL_SIZE, BALL_SIZE }, BLACK);
}

Rectangle BallRectangle(const Ball* ball) {
    Vector2 topLeft = Vector2SubtractValue(ball->position, (float)BALL_SIZE / 2);
    return (Rectangle) { topLeft.x, topLeft.y, BALL_SIZE, BALL_SIZE };
}

