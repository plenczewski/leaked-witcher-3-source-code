#include "events.h"
#include "controller.h"

void initialize_events(void){
	init_event_bus();
}

void run_hardware_events(void){
	int pad_read = PadRead(0);
	eb_send_event((struct EventBusEventCall){EB_E_TICK_EVENT});			// single tick event sent each time main loop is executed


	if (pad_read)
		eb_send_event((struct EventBusEventCall){EB_E_PAD_EVENT, pad_read});
}