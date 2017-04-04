#include "list.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
	void *content;
	struct node_t *next;
}node_t;

void list_create(list_p *list){
	*list = NULL;
}

void list_destroy(list_p *head){
	
}
//Second way, when head is a pointer to node_t

//static node_t *head = NULL;
static int count = 0;

int add_item(list_p *head, void *item)
{

	node_t *node = (node_t *)malloc(sizeof(node_t));
	
	node->content = item;

	node->next = *head;
	
	*head = node;

}

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

int remove_item(list_p *head, void *item)
{
	static node_t *current = NULL;
	static node_t *prev = NULL;
	current = *head;
	prev = *head;
	while (current != NULL)
	{
		if (current->content == item)
		{
			if (current == *head)
			{
				*head = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			free(current);
			count--;
			return 0;
		}
		prev = current;
		current = current->next;
	}
	return -1;
}

list_p get_iterator(list_p *list)
{}

int has_next(list_p *iterator)
{}

void *next(list_p *iterator)
{}

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
			void *temp = current->content;
			return temp;	
	}
	
}
/*
void print_list(list_p *head)
{
	node_t *current = *head;

	while (current!= NULL)
	{
		printf("%d\n", *(int*)current->content);
		current = current->next;
	}
}*/
