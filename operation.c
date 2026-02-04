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

	if (!s || s->size < 2 || !s->top || !s->top->next)
		return (0);
	a = s->top;
	b = a->next;
	c = b->next;
	s->top = b;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	a->next = c;
	if (c)
		c->prev = a;
	else
		s->bottom = a;
	return (1);
}

void	push_node(t_node *move, t_stack *to)
{
	t_node	*old_top;

	old_top = to->top;
	move->next = old_top;
	old_top->prev = move;
	to->top = move;
	to->size++;
}

int	push_node_to_stack(t_stack *from, t_stack *to)
{
	t_node	*move;

	if (!from || !to || !from->top || from->size == 0)
		return (0);
	move = from->top;
	from->top = move->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	move->prev = NULL;
	move->next = NULL;
	if (!to->top)
	{
		to->top = move;
		to->bottom = move;
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

	if (!s || s->size < 2 || !s->top || !s->top->next)
		return (0);
	first = s->top;
	second = first->next;
	last = s->bottom;
	s->top = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	s->bottom = first;
	return (1);
}

int	rev_rotate_stack(t_stack *s)
{
	t_node	*last;
	t_node	*before_last;

	if (!s || s->size < 2 || !s->top || !s->top->next)
		return (0);
	last = s->bottom;
	before_last = last->prev;
	s->bottom = before_last;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = s->top;
	s->top->prev = last;
	s->top = last;
	return (1);
}
