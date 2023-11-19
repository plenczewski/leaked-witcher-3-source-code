#ifndef STRUCTS_H
#define STRUCTS_H

#include "renderer.h"

struct Rectangle {
	struct Point* p1;
	struct Point* p2;
	struct Point* p3;
	struct Point* p4;
};

struct Rectangle* new_rectangle(struct Point* p1, struct Point* p2, struct Point* p3, struct Point* p4);
void draw(struct Rectangle r, struct Color c, struct Renderer* renderer);
void r_dispose(struct Rectangle* r);

#endif

