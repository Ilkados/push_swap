/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:10:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/01/30 21:10:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	skip_spaces(char *s, int i)
{
	while (s[i] && white_space(s[i]))
		i++;
	return (i);
}

int	word_end(char *s, int i)
{
	while (s[i] && !white_space(s[i]))
		i++;
	return (i);
}

int	count_words(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] && white_space(s[i]))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !white_space(s[i]))
				i++;
		}
	}
	return (count);
}

char	*substr_range(const char *s, int start, int end)
{
	char	*out;
	int		i;

	out = malloc(end - start + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (start < end)
		out[i++] = s[start++];
	out[i] = '\0';
	return (out);
}
