#include "list.h"
#define TRUE 1
#define FALSE 0

int main(){   
    printf("open\n"); 
    char* data = "ciao";
    int* value = malloc(sizeof(int));
    *value=5;
    list_t* list = make_list();
    add_item(list,data);
    add_item(list,value);
    node_t* node = get_item_from_index(list,0);
    node_t* node_2 = get_item_from_index(list,1);
    char* data_get = (char*)node->data;
    int val = *(int*)node_2->data;
    printf("done\n");
    printf("%s\n",data_get);
    printf("%d\n",val);
    int len = get_list_size(list);
    printf("length: %d\n",len);
    remove_at_index(list,1);  
    //freeing value pointer since node has been deleted from list and i don't need it anymore 
    free(value);
    len = get_list_size(list);
    printf("length: %d\n",len);
    return 0;
}