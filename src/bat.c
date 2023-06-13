#include "bat.h"

#include <raymath.h>

void DrawBat(const Bat* bat) {
    Vector2 topLeft = Vector2Subtract(bat->position, (Vector2) { (float)BAT_WIDTH / 2, (float)BAT_HEIGHT / 2 });
    DrawRectangleV(topLeft, (Vector2) { BAT_WIDTH, BAT_HEIGHT }, BLACK);
}

Rectangle BatRectangle(const Bat* bat) {
    Vector2 topLeft = Vector2Subtract(bat->position, (Vector2) { (float)BAT_WIDTH / 2, (float)BAT_HEIGHT / 2 });
    return (Rectangle) { topLeft.x, topLeft.y, BAT_WIDTH, BAT_HEIGHT };
}

