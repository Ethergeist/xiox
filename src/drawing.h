#ifndef DRAWING_H_
#define DRAWING_H_
#include "term.h"
#include "types.h"

void paintBackground(Frame* frame, struct winsize* window);
void paintStats(Frame* frame, struct winsize* window, size_t frameCount);
void paintBorder(Frame* frame, struct winsize* window);


#endif // DRAWING_H_
