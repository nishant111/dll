#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct person_ {
    char *name;
    int id;
    int age;
    int weight;
}person_t;

typedef struct car_{
    char *name;
    char *chasisNo;
    int makeYear;
    char *makeCompany;
}car_t;

static void print_person_details(person_t* person)
{
    printf("Person name is %s\n", person->name);
    printf("Person ID is %d\n", person->id);
    printf("person age is %d\n", person->age);
    printf("person weight is %d\n", person->weight);

}

static void print_car_details(car_t *car)
{
    printf("car name is %s\n", car->name);
    printf("car chasisNo is %s\n", car->chasisNo);
    printf("car makeYear is %d\n", car->makeYear);
    printf("car Make Company is %s\n", car->makeCompany);
}

int match_person_by_key(void *data, void *key)
{
    person_t *person = (person_t *)data;
    int id= *(int*)key;
    if (person->id == id)
        return 0;
    return -1;

}

int match_car_by_key(void *data, void *key)
{
    car_t *car = (car_t*) data;
    char *chasis = (char*) key;
    if(strcmp(car->chasisNo,chasis)==0)
        return 0;
    return -1;

}

void print_person_db(dll_t *person_db)
{
    //dll_t* person_db=(dll_t*) person_db;
    if (!person_db || !person_db->head)
         return;
    dll_node_t *start = person_db->head;
    printf("***************Person DB ***********\n");
    while(start!=NULL)
    {
        print_person_details(start->data);
        start = start->right;
    }
    printf("**************Person DB end********\n");
    return;

}

void print_car_db(dll_t *car_db)
{
    if(!car_db || !car_db->head)
        return;
    dll_node_t *start = car_db->head;
    printf("************Car DB ******************\n");
    while(start!=NULL)
    {
        print_car_details(start->data);
        start=start->right;
    }
    printf("**************Car DB end*************\n");
    return;
}

int comparison_person(void *existingData, void *newData)
{
    person_t *existingPerson = (person_t*) existingData;
    person_t *newPerson = (person_t*) newData;
    if (existingPerson->age > newPerson->age)
        return 1; /*New node is smaller */
    else
        return 0;
}

int main (int argc, char **argv)
{
    dll_t* person_db=get_new_dll();
    dll_t* car_db=get_new_dll();

    person_t *person1 = calloc(1,sizeof(person_t));
    person_t *person2 = calloc(1, sizeof(person_t));
    person_t *person3 = calloc(1, sizeof(person_t));
    person_t *person4 = calloc(1,sizeof(person_t));
    person_t *person5 = calloc(1, sizeof(person_t));
    person_t *person6 = calloc(1, sizeof(person_t));

    car_t *car1 = calloc(1,sizeof(car_t));

    person1->name = "alice";  /* Read only string in RO data segment */
    person1->id = 1;
    person1->age = 20;
    person1->weight =55;
    person2->name="alex";
    person2->id = 2;
    person2->age=35;
    person2->weight=67;
    person3->name="alexa";
    person3->id = 3;
    person3->age=16;
    person3->weight=56;
    person4->name = "john";  /* Read only string in RO data segment */
    person4->id = 7;
    person4->age = 77;
    person4->weight =55;
    person5->name = "shawn";  /* Read only string in RO data segment */
    person5->id = 20;
    person5->age = 10;
    person5->weight =55;
    person6->name = "Brock";  /* Read only string in RO data segment */
    person6->id = 21;
    person6->age = 88;
    person6->weight =55;

    car1->name = "Creta";
    car1->chasisNo = "AABBCC";
    car1->makeYear = 2021;
    car1->makeCompany = "hyundai";

    register_print_callback(person_db, print_person_db);
    register_key_match_callback(person_db, match_person_by_key);
    register_comparison_callback(person_db, comparison_person);
    register_print_callback(car_db, print_car_db);
    register_key_match_callback(car_db, match_car_by_key);

    dll_priority_insert(car_db, car1);
    dll_priority_insert(person_db, person1);
    dll_priority_insert(person_db, person2);
    dll_priority_insert(person_db, person3);
    dll_priority_insert(person_db, person4);
    dll_priority_insert(person_db, person5);
    dll_priority_insert(person_db, person6);

    print_db_function(person_db);
    print_db_function(car_db);
    int id=1;
    person_t *found_node = (person_t*) dll_search_by_key(person_db,(void*)&id);
    if (found_node != NULL)
    {
        printf("found the node, printing it below\n");
        print_person_details(found_node);
    }
    else
        printf("could not find the node\n");
    //print_person_db(person_db);
    //print_car_db(car_db);
    return 0;
}
