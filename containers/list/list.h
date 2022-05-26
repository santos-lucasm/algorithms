#ifndef __LIST_H__
#define __LIST_H__

#define true 1
#define false 0

struct node
{
    void* _data;
    struct node* _next;
} typedef node_t;

struct list
{
    node_t* _head;
    node_t* _tail;
} typedef list_t;

list_t* create_empty_list();

int list_size(list_t* list);

int insert_front(list_t* list, void* data);

int insert_back(list_t* list, void* data);

#endif