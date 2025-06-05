/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:26:54 by elfo              #+#    #+#             */
/*   Updated: 2025/06/04 14:11:21 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_split(char **splited, char **argv)
{
	if (splited != argv + 1)
		ft_free_split(splited);
}

static void	sort(t_stack_node *a, t_stack_node *b)
{
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**splited;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		splited = split(*(&argv[1]), ' ');
		init_stack_a(&a, &splited[1], true);
	}
	else
	{
		splited = &argv[1];
		init_stack_a(&a, splited, false);
	}
	sort(a, b);
	free_stack(&a);
	free_stack(&b);
	check_split(splited, argv);
	return (0);
}
