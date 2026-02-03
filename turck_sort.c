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

#include"push_swap.h"

void	Turk_sort(t_stack *a, t_stack *b)
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
