#include "dll.h"
#include <memory.h>
#include <stdlib.h>

dll_t*
get_new_dll(){

    dll_t *dll = calloc(1,sizeof(dll_t));
    dll->head = NULL;
    return dll;
}

void*
dll_search_by_key(dll_t *dll, void *key)
{
    if (!dll || dll->head == NULL || key == NULL)
        return;
    else
    {
        dll_node_t *start= dll->head;
        while(start != NULL)
        {
            if(dll->key_match_function((void*)start->data, key) == 0)
            {
                //printf("Record Found\n")
                return (void*)start->data;
            }
            start=start->right;
        }
    }
        return NULL;

}

void
print_db_function(dll_t *dll)
{
    if (!dll || dll->head == NULL)
        return;
    else
        dll->print_db_function(dll);
    return;

}

void
register_print_callback(dll_t *dll, void (*print_function)(dll_t*))
{
    dll->print_db_function = print_function;
    return;
}

void
register_key_match_callback(dll_t *dll, int (*key_match)(void*, void*))
{
    if (!dll)
        return;
    else
        dll->key_match_function = key_match;
    return;
}

void register_comparison_callback(dll_t *dll, int(*comparison_function)(void*, void*))
{
    dll->comparison_function= comparison_function;
}

int
dll_priority_insert(dll_t* dll, void* data)
{
    if (!dll || !data) return -1;
    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    if (!dll_new_node)
        return -1;
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = data;
    if (dll->head == NULL)
    {
        /* insert first node */
        dll->head = dll_new_node;
        return 0;
    }

    /* insertion at the beggining */
    if(dll->comparison_function(dll->head->data, data))
    {
        dll_new_node->right= dll->head;
        dll->head->left = dll_new_node;
        dll->head=dll_new_node;
        return 0;
    }

    else
    {
        dll_node_t *current = dll->head;
        while(current->right!=NULL && !(dll->comparison_function(current->right->data, data)))
        {
            current=current->right;
        }
        if (current->right == NULL) /* insertion at the end */
        {
            current->right = dll_new_node;
            dll_new_node->left = current;
            return 0;
        }
        /* loop breaks as soon as new node is smaller than current->right->data*/
        dll_new_node->right = current->right;
        current->right->left= dll_new_node;
        dll_new_node->left = current;
        current->right = dll_new_node;
        return 0;
    }
    return -1;
}

int
add_data_to_dll (dll_t *dll, void *app_data){
    if(!dll || !app_data) return -1;

    dll_node_t* dll_new_node = calloc(1, sizeof(dll_node_t));
    if (!dll_new_node)
        return -1;
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = app_data;

    if(dll->head == NULL)
    {
        dll->head = dll_new_node;
        return 0;
    }

    dll_node_t *first_node = dll->head;
    first_node->left = dll_new_node;
    dll_new_node->right = first_node;
    dll->head = dll_new_node;
    return 0;
}
