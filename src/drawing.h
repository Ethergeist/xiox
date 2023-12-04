#ifndef DRAWING_H_
#define DRAWING_H_
#include "term.h"
#include "types.h"
#include "screen.h"
#include <math.h>

void paintBackground(Frame* frame, const Screen* screen, const size_t frameCount);
void paintStats(Frame* frame, const Screen* screen, const size_t frameCount);
void paintBorder(Frame* frame, const Screen* screen);

#endif // DRAWING_H_
