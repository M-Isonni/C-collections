#include "list.h"

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