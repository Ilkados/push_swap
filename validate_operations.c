/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:32:20 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 18:32:22 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	condition_for_sa(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value > sec->value
		&& sec->value < thir->value
		&& fir->value < thir->value)
		return (1);
	return (0);
}

int	condition_for_sa_and_rra(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value > sec->value
		&& sec->value > thir->value)
		return (1);
	return (0);
}

int	condition_for_ra(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value > sec->value
		&& sec->value < thir->value
		&& fir->value > thir->value)
		return (1);
	return (0);
}

int	condition_for_sa_and_ra(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value < sec->value
		&& sec->value > thir->value
		&& fir->value < thir->value)
		return (1);
	return (0);
}

int	condition_for_rra(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value < sec->value
		&& sec->value > thir->value
		&& fir->value > thir->value)
		return (1);
	return (0);
}
