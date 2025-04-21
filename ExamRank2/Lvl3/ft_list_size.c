#include "./ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 1;

	while(begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

t_list	*create_elem(void *data)
{
	t_list	*new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

int	main(void)
{
	t_list	*head = create_elem("uno");
	head->next = create_elem("dos");
	head->next->next = create_elem("tres");

	printf("Tamaño de la lista: %d\n", ft_list_size(head));

	// Liberar memoria
	t_list *tmp;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	return (0);
}
