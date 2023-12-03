#include "drawing.h"
#include <stdint.h>

void paintBackground(Frame* frame, struct winsize* window)
{
    Color startColor = {.r = 1, .g = 1, .b = 1};
    Color endColor = {.r = 200, .g = 80, .b = 32};
    Color white = {.r = 32, .g = 200, .b = 80};
    size_t pixel = 1;
    for (size_t y = 1; y < window->ws_row; y++) {
        u8 offset = y - 20;
        Color step = {
            .r = 1 + (endColor.r / window->ws_row) * offset,
            .g = 1 + (endColor.g / window->ws_row) * offset,
            .b = 1 + (endColor.b / window->ws_row) * offset,
        };
        if (y < 20) {
            step = startColor;
        }
        for (size_t x = 1; x < window->ws_col; x++) {
            frame->pixels[pixel - 1] = (Pixel){.bg = step, .fg = white, .code = ' '};
            pixel++;
        }
        pixel++;
    }
}

void paintStats(Frame* frame, struct winsize* window, size_t frameCount)
{
    size_t pixel = 1;
    char stats[40];
    sprintf(stats, "Width: %d, Height: %d, Frame: %d", window->ws_col, window->ws_row, frameCount);
    size_t offset = window->ws_col - 40;
    for (size_t i = 0; i < strlen(stats); i++) {
        frame->pixels[i + offset].code = stats[i];
    }
}

void paintBorder(Frame* frame, struct winsize* window)
{
    Color borderColor = {.r = 20, .g = 20, .b = 20};
    size_t pixel = 1;
    for (size_t y = 1; y < window->ws_row + 1; y++) {
        for (size_t x = 1; x < window->ws_col; x++) {
            if (y == 1 || y == window->ws_row) {
                frame->pixels[pixel - 1].bg = borderColor;
            } else {
                if (x == 1 || x == window->ws_col) {
                    frame->pixels[pixel - 1].bg = borderColor;
                }
            }
            pixel++;
        }
        pixel++;
    }
}
