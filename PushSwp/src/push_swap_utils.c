/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:17:26 by elfo              #+#    #+#             */
/*   Updated: 2025/05/28 20:55:05 by elfo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

void	current_index(t_stack_node *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			match_index;

	while (a)
	{
		match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > match_index)
			{
				match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			match_index;

	while (b)
	{
		match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < match_index)
			{
				match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->p_cost = a->index;
		if (!(a->above_median))
			a->p_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->p_cost += a->target_node->index;
		else
			a->p_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->p_cost < cheapest_value)
		{
			cheapest_value = stack->p_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
