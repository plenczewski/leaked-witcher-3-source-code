#ifndef LIST_H
#define LIST_H
#include "bool.h"
 
struct ListNode{
	void* current;
	struct ListNode* next;
};

struct LinkedList{
	struct ListNode* first_element;
	struct ListNode* last_element;
	long count;
};

struct LinkedList* new_linked_list();
int l_add_element(struct LinkedList* list, void* element);
BOOL l_is_empty(struct LinkedList list);
long l_count(struct LinkedList list);
void l_for_each(struct LinkedList* list, void (*f)(void*));
void l_for_each_scoped(struct LinkedList* list, void (*f)(void*, void*), void* scope);
void l_remove_at_index(struct LinkedList* list, int index);
void l_remove(struct LinkedList* list, struct ListNode* nodePtr);
void l_dispose(struct LinkedList* list);

#endif