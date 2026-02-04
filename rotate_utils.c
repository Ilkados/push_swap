/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:00:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/02 10:00:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *A, t_stack *B, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(A, B);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(A, B);
		(*ca)++;
		(*cb)++;
	}
}

void	bring_node_to_top_a(t_stack *A, int ca)
{
	while (ca > 0)
	{
		ra(A);
		ca--;
	}
	while (ca < 0)
	{
		rra(A);
		ca++;
	}
}

void	bring_node_to_top_b(t_stack *B, int cb)
{
	while (cb > 0)
	{
		rb(B);
		cb--;
	}
	while (cb < 0)
	{
		rrb(B);
		cb++;
	}
}

static t_node	*find_index0(t_stack *A)
{
	t_node	*cur;

	cur = A->top;
	while (cur)
	{
		if (cur->index == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	final_rotate_min_to_top(t_stack *A)
{
	t_node	*min;
	int		pos;
	int		steps;

	if (!A || A->size < 2)
		return ;
	set_positions(A);
	min = find_index0(A);
	if (!min)
		return ;
	pos = min->pos;
	if (pos <= A->size / 2)
	{
		steps = pos;
		while (steps-- > 0)
			ra(A);
	}
	else
	{
		steps = A->size - pos;
		while (steps-- > 0)
			rra(A);
	}
}
