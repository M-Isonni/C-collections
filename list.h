#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void* data;
    struct node* next;
}node_t;

typedef struct list{
    node_t* head;
}list_t;

//creates a node with given datas -> linked list can contain pointers to any kind of datas
node_t* create_node(void* data);
//creates a list
list_t* make_list();
//adds item to list
void add_item(list_t* list, void* data);
//removes item from list both by index and data and free node memory
void remove_item(list_t* list, void* data);
void remove_at_index(list_t* list, int index);
//delete node freeing memory on heap
void delete_node(node_t* node);

//returns list size
int get_list_size(list_t* list);

//returns item from list without removing it both by index and data
node_t* get_item_from_index(list_t* list, int index);
node_t* get_item_from_data(list_t* list,void* data);