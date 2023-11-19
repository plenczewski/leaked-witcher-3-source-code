#include "g_main.h"

void g_init(void){
	set_world(new_world());
}

void doSth(void* elem){
	FntPrint(elem); 
	FntPrint(" "); 
}
void g_main(void){
    //struct Renderer* renderer = get_renderer();
	struct LinkedList* list = new_linked_list();
	l_add_element(list, "hello!"); 
	l_add_element(list, "my!"); 
	l_add_element(list, "friend!");
	l_for_each(list, doSth);
	l_remove_at_index(list, 1);
	l_for_each(list, doSth);
	FntPrint("\n"); 
	print_ptr(list);
	
	FntPrint("/");   
	FntPrint("/%d", l_is_empty(*list));  
	FntPrint("/%d",l_count(*list)); 
	l_dispose(list);
}