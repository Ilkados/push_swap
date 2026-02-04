/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:00:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/02 12:00:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min_index(t_stack *a)
{
	t_node	*cur;
	t_node	*min;

	if (!a || !a->top)
		return (NULL);
	cur = a->top;
	min = cur;
	while (cur)
	{
		if (cur->index < min->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*find_target_in_a(t_stack *a, t_node *b)
{
	t_node	*cur;
	t_node	*best;
	t_node	*min;

	best = NULL;
	min = min_index(a);
	cur = a->top;
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

void	set_targets(t_stack *a, t_stack *b)
{
	t_node	*cur;

	if (!a || !b)
		return ;
	cur = b->top;
	while (cur)
	{
		cur->target = find_target_in_a(a, cur);
		cur = cur->next;
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
	cur = b->top;
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
