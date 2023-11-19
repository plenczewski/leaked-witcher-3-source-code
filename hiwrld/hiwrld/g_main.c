#include "g_main.h"
#include "ev_bus.h"
#include "events.h"

int subscriber_ptr;

void _event_handler(struct EventBusEventCall ev){
	printf("INFO: received event: %d with data: %d\n", ev.type, ev.data);
	//if(ev.type == EB_E_PAD_EVENT)
		//eb_unsubscribe(subscriber_ptr);
}

void g_init(void){
	struct World* world = new_world();
	printf("INFO: Created world with address: %p\n", world);
	initialize_events();
	printf("INFO: Initialized event bus\n");
	subscriber_ptr = eb_subscribe_to_events(_event_handler);
	set_world(world);
}
void g_main(void){
	run_hardware_events();
}