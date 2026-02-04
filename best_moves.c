/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:32:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/04 14:32:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_best_to_top(t_stack *A, t_stack *B, t_node *best)
{
	int	ca;
	int	cb;

	if (!A || !B || !best)
		return ;
	ca = best->cost_a;
	cb = best->cost_b;
	rotate_both(A, B, &ca, &cb);
	bring_node_to_top_a(A, ca);
	bring_node_to_top_b(B, cb);
}
