#include "dll.h"
#include <stdlib.h>
#include <memory.h>

extern person_t;

int /* return 0 on success -1 on failure */
remove_data_from_dll_by_data_ptr(dll_t *dll, void *data) {
/*    if (!data)
        return -1;
    dll_node_t *temp;
    temp = dll->head;
    while (temp->right!=NULL)
    {
        if(((dll_node_t*)temp)->data->name == ((person_t)data)->name)
        {
            if(temp->left == NULL)
            {
                dll->start = tmp->right;
                temp->right = NULL;
                free(temp);
            }
            else if (temp->right == NULL)\/*last node *\/
            {
                temp->left->right = NULL;
                temp->left = NULL;
                free(temp);
            }
            else
            {
                temp->left->right = temp->right->left;
                temp->left=NULL;
                temp->right = NULL;
                free(temp);
            }
            return 0;
        }
        temp = temp->right; \/* move ahead in the list *\/

    }*/
    return 0;
}

int /* return 0 if empty , -1 if not empty */
is_dll_empty (dll_t *dll) {
    return 0;
}

void /* delete all nodes from a dll , but do not free appln data*/
drain_dll (dll_t *dll) {

}


