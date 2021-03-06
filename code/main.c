#include "gba.h"
#include "drawing.h"

// type definitions
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;


/*
* Do nothing when in VBlank / HBlank
*/
inline void vsync()
{
  while (REG_VCOUNT >= 160);
  while (REG_VCOUNT < 160);
}

int main()
{
    REG_DISPLAYCONTROL = VIDEO_MODE | BG_MODE; //mode 3 graphics, we aren't actually using bg2 right now

    while(1)
	{
        vsync();
        tick();
	}

    return 0;
}