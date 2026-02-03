#include "push_swap.h"
#include <limits.h>

t_node	*min_index(t_stack *a)
{
	t_node	*cur;
	t_node	*min;

	if (!a || !a->Top)
		return (NULL);
	cur = a->Top;
	min = cur;
	while (cur)
	{
		if (cur->index < min->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*find_target_in_a(t_stack *A, t_node *b)
{
	t_node	*cur;
	t_node	*best;
	t_node	*min;

	best = NULL;
	min = min_index(A);
	cur = A->Top;
	while (cur)
	{
		if (cur->index > b->index
			&& (!best || cur->index < best->index))
			best = cur;
		cur = cur->next;
	}
	if (best)
		return (best);
	return (min);
}
void	set_targets(t_stack *A, t_stack *B)
{
	t_node	*b;

	if (!A || !B)
		return ;
	b = B->Top;
	while (b)
	{
		b->target = find_target_in_a(A, b);
		b = b->next;
	}
}

static int	calc_cost(int pos, int size)
{
	if (size <= 1)
		return (0);
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}

void	set_costs(t_stack *a, t_stack *b)
{
	t_node	*cur;

	if (!a || !b)
		return ;
	cur = b->Top;
	while (cur)
	{
		cur->cost_b = calc_cost(cur->pos, b->size);
		if (cur->target)
			cur->cost_a = calc_cost(cur->target->pos, a->size);
		else
			cur->cost_a = 0;
		cur = cur->next;
	}
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}


