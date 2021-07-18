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
}dll_t;

dll_t*
get_new_node();

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

#endif
