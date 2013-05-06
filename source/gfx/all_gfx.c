//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "icone_orc.c"
#include "icone_humain.c"
#include "icone_elfe.c"
#include "icone_gobelin.c"
#include "icone_araignee.c"
#include "icone_squelette.c"
#include "icone_epee1.c"
#include "classe_guerrier.c"
#include "classe_archer.c"
#include "classe_mage.c"
#include "joueur_minimap.c"
#include "bouton_attaque.c"
#include "bouton_sort.c"
#include "bouton_objet.c"
#include "bouton_passer.c"
#include "bouton_fuite.c"

// Background files : 
#include "bg_blanc.c"
#include "bg_cells.c"
#include "bg_combat_bot.c"
#include "bg_combat_top.c"

// Palette files : 
#include "icone.pal.c"
#include "classe.pal.c"
#include "ui.pal.c"
#include "bg_blanc.pal.c"
#include "bg_cells.pal.c"
#include "bg_combat_bot.pal.c"
#include "bg_combat_top.pal.c"

// Background Pointers :
PAGfx_struct bg_blanc = {(void*)bg_blanc_Map, 768, (void*)bg_blanc_Tiles, 64, (void*)bg_blanc_Pal, (int*)bg_blanc_Info };
PAGfx_struct bg_cells = {(void*)bg_cells_Map, 768, (void*)bg_cells_Tiles, 448, (void*)bg_cells_Pal, (int*)bg_cells_Info };
PAGfx_struct bg_combat_bot = {(void*)bg_combat_bot_Map, 768, (void*)bg_combat_bot_Tiles, 1664, (void*)bg_combat_bot_Pal, (int*)bg_combat_bot_Info };
PAGfx_struct bg_combat_top = {(void*)bg_combat_top_Map, 768, (void*)bg_combat_top_Tiles, 1792, (void*)bg_combat_top_Pal, (int*)bg_combat_top_Info };


#ifdef __cplusplus
}
#endif

