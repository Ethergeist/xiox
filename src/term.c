#include "term.h"

void clearScreen(void) { printf("\033[2J"); }

void resetScreen(void) { printf("\033[m"); }

void drawFrame(Frame* frame, const Screen* screen)
{
    moveCursor(1, 1);
    for (size_t i = 0; i < frame->count; i++) {
        setPixel(&frame->pixels[i]);
    }
}

void clearFrame(Frame* frame)
{
    for (size_t p = 0; p < frame->count; p++) {
        frame->pixels[p].bg = (Color) { 0, 0, 0 };
        frame->pixels[p].fg = (Color) { 0, 0, 0 };
        frame->pixels[p].code = ' ';
    }
}

void hideCursor(void) { printf("\033[?25l"); }

void moveCursor(u8 x, u8 y) { printf("\033[%u;%uH", x, y); }

void showCursor(void) { printf("\033[?25h"); }

void setPixel(const Pixel* pixel)
{
    printf(
        "\033[38;2;%u;%u;%um\033[48;2;%u;%u;%um%c",
        pixel->fg.r,
        pixel->fg.g,
        pixel->fg.b,
        pixel->bg.r,
        pixel->bg.g,
        pixel->bg.b,
        pixel->code
    );
}
