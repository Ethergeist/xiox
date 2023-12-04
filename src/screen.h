#ifndef SCREEN_H_
#define SCREEN_H_
#include "global.h"

#define MAX_ROWS 512

typedef struct Screen {
    u16 cols;
    u16 pixelCount;
    u16 rows;
    u16 rowStart[MAX_ROWS];
} Screen;

Screen* Screen_create(void);
bool Screen_updateSize(Screen *screen);
void Screen_destroy(Screen* screen);



#endif // SCREEN_H_
