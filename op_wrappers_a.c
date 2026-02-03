/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:14:25 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 22:14:28 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap_nodes(a);
	write(1, "sa\n", 3);
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	rev_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	pa(t_stack *b, t_stack *a)
{
	push_node_to_stack(b, a);
	write(1, "pa\n", 3);
}
