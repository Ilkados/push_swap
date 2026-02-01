/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:30:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/01/31 10:30:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	total_tokens(char **argv, int argc)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count += count_words(argv[i]);
		i++;
	}
	return (count);
}

void	copy_tokens(char **dst, char **src, int *k)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[*k] = src[j];
		(*k)++;
		j++;
	}
}

char	**tokenize_argv(int argc, char **argv)
{
	char	**array;
	char	**temp;
	int		i;
	int		k;

	array = malloc((total_tokens(argv, argc) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		temp = split(argv[i]);
		if (!temp)
		{
			free_tokens(array);
			return (NULL);
		}
		copy_tokens(array, temp, &k);
		free(temp);
		i++;
	}
	array[k] = NULL;
	return (array);
}
