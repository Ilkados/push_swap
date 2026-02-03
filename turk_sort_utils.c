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

void	set_targets(t_stack *a, t_stack *b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	t_node	*min_a;
	t_node	*best;
	int		best_index;

	if (!a || !b || !a->Top)
		return ;
	min_a = min_index(a);
	cur_b = b->Top;
	while (cur_b)
	{
		best = NULL;
		best_index = INT_MAX;
		cur_a = a->Top;
		while (cur_a)
		{
			if (cur_a->index > cur_b->index
				&& cur_a->index < best_index)
			{
				best_index = cur_a->index;
				best = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best)
			cur_b->target = best;
		else
			cur_b->target = min_a;
		cur_b = cur_b->next;
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

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_node	*find_cheapest(t_stack *b)
{
	t_node	*cur;
	t_node	*best;
	int		best_score;
	int		score;

	if (!b || !b->Top)
		return (NULL);
	cur = b->Top;
	best = cur;
	best_score = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);
	cur = cur->next;
	while (cur)
	{
		score = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);
		if (score < best_score)
		{
			best = cur;
			best_score = score;
		}
		cur = cur->next;
	}
	return (best);
}