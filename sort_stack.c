/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:00:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 10:00:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_stack(t_stack *A, t_stack *B)
{
	if (!A || A->size < 2)
		return ;
	if (is_sorted(A))
		return ;
	if (A->size == 2)
	{
		if (A->top->value > A->top->next->value)
			sa(A);
	}
	else if (A->size == 3)
		tiny_sort_3(A);
	else
	{
		turk_sort(A, B);
	}
}
