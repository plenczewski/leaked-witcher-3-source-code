#include "list.h"

struct ListNode* _l_get_element_at(struct LinkedList* list, long index);

struct LinkedList* new_linked_list(){
	struct LinkedList* ll = (struct LinkedList*)malloc(sizeof(*ll));
	if (!ll)
		return NULL;
	ll->first_element = 0;
	ll->last_element = 0;
	ll->count = 0;
	return ll;
}

int l_add_element(struct LinkedList* list, void* element){
	struct ListNode* last_node = list->last_element;
	struct ListNode* new_list_node = (struct ListNode*)malloc(sizeof(*new_list_node));
	if (!new_list_node)
		return NULL;

	new_list_node->current = element;
	new_list_node->next = 0;

	if (last_node)
		last_node->next = new_list_node;
	else
		list->first_element = new_list_node;

	list->last_element = new_list_node;
	list->count++;
	return new_list_node;
}

BOOL l_is_empty(struct LinkedList list){
	return l_count(list) == 0;
}

long l_count(struct LinkedList list){
	return list.count;
}

void l_for_each(struct LinkedList* list, void (*f)(void*)){
	struct ListNode* next_elem_ptr = list->first_element;
	while (next_elem_ptr) {
		(*f)(next_elem_ptr->current);
		next_elem_ptr = next_elem_ptr->next;
	}
}
void l_for_each_scoped(struct LinkedList* list, void (*f)(void*, void*), void* scope){
	struct ListNode* next_elem_ptr = list->first_element;
	while (next_elem_ptr) {
		(*f)(next_elem_ptr->current, scope);
		next_elem_ptr = next_elem_ptr->next;
	}
}
void l_remove_at_index(struct LinkedList* list, int index){
	struct ListNode* previous = NULL;
	struct ListNode* toRemove = NULL;
	struct ListNode* next = NULL;
	if (index < 0)
		return;
	if (index >= l_count(*list))
		return;
	if (index == 0)
	{
		toRemove =(struct ListNode*) _l_get_element_at(list, index);
		next = toRemove->next;
	}
	else {
		previous =(struct ListNode*) _l_get_element_at(list, index - 1);
		toRemove = previous->next;
		if(toRemove)
			next = toRemove->next;
	}
	if(!toRemove)
		return;
	// trying to remove in the middle
	else if (previous && next)
		previous->next = next;
	else if (!previous && !next)
		list->first_element = NULL;
	// trying to remove first
	else if (!previous && next)
		list->first_element = next;
	// trying to remove last
	else if (previous && !next)
		previous->next = 0;
	list->count--;
	free(toRemove);
}
void l_remove(struct LinkedList* list, struct ListNode* nodePtr){
	long index = _l_index_of(list, nodePtr);
	l_remove_at_index(list, index);
}
long _l_index_of(struct LinkedList* list, struct ListNode* nodePtr){
	struct ListNode* previous = list->first_element;
	long i = 0;
	while(previous && previous != nodePtr){
		previous = previous->next;
		i++;
	}
	if(!previous)
		return -1;
	return i;
}

void l_dispose(struct LinkedList* list) {
	struct ListNode* node_to_remove = list->first_element;
	struct ListNode* current = NULL;
	while (node_to_remove) {
		current = node_to_remove;
		node_to_remove = current->next;
		free(current);
	}
	free(list);
}

struct ListNode* _l_get_element_at(struct LinkedList* list, long index) {
	struct ListNode* next_elem_ptr = list->first_element;
	long i;
	if (index < 0) return 0;
	for (i = 0; i < index; i++)
		next_elem_ptr = next_elem_ptr->next;
	return next_elem_ptr;
}