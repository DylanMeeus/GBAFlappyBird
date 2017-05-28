#include "gba.h"
#include "drawing.h"
#include "colour.h"
// the bird itself

typedef struct Flappy Flappy;
struct Flappy{
    int y;
    int x; // bird will stand still normally
    int velY;
    int size;
};

// draw the 'bird'
void drawFlappy(Flappy* flappy);
// update the birds position
void updateFlappy(Flappy* flappy);

void createFlappy(Flappy* flappy, int posX, int posY, int size);

// called when flappy needs to react to input
void flappyAction(Flappy* flappy);