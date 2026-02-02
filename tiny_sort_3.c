/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.Firstr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:09:13 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 18:09:16 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort_3(t_stack *A)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = A->Top;
	second = first->next;
	third = A->Bottom;
	if (first->value < second->value && second->value < third->value)
		return ;
	else if (swap(first, second, third))
		sa(A);
	else if (swap_and_rotate_rev(first, second, third))
	{
		sa(A);
		rra(A);
	}
	else if (rotate(first, second, third))
		ra(A);
	else if (swap_and_rotate(first, second, third))
	{
		sa(A);
		ra(A);
	}
	else if (reverse_rotate(first, second, third))
		rra(A);
}
