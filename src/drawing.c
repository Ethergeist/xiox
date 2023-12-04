#include "drawing.h"
#include <stdint.h>

void paintBackground(Frame* frame, const Screen* screen, const size_t delta)
{
    Color bgColor = {.r = 150, .g = 40, .b = 150};
    size_t pixel = 1;
    for (size_t y = 1; y < screen->rows; y++) {
        for (size_t x = 1; x < screen->cols; x++) {
            u8 amount = (u8)(sin((x + (delta / 30) % 360)) * 10) % 20;
            amount += 20;
            u8 offset = y - amount;
            frame->pixels[pixel - 1].bg = y < amount ? (Color){1, 1, 1}
                                                     : (Color){
                                                           1 + (bgColor.r / screen->rows) * offset,
                                                           1 + (bgColor.g / screen->rows) * offset,
                                                           1 + (bgColor.b / screen->rows) * offset,
                                                       };
            pixel++;
        }
        pixel++;
    }
}

void paintStats(Frame* frame, const Screen* screen, size_t frameCount)
{
    size_t pixel = 1;
    char stats[40];
    sprintf(stats, "Width: %d, Height: %d, Frame: %d", screen->cols, screen->rows, frameCount);
    size_t offset = screen->cols - 40;
    for (size_t i = 0; i < strlen(stats); i++) {
        frame->pixels[i + offset].code = stats[i];
    }
}

void paintBorder(Frame* frame, const Screen* screen)
{
    Color borderColor = {.r = 30, .g = 30, .b = 30};
    Color textColor = {.r = 32, .g = 200, .b = 80};
    size_t pixel = 1;
    for (size_t y = 1; y < screen->rows; y++) {
        for (size_t x = 1; x < screen->cols; x++) {
            if (y == 1 || y == screen->rows - 1) {
                frame->pixels[pixel - 1].bg = borderColor;
                frame->pixels[pixel - 1].fg = textColor;
            } else {
                if (x == 1 || x == screen->cols - 1) {
                    frame->pixels[pixel - 1].bg = borderColor;
                    frame->pixels[pixel - 1].fg = textColor;
                }
            }
            pixel++;
        }
        pixel++;
    }
}
