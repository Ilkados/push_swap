/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tokens_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:35:46 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 16:35:49 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

int	valid_str(const char *token)
{
	int	i;

	i = 0;
	if (!token || token[0] == '\0')
		return (0);
	if (token[i] == '+' || token[i] == '-')
		i++;
	if (token[i] == '\0')
		return (0);
	while (token[i])
	{
		if (token[i] < '0' || token[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_safe(const char *token, int *out)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!token || !out)
		return (0);
	if (token[i] == '+' || token[i] == '-')
	{
		if (token[i] == '-')
			sign = -1;
		i++;
	}
	while (token[i])
	{
		result = result * 10 + (token[i] - '0');
		i++;
	}
	result *= sign;
	if (result > 2147483647L || result < -2147483648L)
		return (0);
	*out = (int)result;
	return (1);
}

int	count_tokens(char **token)
{
	int	i;

	i = 0;
	while (token[i])
		i++;
	return (i);
}

int	duplicate_esist(int *arr, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size - 1)
	{
		k = i + 1;
		while (k < size)
		{
			if (arr[k] == arr[i])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	*valid_tokens(char **tokens, int *Size)
{
	int	size;
	int	*arr;
	int	i;
	int	value;

	size = count_tokens(tokens);
	if (Size != NULL)
		*Size = size;
	arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	if (!arr)
		return (NULL);
	while (i < size)
	{
		if (!valid_str(tokens[i]) || !ft_atoi_safe(tokens[i], &value))
		{
			free(arr);
			return (NULL);
		}
		arr[i] = value;
		i++;
	}
	return (arr);
}
