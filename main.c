/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:10:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 19:10:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_push_swap(t_stack *a, t_stack *b, int *arr, int size)
{
	a->Top = NULL;
	a->Bottom = NULL;
	a->size = 0;
	b->Top = NULL;
	b->Bottom = NULL;
	b->size = 0;
	init_stack_a(a, arr, size);
	free(arr);
	if (is_sorted(a))
	{
		free_stack(a);
		return ;
	}
	sort_stack(a, b);
	free_stack(a);
}

int	main(int argc, char **argv)
{
	int		size;
	char	**tokens;
	int		*arr;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	tokens = tokenize_argv(argc, argv);
	if (!tokens || tokens[0] == NULL)
	{
		free_tokens(tokens);
		error();
		return (1);
	}
	arr = validate_and_convert(tokens, &size);
	free_tokens(tokens);
	if (!arr)
	{
		error();
		return (1);
	}
	run_push_swap(&a, &b, arr, size);
	return (0);
}
