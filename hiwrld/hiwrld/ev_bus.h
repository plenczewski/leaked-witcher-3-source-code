#ifndef EVENT_BUS_H
#define EVENT_BUS_H

#define EVENT_BUS_EVENT_TYPE short
#define EB_E_TICK_EVENT			1
#define EB_E_PAD_EVENT			2

struct EventBusEventCall{
	EVENT_BUS_EVENT_TYPE type;
	void* data;
};

void init_event_bus(void);
int eb_subscribe_to_events(void (*f)(struct EventBusEventCall));		// subscribes to event channel. returns subscriber address
void eb_unsubscribe(int subscriber_address);							// unsubscribes event channel.
void eb_send_event(struct EventBusEventCall event_call);

#endif