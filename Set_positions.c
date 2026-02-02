/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:32:14 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 22:38:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack *A)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = A->Top;
	while (cur)
	{
		cur->pos = i;
		i++;
		cur = cur->next;
	}
}