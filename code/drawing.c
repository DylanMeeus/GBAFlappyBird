#include "drawing.h"
#include "gba.h"


void colourPixel(int x, int y, uint16 colour){
    SCREEN_BUFFER[y * SCREEN_WIDTH + x] = colour;
}

void drawRectangle(int left, int top, int width, int height, uint16 clr)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
    	   SCREEN_BUFFER[(top + y) * SCREEN_WIDTH + left + x] = clr;
        }
    }
}


void drawLine(int startX, int startY, int endX, int endY, uint16 colour){
    int slope = (endY-startY) / (endX-startX);
    if(startX > endX){
        for(int x = startX; x <= endX; x++){
            int y = slope * (x-startX)+startY;
            colourPixel(x,y,colour);
        }
    } else {
        for(int x = endX; x >= startX; x--){
            int y = slope * (x-startX)+startY;
            colourPixel(x,y,colour);
        }
    }
}


void drawCircle(int centerX, int centerY, int radius, uint16 colour){

       int x = radius;
       int y = 0;
       int err = 0;

        while (x >= y)
        {
            drawLine(centerX - y, centerY + x, centerX + y, centerY + x, colour);
            drawLine(centerX - x, centerY + y, centerX + x, centerY + y, colour);
            drawLine(centerX - x, centerY - y, centerX + x, centerY - y, colour);
            drawLine(centerX - y, centerY - x, centerX + y, centerY - x, colour);


            y += 1;
            if (err <= 0)
            {
                err += 2*y + 1;
            }
            if (err > 0)
            {
                x -= 1;
                err -= 2*x + 1;
            }
        }
}

void drawCirclePerimeter(int centerX, int centerY, int radius){

       int x = radius;
       int y = 0;
       int err = 0;

        while (x >= y)
        {
            drawRectangle(centerX + x, centerY + y,1,1,700);
            drawRectangle(centerX + y, centerY + x,1,1,700);
            drawRectangle(centerX - y, centerY + x,1,1,700);
            drawRectangle(centerX - x, centerY + y,1,1,700);
            drawRectangle(centerX - x, centerY - y,1,1,700);
            drawRectangle(centerX - y, centerY - x,1,1,700);
            drawRectangle(centerX + y, centerY - x,1,1,700);
            drawRectangle(centerX + x, centerY - y,1,1,700);

            y += 1;
            if (err <= 0)
            {
                err += 2*y + 1;
            }
            if (err > 0)
            {
                x -= 1;
                err -= 2*x + 1;
            }
        }
}