/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:10:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/01/30 21:10:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

char	**split_fail(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}
char	**split(char *s)
{
	char	**array;
	int		i;
	int		k;
	int		start;

	array = malloc((count_words(s) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	k = 0;
	while (s && s[i])
	{
		i = skip_spaces(s, i);
		if (!s[i])
			break ;
		start = i;
		i = word_end(s, i);
		array[k] = substr_range(s, start, i);
		if (!array[k++])
			return (split_fail(array));
	}
	array[k] = NULL;
	return (array);
}
