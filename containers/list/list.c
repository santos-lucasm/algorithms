#include "list.h"

#include <stdlib.h>
#include <stdio.h>

list_t* create_empty_list()
{
    printf("ENTERING %s\n", __func__);

    list_t* new_list = malloc( sizeof(list_t) );
    if(!new_list) // Bad alloc
        return NULL;
    
    new_list->_head = NULL;
    new_list->_tail = NULL;
}

int list_size(list_t* list)
{
    if(!list || !list->_head || !list->_tail)
        return 0;
    
    int size = 1;
    node_t* aux = list->_head;

    while(aux != list->_tail)
    {
        size++;
        aux = aux->_next;
    }
    return size;
}

int insert_front(list_t* list, void* data)
{
    printf("ENTERING %s\n", __func__);

    // Invalid parameters
    if(!list || !data)
        return false;

    // Create node to be inserted
    node_t* new_node = malloc( sizeof(node_t) );
    if(!new_node) // Bad alloc
        return false;
    new_node->_data = data;

    node_t* aux = list->_head;
    if(!aux) // Empty list
    {   
        new_node->_next = NULL;
        list->_head = new_node;
        list->_tail = new_node;
    }
    else
    {
        new_node->_next = list->_head;
        list->_head = new_node;
    }
    return true;
}

int insert_back(list_t* list, void* data)
{
    printf("ENTERING %s\n", __func__);

    // Invalid parameters
    if(!list || !data)
        return false;

    
    node_t* aux = list->_head;
    if(!aux) // Empty list, insert at front
    {
        return insert_front(list, data);
    }

    // Iterate until find tail
    while(aux != list->_tail)
    {
        aux = aux->_next;
    }

    node_t* new_node = malloc( sizeof(node_t) );
    if(!new_node) // Bad alloc
        return false;
    
    new_node->_data = data;
    new_node->_next = NULL;
    aux->_next = new_node;
    list->_tail = new_node;
}