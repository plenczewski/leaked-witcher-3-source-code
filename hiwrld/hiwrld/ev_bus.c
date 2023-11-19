#include "ev_bus.h"
#include "list.h"

struct LinkedList* __subscribers;

void init_event_bus(void){
	__subscribers = new_linked_list();
}
int eb_subscribe_to_events(void (*f)(struct EventBusEventCall)){
	return l_add_element(__subscribers, f);
}
void eb_unsubscribe(int subscriber_address){
	l_remove(__subscribers, subscriber_address);
}
void _on_event(void (*fn)(EventBusEventCall), struct EventBusEventCall* event_call){
	(*fn)(*event_call);
}

void eb_send_event(struct EventBusEventCall event_call){
	l_for_each_scoped(__subscribers, _on_event, &event_call);
}