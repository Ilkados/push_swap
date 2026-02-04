/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:58:35 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 17:58:37 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *A)
{
	t_node	*cur;

	if (!A || A->size < 2)
		return (1);
	cur = A->top;
	while (cur != NULL && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
