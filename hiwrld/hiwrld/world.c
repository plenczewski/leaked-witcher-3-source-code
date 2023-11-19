#include "world.h"

struct World* __world;

struct World* new_world(void){
	struct World* world = (struct World*) malloc(sizeof(*world));
	world->game_objects=NULL;
	return world; 
}
struct World* get_world(void){
	return __world;
}
void set_world(struct World* world){
	__world = world;
}