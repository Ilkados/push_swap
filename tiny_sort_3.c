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
	else if (condition_for_sa(first, second, third))
		sa(A);
	else if (condition_for_sa_and_rra(first, second, third))
	{
		sa(A);
		rra(A);
	}
	else if (condition_for_ra(first, second, third))
		ra(A);
	else if (condition_for_sa_and_ra(first, second, third))
	{
		sa(A);
		ra(A);
	}
	else if (condition_for_rra(first, second, third))
		rra(A);
}
