#ifndef POINT_H
#define POINT_H

struct Point{
	unsigned short x;
	unsigned short y;
};

struct Point* new_point(unsigned short x, unsigned short y);

#endif