#ifndef BAT_H
#define BAT_H

#include <raylib.h>

#define BAT_SPEED 400
#define BAT_WIDTH 20
#define BAT_HEIGHT 150
#define BAT_OFFSET 50

typedef struct {
    Vector2 position;
} Bat;

void DrawBat(const Bat* bat);

Rectangle BatRectangle(const Bat* bat);

#endif
