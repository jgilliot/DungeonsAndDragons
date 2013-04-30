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


// Sprite files : 
extern const unsigned char icone_orc_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : icone_Pal
extern const unsigned char icone_humain_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : icone_Pal
extern const unsigned char icone_elfe_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : icone_Pal
extern const unsigned char icone_gobelin_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : icone_Pal
extern const unsigned char icone_araignee_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : icone_Pal
extern const unsigned char icone_squelette_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : icone_Pal
extern const unsigned char icone_epee1_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : icone_Pal
extern const unsigned char classe_guerrier_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : classe_Pal
extern const unsigned char classe_archer_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : classe_Pal
extern const unsigned char classe_mage_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : classe_Pal
extern const unsigned char joueur_minimap_Sprite[64] __attribute__ ((aligned (4))) ;  // Pal : ui_Pal

// Background files : 
extern const int bg_blanc_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_blanc_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_blanc_Pal
extern const unsigned char bg_blanc_Tiles[64] __attribute__ ((aligned (4))) ;  // Pal : bg_blanc_Pal
extern PAGfx_struct bg_blanc; // background pointer

extern const int bg_cells_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_cells_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_cells_Pal
extern const unsigned char bg_cells_Tiles[448] __attribute__ ((aligned (4))) ;  // Pal : bg_cells_Pal
extern PAGfx_struct bg_cells; // background pointer


// Palette files : 
extern const unsigned short icone_Pal[239] __attribute__ ((aligned (4))) ;
extern const unsigned short classe_Pal[67] __attribute__ ((aligned (4))) ;
extern const unsigned short ui_Pal[2] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_blanc_Pal[2] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_cells_Pal[4] __attribute__ ((aligned (4))) ;


#endif

