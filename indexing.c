/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:57:38 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 17:57:41 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_array(int *arr, int size)
{
	int	i;
	int	k;
	int	temp;

	if (size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		k = i + 1;
		while (k < size)
		{
			if (arr[i] > arr[k])
			{
				temp = arr[i];
				arr[i] = arr[k];
				arr[k] = temp;
			}
			k++;
		}
		i++;
	}
}

int	find_index(int value, int *sorted_arr, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (sorted_arr[j] == value)
			return (j);
		j++;
	}
	return (-1);
}

void	assign_indexes(t_stack *A, int *sorted_arr, int size)
{
	t_node	*cur;

	cur = A->Top;
	while (cur)
	{
		cur->index = find_index(cur->value, sorted_arr, size);
		cur = cur->next;
	}
}

void	indexing_stack(t_stack *A)
{
	int		size;
	int		*arr;
	int		i;
	t_node	*cur;

	size = A->size;
	if (size < 2)
		return ;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = 0;
	cur = A->Top;
	while (cur != NULL)
	{
		arr[i] = cur->value;
		i++;
		cur = cur->next;
	}
	sort_int_array(arr, i);
	assign_indexes(A, arr, i);
	free(arr);
}
