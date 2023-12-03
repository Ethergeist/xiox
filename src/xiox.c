#include "drawing.h"
#include "term.h"
#include "types.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
int main(int argc, char** argv)
{
    struct winsize window;
    ioctl(0, TIOCGWINSZ, &window);
    size_t frameCount = 0;
    Frame* frame = (Frame*)malloc(sizeof(Frame) + (sizeof(Pixel) * window.ws_col * window.ws_row));
    if(frame == NULL) {
        return EXIT_SUCCESS;
    }
    frame->count = window.ws_col * window.ws_row;
    paintBackground(frame, &window);
    paintBorder(frame, &window);
    hideCursor();
    while (true) {
        paintStats(frame, &window, frameCount);
        drawFrame(frame, &window);
        frameCount++;
        moveCursor(1, 1);
    }
    showCursor();
    return 0;
}
