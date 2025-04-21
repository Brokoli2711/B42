#include "./ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void    plusone(void* h)
{
    t_list *n;

    n = (t_list *)h;
    n->data = "P";
}

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list->next)
    {
        (*f)(begin_list);
        begin_list = begin_list->next;
    }
}

t_list  *create_elem(void *data)
{
    t_list *new_elem = malloc(sizeof(t_list));
    if (!new_elem)
        return (NULL);
    new_elem->data = data;
    new_elem->next = NULL;
    return (new_elem);
}

int main(void)
{
    t_list  *head = create_elem("1");
    head->next = create_elem("2");
    head->next->next = create_elem("3");

    ft_list_foreach(head, plusone);
    while(head->next)
    {
        printf("%s", (char *)head->data);
        head = head->next;
    }
    t_list *tmp;
    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}
