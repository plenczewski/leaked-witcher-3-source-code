#include "rectangle.h"

struct Rectangle* new_rectangle(struct Point* p1, struct Point* p2, struct Point* p3, struct Point* p4){
	struct Rectangle* r = (struct Rectangle*) malloc(sizeof(*r));
	r->p1 = p1;
	r->p2 = p2;
	r->p3 = p3;
	r->p4 = p4;
	return r;
}

void draw_rectangle(struct Rectangle rect, struct Color c, struct Renderer* renderer){
	POLY_F4 pf4;
	struct Point p1 = *(rect.p1);
	struct Point p2 = *(rect.p2);
	struct Point p3 = *(rect.p3);
	struct Point p4 = *(rect.p4);
	SetPolyF4(&pf4);
	setXY4(&pf4, 
		p1.x, p1.y,
		p2.x, p2.y,
		p3.x, p3.y,
		p4.x, p4.y);
	setRGB0(&pf4, c.red, c.green, c.blue); 
	DrawPrim(&pf4);
	GsSortPoly(&pf4, &(renderer->ordering_table[*(renderer->current_buffer)]), 0);
}
void r_dispose(struct Rectangle* r){
	free(r->p1);
	free(r->p2);
	free(r->p3);
	free(r->p4);
	free(r);
};