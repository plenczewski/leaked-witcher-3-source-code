#include "point.h"

struct Point* new_point(unsigned short x, unsigned short y){
	struct Point* p =(struct Point*) malloc(sizeof(*p));
	p->x = x;
	p->y = y;
	return p;
}