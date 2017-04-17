#include <stdint.h>
typedef struct node_t *list_p;


void list_create(list_p *list);
void list_destroy(list_p *head);
void add_item(list_p *head,void *item); 
int remove_item(list_p *head,void *item); 
int no_of_items(list_p *head); 
void *get_item(list_p *head, uint16_t index);
