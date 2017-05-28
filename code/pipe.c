#include "pipe.h"
#include "time.h"
#include <stdlib.h>
#include <stdbool.h>

#define PIPE_WIDTH 20
#define GAP_HEIGHT 45
#define PIPE_SPEED  1 // how fast does the pipe move

bool timeInit = false;
void createPipe(Pipe* pipe, int x, int gapStart){
    pipe->x = x;
    pipe->gapStart = gapStart;
    pipe->width = PIPE_WIDTH;
    pipe->oldX = pipe->x;
    pipe->oldWidth = pipe->width;
    if(timeInit == false){
        srand(time(NULL));
        timeInit = true;
    }
}

void updatePipe(Pipe* pipe){
    pipe->oldX = pipe->x;
    pipe->oldWidth = pipe->width;
    if(pipe->x > 0){
        pipe->x -= PIPE_SPEED;
    } else {
        // Make the pipe disappear
        if(pipe->width > 0){
            pipe->width -= 1;
        } else {
            // the pipe is gone, start creating it again at the rightmost edge of the screen

            pipe->x = SCREEN_WIDTH-PIPE_WIDTH;
            pipe->gapStart = GAP_HEIGHT + rand()%100;
            pipe->width = PIPE_WIDTH;
        }
    }

}

void drawPipe(Pipe* pipe){


    // only delete the bit behind the pipe
    int height = SCREEN_HEIGHT - (pipe->gapStart + GAP_HEIGHT);
    drawRectangle( (pipe->oldX + pipe->oldWidth),0, PIPE_SPEED, SCREEN_HEIGHT, BLACK);
//    drawRectangle((pipe->oldX + pipe->oldWidth),pipe->gapStart + GAP_HEIGHT, PIPE_SPEED, SCREEN_HEIGHT, BLACK);

    // draw new pipes
    drawRectangle(pipe->x,0, pipe->width, pipe->gapStart, GREEN);
    drawRectangle(pipe->x,pipe->gapStart + GAP_HEIGHT, pipe->width, height, GREEN);
}