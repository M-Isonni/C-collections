#include "collections.h"

node_t* create_node(void* data){
    node_t* new_node = malloc(sizeof(node_t));
    if(!new_node){
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

list_t* make_list(){
    list_t* new_list = malloc(sizeof(list_t));
    new_list->head = NULL;
    return new_list;
}

void add_item(list_t* list, void* data){
    if(list->head==NULL){
        list->head=create_node(data);
        return;
    }
    node_t* current_node = list->head;
    while(current_node->next!=NULL){
        current_node = current_node->next;
    }
    current_node->next=create_node(data);
}

void delete_node(node_t* node){    
    free(node);
}

void remove_item(list_t* list, void* data){
    node_t* current = list->head;
    if(!current){
        return;
    }
    node_t* prev = NULL;
    while(current->data!=data){
        prev = current;
        current=current->next;
    }
    if(prev!=NULL){
        prev->next = current->next;
    }
    delete_node(current);

}

void remove_at_index(list_t* list, int index){
    int current_index = 0;
    node_t* current = list->head;
    if(!current){
        return;
    }
    node_t* prev = NULL;
    while(current_index!=index){
        current_index++;
        prev = current;
        current=current->next;
    }
    if(prev!=NULL){
        prev->next = current->next;
    }
    delete_node(current);

}


node_t* get_item_from_index(list_t* list,int index){
    int current_index = 0;
    node_t* node = list->head;
    if(!node){
        return NULL;
    }
    while(current_index!=index){
        current_index++;
        node=node->next;
    }
    return node;
}

node_t* get_item_from_data(list_t* list,void* data){
    node_t* node = list->head;
    if(!node){
        return NULL;
    }
    while(node->data!=data){
        node=node->next;
    }
    return node;
}

int get_list_size(list_t* list){
    int counter = 0;
    node_t* current = list->head;
    if(!current){
        return counter;
    }
    while (current!=NULL){
        counter++;
        current = current->next;
    }
    return counter;
    
}


dictionary_t *make_dict(const size_t hash_map_size)
{
    dictionary_t *new_dict = malloc(sizeof(dictionary_t));
    if (!new_dict)
        return NULL;
    size_t hash_map_memory_size = sizeof(key_value_pair_t *) * hash_map_size;
    new_dict->hash_map = malloc(hash_map_memory_size);
    if (!new_dict->hash_map)
    {
        free(new_dict);
        return NULL;
    }
    memset(new_dict->hash_map, 0, hash_map_memory_size);
    new_dict->hash_map_size = hash_map_size;
    return new_dict;
}

key_value_pair_t *add_item_to_dict(dictionary_t *dict, void *key, void *value, size_t key_size)
{
    int hash = hashing(key, dict->hash_map_size);
    key_value_pair_t *current = dict->hash_map[hash];
    key_value_pair_t *prev = current;
    if (!current)
    {
        key_value_pair_t *new_item = malloc(sizeof(key_value_pair_t));
        new_item->key = key;
        new_item->value = value;
        new_item->next = NULL;
        new_item->key_size = key_size;
        dict->hash_map[hash] = new_item;
        return new_item;
    }
    while (current)
    {
        prev = current;
        current = current->next;
    }
    key_value_pair_t *new_item = malloc(sizeof(key_value_pair_t));
    new_item->key = key;
    new_item->value = value;
    new_item->next = NULL;
    new_item->key_size = key_size;
    prev->next = new_item;
    return new_item;
}

key_value_pair_t *get_item_from_dict(dictionary_t *dict, void *key, size_t key_size)
{
    int hash = hashing(key, dict->hash_map_size);
    key_value_pair_t *current = dict->hash_map[hash];
    if (!current)
    {
        return NULL;
    }
    while (current)
    {
        if (current->key_size == key_size && !memcmp(current->key,key, key_size))
        {           
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void remove_item_from_dict(dictionary_t *dict, void *key, size_t key_size)
{
    int hash = hashing(key, dict->hash_map_size);
    key_value_pair_t *current = dict->hash_map[hash];
    key_value_pair_t* last = current;
    if (!current)
    {
        return;
    }
    while (current)
    {
        if (current->key_size == key_size && !memcmp(current->key,key, key_size))
        {
            if(!last){
                dict->hash_map[hash]=current->next;
                free(current);
                return;
            }
            last->next = current->next;
            free(current);
            return;
            //return current;
        }
        last = current;
        current = current->next;
    }
    return;
}

unsigned int hashing(const void *key, unsigned int hashsize)
{
    unsigned hashval;
    int size = sizeof(key);
    unsigned char *value = (unsigned char *)(key);
    int i;
    for (i = 0; i < size; i++)
        hashval = size * (*value) + HASH_MODIFIER * hashval;
    return hashval % hashsize;
}