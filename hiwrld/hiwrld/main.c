#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <rand.h>
#include <libetc.h>
#include "controller.c"
#include "color.h"
#include "debug.h"
#include "point.h"
#include "rectangle.h"
#include "triangle.h"
#include "renderer.h"
#include "world.h"
#include "g_main.h"

void init();
void gameLoop();
void update();

int main() 
{
	init();
	for (;;)  
		gameLoop();
	return 0;
}

struct Point* ball_point;
 
void init()
{ 
	ball_point = new_point(0, 0);
	graphics();  
	init_renderer(); 
	initializePad();
	ResetGraph(0);
	g_init();
}


void moveLeft()
{
	if(ball_point->x != 0)
		ball_point->x--;
}
void moveRight()
{
	if(ball_point->x != SCREEN_WIDTH)
		ball_point->x++;
}
void moveDown()
{
	if(ball_point->y <= SCREEN_HEIGHT)
		ball_point->y++;
}
void moveUp()
{
	if(ball_point->y != 0)
		ball_point->y--;
}
 
void update()
{  	
	// declarations
	struct Rectangle* r;
	struct Color* c;
	// initializations
	r = new_rectangle(
	new_point(0 + ball_point->x, 0 + ball_point->y), 
	new_point(0 + ball_point->x, 10 + ball_point->y),
	new_point(10 + ball_point->x, 0 + ball_point->y),
	new_point(10 + ball_point->x, 10 + ball_point->y)
	);
	c = new_color(102, 255, 153);  
	// body
	g_main(); 
	draw_rectangle(*r, *c, get_renderer());
	if (padCheck(Pad1Up)) 
		moveUp();
	if (padCheck(Pad1Down)) 
		moveDown();
	if (padCheck(Pad1Left)) 
		moveLeft();
	if (padCheck(Pad1Right)) 
		moveRight();  
	// destructions
	r_dispose(r);
	free(c);
}

void gameLoop()
{
	padUpdate();
	update();
	display();
}
