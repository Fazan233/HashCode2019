//
// Created by Vladyslav USLYSTYI on 2019-02-24.
//

#include "pizza.h"

t_stack	*create_stack(int total, t_point *start, t_point *end)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->next = NULL;
	stack->total = total;
	stack->a.x = start->x;
	stack->a.y = start->y;
	stack->b.x = end->x;
	stack->b.y = end->y;
	return (stack);
}

void	push_stack(t_stack **stack, t_stack *item)
{
	if (*stack == NULL)
		*stack = item;
	else
	{
		item->next = *stack;
		item->total = item->total + (*stack)->total;
		*stack = item;
	}
}

void	pop_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}



t_stack	*copy_stack(t_stack *stack)
{
	t_stack *copy;
	int total;

	copy = NULL;
	total = stack->total;
	while (stack)
	{
		push_stack(&copy, create_stack(stack->total, &stack->a, &stack->b));
		stack = stack->next;
	}
	copy->total = total;
	return (copy);
}