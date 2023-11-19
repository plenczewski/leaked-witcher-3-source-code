#ifndef WORLD_H
#define WORLD_H
#include "bool.h"

struct World{
	struct LinkedList* game_objects;
};

struct World* new_world(void);
struct World* get_world(void);
void set_world(struct World* world);
void dispose_world(void);

#endif