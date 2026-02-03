/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:16:44 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 22:16:47 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b)
{
	swap_nodes(b);
	write(1, "sb\n", 3);
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rrb(t_stack *b)
{
	rev_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	pb(t_stack *a, t_stack *b)
{
	push_node_to_stack(a, b);
	write(1, "pb\n", 3);
}
