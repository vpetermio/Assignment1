#pragma once
#include <stdint.h>
typedef struct node *list_p;

void list_create(list_p *list);
void list_destroy(list_p *head);
int add_item(list_p *head,void *item); // Return 0 if item added else -1
int remove_item(list_p *head,void *item); // Return 0 if item removed else -1
int no_of_items(); // Return number of items in list
list_p get_iterator(list_p *list);
int has_next(list_p *iterator);
void *next(list_p *iterator);
void *get_item(list_p *head, uint16_t index);
void print_list(list_p *head);
