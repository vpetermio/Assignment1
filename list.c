#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/*
@file list.c
@brief Manages lists.
@author Adam Szekely and Peter Varanic
*/

/*@brief The list node struct.*/
typedef struct node_t {
	void *content;
	struct node_t *next;
}node_t;

/*@brief Create a list.
@param[in] list pointer to a list.*/
void list_create(list_p *list){
	*list = NULL;
}

/*@brief Add an item to a specific list.
@param[in] head pointer to a list.
@param[in] item pointer to an item.*/
void add_item(list_p *head, void *item)
{
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->content = item;
	node->next = *head;
	*head = node;
}

/*@brief Return the number of items in a list.
@return The number of items.
@param[in] head pointer to a list.*/
int no_of_items(list_p *head)
{
	int count = 0;
	node_t *it = *head;

	while (it != NULL)
	{
		count++;
		it = it->next;
	}

	return count;
}

/*@brief Remove an item from a list.
@return 0:OK the item has been removed; -1:the item does not exist.
@param[in] head pointer to a list.
@param[in] item pointer to an item.*/
int remove_item(list_p *head, void* item)
{
	
	if (item==(*head)->content)
	{
		node_t *current_head = *head;
		*head = (*head)->next;
		free(current_head);
		return 0;
	}
	else {
		node_t *current = (*head)->next;
		node_t *prev = *head;
		int i = 1;
		while (current!=NULL) {
			if (item == current->content)
			{
				prev->next = current->next;
				free(current);
				return 0;
			}
			else {
				prev = current;
				current = current->next;
			}
		}
		return -1;
	}
}

/*@brief Return an item from a list.
@return The item; NULL:the list is empty.
@param[in] head pointer to a list.
@param[in] index the position of the item.*/
void *get_item(list_p *head, uint16_t index)
{
	//start from the first link
	node_t *current = *head;
	int i = 0;
	//if list is empty
	if (current == NULL) {
		
		return NULL;
	}
	else {
			while (i < index)
			{
				current = current->next;
				i++;
			}
			return current->content;
	}
}

