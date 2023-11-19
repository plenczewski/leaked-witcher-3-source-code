#include "color.h"

struct Color* new_color(unsigned short red, unsigned short green, unsigned short blue){
	struct Color* c = (struct Color*)malloc(sizeof(*c));
	c->red = red;
	c->green = green;
	c->blue = blue; 
	return c;
}