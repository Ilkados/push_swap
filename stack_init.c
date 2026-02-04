/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:26:59 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 17:27:02 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_node	*new_node(int Value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = Value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_bottom(t_stack *stack, t_node *node)
{
	t_node	*old_botttom;

	if (!stack->top)
	{
		stack->size = 0;
		stack->bottom = node;
		stack->top = node;
		stack->size++;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		old_botttom = stack->bottom;
		node->prev = old_botttom;
		old_botttom->next = node;
		node->next = NULL;
		stack->bottom = node;
		stack->size++;
	}
}

int	init_stack_a(t_stack *stack, int *arr, int size)
{
	int		i;
	t_node	*node;

	if (!stack || !arr || size <= 0)
		return (0);
	i = 0;
	while (i < size)
	{
		node = new_node(arr[i]);
		if (!node)
		{
			free_stack(stack);
			return (0);
		}
		append_bottom(stack, node);
		i++;
	}
	return (1);
}
