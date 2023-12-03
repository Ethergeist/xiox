#ifndef TERM_H_
#define TERM_H_
#include "types.h"
#include <stdio.h>
#include <sys/ioctl.h>

void clearScreen(void);
void drawFrame(Frame* frame, struct winsize* window);
void hideCursor(void);
void moveCursor(u8 x, u8 y);
void showCursor();
void setPixel(const Pixel* pixel);

#endif // TERM_H_
