#ifndef __LIST_H__
#define __LIST_H__

struct node
{
    void* _data;
    node* _next;
} typedef node_t;

struct list
{
    node* _head;
    node* _tail;
} typedef list_t;

#endif