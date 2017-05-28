#include "drawing.h"
#include "gba.h"
#include "colour.h"
// represents a pipe in the game


typedef struct Pipe Pipe;

struct Pipe{
    int oldX;
    int oldWidth;
    int x;
    int width;
    int gapStart; // the pipes have the same 'gap' in between them. So we don't need to keep the endgap as well
};


void createPipe(Pipe* pipe, int x, int gapStart);

void updatePipe(Pipe* pipe);

void drawPipe(Pipe* pipe);