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

int swap(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value > sec->value
		&& sec->value < thir->value
		&& fir->value < thir->value)
		return 1;
   return 0;
}

int swap_and_rotate_rev(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value > sec->value && sec->value > thir->value)
	   return 1;
   return 0;
}

int rotate(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value > sec->value
		&& sec->value < thir->value
		&& fir->value > thir->value)
		return 1;
  return 0;
}

int swap_and_rotate(t_node *fir, t_node *sec, t_node *thir)
{
	if (fir->value < sec->value
		&& sec->value > thir->value
		&& fir->value < thir->value)
 	return 1;
 return 0;
}

int reverse_rotate(t_node *fir, t_node *sec, t_node *thir)
{
    return (fir->value < sec->value 
        && sec->value > thir->value 
        && fir->value > thir->value);
		
}
