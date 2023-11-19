#ifndef RENDERER_H
#define RENDERER_H
#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#define OT_LENGTH 100 // the ordertable length
#define PACKETMAX 500 // the maximum number of objects on the screen
#define SCREEN_WIDTH  320 // screen width
#define	SCREEN_HEIGHT 240 // screen height (240 NTSC, 256 PAL) 

struct Renderer{
	short* current_buffer;
	GsOT* ordering_table;
};


void graphics();
void display();
void init_renderer();
struct Renderer* get_renderer();

#endif