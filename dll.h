/* Header for Double linked list */

#ifndef __A__
#define __A__
typedef struct dll_node_{

    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
}dll_node_t;

typedef struct dll_{
    dll_node_t *head;
    /* Application will pass function to be used for matching */
    int (*key_match_function)(void *, void *);
    void (*print_db_function)(struct dll_ *);
    int (*comparison_function)(void *, void *);
}dll_t;

dll_t*
get_new_node();

void
register_key_match_callback(dll_t *, int (*key_match)(void*, void*));

void
register_print_callback(dll_t *, void (*print_function)(dll_t *));

void
register_comparison_callback(dll_t *, int (*comparison_function)(void*, void*));

void *
dll_search_by_key(dll_t *dll,void* key);

int
add_data_to_dll(dll_t *dll, void *app_data);

/*More function */

int /* return 0 on success -1 on failure */
remove_data_from_dll_by_data_ptr (dll_t *dll, void *data);

int /* return 0 if empty, -1 if not empty */
is_dll_empty (dll_t *dll);

/* Delete all nodes from a dll , but do not free appln data */
void
drain_dll (dll_t *dll);

#define ITERATE_LIST_BEGIN(dll, node) \
    {							 \
        dll_node_t * _node = NULL;                                     \
        node = dll->head;                                \
        for(;node!=NULL;node=_node)                       \
        {                                                \
            _node = node->right;                          \

#define ITERATE_LIST_END }}

#endif
