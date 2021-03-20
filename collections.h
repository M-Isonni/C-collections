#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MODIFIER 31

typedef struct node
{
    void* data;
    struct node* next;
}node_t;

typedef struct list
{
    node_t* head;
}list_t;

typedef struct key_value_pair
{
    void* key;
    void* value;
    size_t key_size;
    struct key_value_pair* next;
}key_value_pair_t;

typedef struct dictionary
{
    unsigned long size;
    size_t hash_map_size;
    key_value_pair_t** hash_map;
}dictionary_t;

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


//creates dictionary
dictionary_t* make_dict(const size_t hash_map_size);
//algorythm for hasing
unsigned int hashing(const void* key,unsigned int hash_size);
//add item to dictionary
key_value_pair_t* add_item_to_dict(dictionary_t* dict, void* key, void*value, size_t key_len);
//gets item from dictionary by key
key_value_pair_t* get_item_from_dict(dictionary_t* dict, void* key, size_t key_len);
//removes item from dictionary and frees space
void remove_item_from_dict(dictionary_t* dict, void* key, size_t key_len);