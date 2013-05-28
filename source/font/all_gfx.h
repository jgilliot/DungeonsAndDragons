//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Background files : 
extern const int newfont_Info[3]; // BgMode, Width, Height
extern const unsigned short newfont_Map[768] __attribute__ ((aligned (4))) ;  // Pal : newfont_Pal
extern const unsigned char newfont_Tiles[4352] __attribute__ ((aligned (4))) ;  // Pal : newfont_Pal
extern PAGfx_struct newfont; // background pointer


// Palette files : 
extern const unsigned short newfont_Pal[16] __attribute__ ((aligned (4))) ;


#endif

