#ifndef COLOR_H
#define COLOR_H

struct Color {
	unsigned short red;
	unsigned short green;
	unsigned short blue;
};

struct Color* new_color(unsigned short red, unsigned short green, unsigned short blue);

#endif