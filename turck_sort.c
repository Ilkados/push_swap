/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:20:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/02 10:20:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:20:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/02 10:20:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_abs(int x)
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

	if (!b || !b->top)
		return (NULL);
	cur = b->top;
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

void	turk_sort(t_stack *a, t_stack *b)
{
	t_node	*best;

	indexing_stack(a);
	while (a->size > 3)
		pb(a, b);
	tiny_sort_3(a);
	while (b->size)
	{
		set_positions(a);
		set_positions(b);
		set_targets(a, b);
		set_costs(a, b);
		best = find_cheapest(b);
		move_best_to_top(a, b, best);
		pa(b, a);
	}
	final_rotate_min_to_top(a);
}
