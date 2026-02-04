/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:00:00 by moboulir          #+#    #+#             */
/*   Updated: 2026/02/01 10:00:00 by moboulir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*
** =========================
** Data structures
** =========================
*/

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/*
** =========================
** Error / Free
** =========================
*/

void	error(void);
void	free_tokens(char **tokens);
void	free_stack(t_stack *s);

/*
** =========================
** Split / Parsing
** =========================
*/

int		white_space(char c);
int		count_words(const char *s);
char	*substr_range(const char *s, int start, int end);
char	**split(char *s);

char	**tokenize_argv(int argc, char **argv);
int		*valid_tokens(char **tokens, int *size);
int		validate_and_convert(char **tokens, int *size);

/*
** =========================
** Stack init / utils
** =========================
*/

int		init_stack_a(t_stack *stack, int *arr, int size);
int		is_sorted(t_stack *a);
void	indexing_stack(t_stack *a);
void	set_positions(t_stack *a);

/*
** =========================
** Core operations
** =========================
*/

int		swap_nodes(t_stack *s);
int		push_node_to_stack(t_stack *from, t_stack *to);
int		rotate_stack(t_stack *s);
int		rev_rotate_stack(t_stack *s);

/*
** =========================
** Wrappers (print ops)
** =========================
*/

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*
** =========================
** Sorting logic
** =========================
*/

void	tiny_sort_3(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);

/*
** =========================
** Turk utils
** =========================
*/

void	set_targets(t_stack *a, t_stack *b);
void	set_costs(t_stack *a, t_stack *b);
int		ft_abs(int x);

void	rotate_both(t_stack *a, t_stack *b, int *ca, int *cb);
void	bring_node_to_top_a(t_stack *a, int ca);
void	bring_node_to_top_b(t_stack *b, int cb);
void	move_best_to_top(t_stack *a, t_stack *b, t_node *best);
void	final_rotate_min_to_top(t_stack *a);

#endif
