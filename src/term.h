#ifndef TERM_H_
#define TERM_H_
#include "types.h"
#include "screen.h"
#include <stdio.h>
#include <sys/ioctl.h>

void clearScreen(void);
void resetScreen(void);
void drawFrame(Frame* frame, const Screen* screen);
void clearFrame(Frame* frame);
void hideCursor(void);
void moveCursor(u8 x, u8 y);
void showCursor(void);
void setPixel(const Pixel* pixel);

#endif // TERM_H_
