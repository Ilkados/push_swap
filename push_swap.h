/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
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

/* Error */
void	error(void);

/* Free */
void	free_tokens(char **tokens);
void	free_stack(t_stack *s);

/* Split utils */
int		white_space(char c);
int		skip_spaces(char *s, int i);
int		word_end(char *s, int i);
int		count_words(const char *s);
char	*substr_range(const char *s, int start, int end);
char	**split(char *s);

/* Parsing */
int		duplicate_esist(int *arr, int size);
int		*valid_tokens(char **tokens, int *size);
char	**tokenize_argv(int argc, char **argv);

/* Read input */
int		*validate_and_convert(char **tokens, int *size);

/* Build the stack */
int		init_stack_a(t_stack *stack, int *arr, int size);

/* Core operations (no printing) */
int		swap_nodes(t_stack *s);
int		push_node_to_stack(t_stack *from, t_stack *to);
int		rotate_stack(t_stack *s);
int		rev_rotate_stack(t_stack *s);

/* Operation wrappers for A */
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	pa(t_stack *b, t_stack *a);

/* Validate operations*/
int		condition_for_sa(t_node *fir, t_node *sec, t_node *thir);
int		condition_for_sa_and_rra(t_node *fir, t_node *sec, t_node *thir);
int		condition_for_ra(t_node *fir, t_node *sec, t_node *thir);
int		condition_for_sa_and_ra(t_node *fir, t_node *sec, t_node *thir);
int		condition_for_rra(t_node *fir, t_node *sec, t_node *thir);

/* Operation wrappers for B */
void	sb(t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* Operation wrappers (both) */
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Rotation helpers */

/* Rotation helpers */
void	rotate_both(t_stack *a, t_stack *b, int *ca, int *cb);
void	rotate_a(t_stack *a, int ca);
void	rotate_b(t_stack *b, int cb);

/* Indexing */
void	indexing_stack(t_stack *a);

/* Positions */
void	set_positions(t_stack *a);

/* Check sorted */
int		is_sorted(t_stack *a);

/* Move utils */
void	bring_node_to_top_a(t_stack *a, int ca);
void	bring_node_to_top_b(t_stack *b, int cb);
void	move_best_to_top(t_stack *a, t_stack *b, t_node *best);
void	final_rotate_min_to_top(t_stack *a);

/* Turk logic */
void	set_costs(t_stack *a, t_stack *b);
void	set_targets(t_stack *a, t_stack *b);
int		ft_abs(int x);

/* Sorting */
void	tiny_sort_3(t_stack *a);
void	turk_sort(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);

#endif
