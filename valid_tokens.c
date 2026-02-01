/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:31:34 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 16:31:37 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*validate_and_convert(char **tokens, int *size)
{
	int	*arr;

	arr = valid_tokens(tokens, size);
	if (arr == NULL || duplicate_esist(arr, *size) == 1)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
