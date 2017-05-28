#ifndef DRAWING_H
#define DRAWING_H

typedef unsigned short  uint16;


void drawCircle(int centerX, int centerY, int radius,uint16 colour);
void drawCirclePerimeter(int centerX, int centerY, int radius);
void drawLine(int startX, int startY, int endX, int endY,uint16 colour);
void drawRectangle(int left, int top, int width, int height, uint16 clr);
void colourPixel(int x, int y, uint16 colour);

#endif