#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct person_ {
    char *name;
    int age;
    int weight;
}person_t;

static void print_person_details(person_t* person)
{
    printf("Person name is %s\n", person->name);
    printf("person age is %d\n", person->age);
    printf("person weight is %d\n", person->weight);

}

static void print_person_db(dll_t *person_db)
{
    if (!person_db || !person_db->head)
         return;
    dll_node_t *start = person_db->head;
    while(start!=NULL)
    {
        print_person_details(start->data);
        start = start->right;
    }

}

int main (int argc, char **argv)
{
    dll_t* person_db=get_new_dll();
    person_t *person1 = calloc(1,sizeof(person_t));
    person_t *person2 = calloc(1, sizeof(person_t));
    person_t *person3 = calloc(1, sizeof(person_t));
    person1->name = "alice";  /* Read only string in RO data segment */
    person1->age = 20;
    person1->weight =55;
    person2->name="alex";
    person2->age=35;
    person2->weight=67;
    person3->name="alexa";
    person3->age=23;
    person3->weight=56;
    add_data_to_dll(person_db, person1);
    add_data_to_dll(person_db, person2);
    add_data_to_dll(person_db, person3);
    print_person_db(person_db);
    return 0;
}
