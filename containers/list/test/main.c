#include "../list.h"
#include <stdio.h>

void print_list(list_t* list)
{
    printf("ENTERING %s\n", __func__);

    if(!list)
        return;

    // Iterate until find tail
    node_t* aux = list->_head;
    while(aux != list->_tail)
    {
        printf("%d -> ", *((int*)aux->_data) );
        aux = aux->_next;
    }
    printf("%d\n", *((int*)aux->_data) );
}

int main()
{
    list_t* supermarket_list = create_empty_list();

    int rice = 6;
    int beans = 25;
    int tomato = 50;
    insert_back(supermarket_list, &rice);
    insert_front(supermarket_list, &beans);
    insert_back(supermarket_list, &tomato);

    print_list(supermarket_list);
    printf("List size: %d", list_size(supermarket_list));
}