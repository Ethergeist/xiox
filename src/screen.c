#include "screen.h"
#include "global.h"

Screen* Screen_create(void)
{

    LOG_DEBUG("Creating Screen instance...%c", 0);
    Screen* screen = (Screen*)malloc(sizeof(Screen));
    if (screen == NULL) {
        LOG_ERROR("Unable to allocate memory for Screen data.%c", 0);
        return NULL;
    }
    if (Screen_updateSize(screen) == false) {
        Screen_destroy(screen);
        return NULL;
    }
    LOG_DEBUG("Screen instance created.%c", 0);
    return screen;
}

void Screen_onResize(int signo, siginfo_t* info, void* screen)
{
    LOG_DEBUG("Screen size changed.%c", 0);
    Screen_updateSize((Screen*)screen);
}

bool Screen_updateSize(Screen* screen)
{
    LOG_DEBUG("Updating Screen size...%c", 0);
    struct winsize window;
    if (ioctl(0, TIOCGWINSZ, &window) != 0) {
        LOG_ERROR("Failed to update Screen size%c", 0);
        LOG_PERROR("Unable to read ioctl data.");
        return false;
    }
    *screen = (Screen){
        .cols = window.ws_col,
        .pixelCount = window.ws_col * window.ws_row,
        .rows = window.ws_row,
    };
    screen->rowStart[0] = 0;
    for (size_t r = 1; r < MAX_ROWS; r++) {
        if (r >= screen->rows) {
            screen->rowStart[r] = 0;
            continue;
        }
        screen->rowStart[r] = screen->cols * r;
    }
    LOG_DEBUG("Screen size updated.%c", 0);
    return true;
}

void Screen_destroy(Screen* screen)
{
    LOG_DEBUG("Destroying Screen instance...%c", 0);
    if (screen == NULL) {
        LOG_WARN("Screen already NULL, skipping destruction.%c", '\0');
        return;
    }
    free(screen);
    screen = NULL;
    LOG_DEBUG("Screen instance destroyed.%c", 0);
}
