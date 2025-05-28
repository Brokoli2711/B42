#include "../includes/push_swap.h"
#include <limits.h>

void  current_index(t_stack_node *stack)
{
  int	i;
  int	median;

  i = 0;
  if (!stack)
    return ;
  median = stack_len(stack) / 2;
  while (stack) {
    stack->index = i;
    if (i <= median)
      stack->above_median = true;
    else
      stack->above_median = false;
    stack = stack->next;
    ++i;
  }
}

static void set_target_a(t_stack_node *a, t_stack_node *b) {
  t_stack_node *current_b;
  t_stack_node *target_node;
  long match_index;

  while (a) {
    match_index = LONG_MIN;
    current_b = b;
    while (current_b) {
      if (current_b->value < a->value && current_b->value > match_index) {
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

static void set_target_b(t_stack_node *a, t_stack_node *b) {
  t_stack_node *current_a;
  t_stack_node *target_node;
  long match_index;

  while (b) {
    match_index = LONG_MAX;
    current_a = a;
    while (current_a) {
      if (current_a->value > b->value && current_a->value < match_index) {
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
static void cost_analysis_a(t_stack_node *a, t_stack_node *b) {
  int len_a;
  int len_b;

  len_a = stack_len(a);
  len_b = stack_len(b);
  while (a) {
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

void	set_cheapest(t_stack_node *stack) {
  long cheapest_value;
  t_stack_node *cheapest_node;

  if (!stack)
    return;
  cheapest_value = LONG_MAX;
  while (stack) {
    if (stack->p_cost < cheapest_value) {
      cheapest_value = stack->p_cost;
      cheapest_node = stack;
    }
    stack = stack->next;
  }
  cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) {
  current_index(a);
  current_index(b);
  set_target_a(a, b);
  cost_analysis_a(a, b);
  set_cheapest(a);
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b) {
  current_index(a);
  current_index(b);
  set_target_b(a, b);
}

int	stack_len(t_stack_node *stack) //Define a function that calculates and returns the length of a stack
{
	int	count; //To store the node count

	if (!stack) 
		return (0);
	count = 0;
	while (stack) //Loop until the end of the stack is reached
	{
		stack = stack->next; //Move to the next node
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack) //Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack) //Define a function that searches a stack and returns the node with the smallest number
{
	long			min; //To store the smallest value so far
	t_stack_node	*min_node; //To store a pointer that points to the smallest number

	if (!stack)
		return (NULL);
	min = LONG_MAX; //Assign to the smallest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->value < min) //Check if the current node value is smaller than the smallest so far
		{
			min = stack->value; //If so, update the smallest number so far
			min_node = stack; //Set the pointer to point to the node with the smallest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (min_node); 
}

t_stack_node	*find_max(t_stack_node *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	t_stack_node	*max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->value > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->value; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}
