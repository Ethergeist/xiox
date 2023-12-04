#include "drawing.h"
#include "global.h"
#include "screen.h"
#include "term.h"
#include <stdlib.h>

static Screen* screen;
static Frame* frame;
void onSignal(int sig);
void cleanup(void);

int main(int argc, char** argv)
{
    screen = Screen_create();
    Screen_updateSize(screen);
    frame = (Frame*)malloc(sizeof(Frame) + (sizeof(Pixel) * screen->rows * screen->cols));
    frame->count = screen->rows * screen->cols;
    struct sigaction sa = {0};
    sa.sa_handler = onSignal;
    sigemptyset(&(sa.sa_mask));
    sigaction(SIGINT, &sa, NULL);

    size_t frameCount = 0;
    paintBackground(frame, screen, frameCount);
    paintBorder(frame, screen);
    clearScreen();
    hideCursor();

    while (true) {
        sigaction(SIGWINCH, &sa, NULL);
        drawFrame(frame, screen);
        moveCursor(1, 1);
        frameCount++;
        clearFrame(frame);
        paintBackground(frame, screen, frameCount);
        paintBorder(frame, screen);
        paintStats(frame, screen, frameCount);
    }
    cleanup();
    return EXIT_SUCCESS;
}

void onSignal(int sig)
{
    switch (sig) {
        case SIGINT:
            cleanup();
            LOG_DEBUG("SIGINT encountered, exiting.%c", 0);
            exit(EXIT_SUCCESS);
            break;
        case SIGWINCH:
            LOG_DEBUG("Window size changed, updating Screen.%c", 0);
            Screen_updateSize(screen);
            clearFrame(frame);
            Frame* newFrame = (Frame*)realloc(frame, sizeof(Frame) + (sizeof(Pixel) * screen->rows * screen->cols));
            newFrame->count = screen->rows * screen->cols;
            clearScreen();
            if (newFrame == NULL) {
                LOG_PERROR("Unable to allocate new frame size.");
                cleanup();
                exit(EXIT_FAILURE);
            }
            frame = newFrame;
            break;
        default:
            break;
    }
}

void cleanup(void)
{
    Screen_destroy(screen);
    if (frame != NULL) {
        free(frame);
        frame = NULL;
    }
    resetScreen();
    clearScreen();
    showCursor();
    moveCursor(1,1);
}
