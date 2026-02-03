/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:00:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/01/31 14:00:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_nodes(t_stack *s)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	if (!s || s->size < 2 || !s->Top || !s->Top->next)
		return (0);
	a = s->Top;
	b = a->next;
	c = b->next;
	s->Top = b;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	a->next = c;
	if (c)
		c->prev = a;
	else
		s->Bottom = a;
	return (1);
}

void	push_node(t_node *move, t_stack *to)
{
	t_node	*old_top;

	old_top = to->Top;
	move->next = old_top;
	old_top->prev = move;
	to->Top = move;
	to->size++;
}

int	push_node_to_stack(t_stack *from, t_stack *to)
{
	t_node	*move;

	if (!from || !to || !from->Top || from->size == 0)
		return (0);
	move = from->Top;
	from->Top = move->next;
	if (from->Top)
		from->Top->prev = NULL;
	else
		from->Bottom = NULL;
	from->size--;
	move->prev = NULL;
	move->next = NULL;
	if (!to->Top)
	{
		to->Top = move;
		to->Bottom = move;
		to->size++;
		return (1);
	}
	push_node(move, to);
	return (1);
}

int	rotate_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!s || s->size < 2 || !s->Top || !s->Top->next)
		return (0);
	first = s->Top;
	second = first->next;
	last = s->Bottom;
	s->Top = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	s->Bottom = first;
	return (1);
}

int	rev_rotate_stack(t_stack *s)
{
	t_node	*last;
	t_node	*before_last;

	if (!s || s->size < 2 || !s->Top || !s->Top->next)
		return (0);
	last = s->Bottom;
	before_last = last->prev;
	s->Bottom = before_last;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = s->Top;
	s->Top->prev = last;
	s->Top = last;
	return (1);
}
