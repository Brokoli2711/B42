#include "../includes/push_swap.h"

static void	rotate(t_stack_node **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack_node	*last_node; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print) //Rotate the top `b` node to the bottom of the stack, and print the instruction
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

void	rotate_both(t_stack_node **a,
		t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate(t_stack_node **stack) //Define a funtion that rotates a stack's bottom node, to the top
{
	t_stack_node	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
}

void	rra(t_stack_node **a, bool print) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}

static void	push(t_stack_node **dst, t_stack_node **src) //Define a function that pushes a top node, from one stack to another's top node
{
	t_stack_node	*push_node; //Used to store the pointer to the node to be pushed

	if (!*src) //The top node of a stack to be pushed
		return ;
	push_node = *src; //The top node to push is assigned to the `t_stack_node` variable
	*src = (*src)->next; //Move the pointer of the stack to the next node, which will become the next `top node` after the node before is "popped off"
	if (*src) //Check if the current node exists
		(*src)->prev = NULL; //Set the current node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from its stack
	if (!*dst) //Check if the other stack is empty
	{
		*dst = push_node; //If it's empty, assign as the first node of that stack, the node we want pushed
		push_node->next = NULL; //Ensure it is also set as the last node, e.g. properly null terminate the stack
	}
	else //If the other stack we want to push to is not empty
	{
		push_node->next = *dst; //Assign the node to push, to the top of the current top node of the stack
		push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		*dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

static void	swap(t_stack_node **head) //Define a function that swaps the positions of the top node and second node of a stack
{
	if (!*head || !(*head)->next) //Check if the stop node, or second node of a stack exists
		return ;
	*head = (*head)->next; //Update `head` to point to the next node, effectively swapping the first and second nodes
	(*head)->prev->prev = *head; //Update the `prev` pointer of the node before the `new head` to point to the `new head`
	(*head)->prev->next = (*head)->next; //Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
	if ((*head)->next) //Check if there's a `next` node after the `new head` and
		(*head)->next->prev = (*head)->prev; //If so, update its `prev` pointer to point back to the `new head`
	(*head)->next = (*head)->prev; //Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
	(*head)->prev = NULL; //Sets the `prev` pointer of the `new head` to `NULL` completing the swap
}

void	sa(t_stack_node	**a, bool print) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
