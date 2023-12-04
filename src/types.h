#ifndef TYPES_H_
#define TYPES_H_
#include "global.h"



typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
} Color;

typedef struct Pixel {
    Color bg;
    Color fg;
    char code;
} Pixel;

typedef struct Frame {
    uint16_t count;
    Pixel pixels[];
} Frame;

typedef struct Level {
    char foreground[4096][1024];
    char background[4096][1024];
} Level;

typedef struct Vec2 {
    f32 x;
    f32 y;
} Vec2;

typedef struct Camera {
    Vec2 start;
    Vec2 center;
    Vec2 end;
} Camera;

#endif // TYPES_H_
