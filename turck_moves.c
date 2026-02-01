#include "push_swap.h"
void	rotate_both(t_stack *A, t_stack *B, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(A, B);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(A, B);
		(*ca)++;
		(*cb)++;
	}
}
void	bring_node_to_top_a(t_stack *A, int ca)
{
	while (ca > 0)
	{
		ra(A);
		ca--;
	}
	while (ca < 0)
	{
		rra(A);
		ca++;
	}
}

void	bring_node_to_top_b(t_stack *B, int cb)
{
	while (cb > 0)
	{
		rb(B);
		cb--;
	}
	while (cb < 0)
	{
		rrb(B);
		cb++;
	}
}

static t_node *find_index0(t_stack *A)
{
	t_node *cur = A->Top;
	while (cur)
	{
		if (cur->index == 0)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void final_rotate_min_to_top(t_stack *A)
{
	t_node *min;

    int p = 0;
	if (!A || A->size < 2)
		return;
	set_positions(A);
	min = find_index0(A);
	if (!min)
		return;
    p = min->pos;
	if (p <= A->size / 2)
	{
		while (p-- > 0)
			ra(A);
	}
	else
	{
        p = (A->size - min->pos);
		while (p-- > 0)
			rra(A);
	}
}

void	move_best_to_top(t_stack *A, t_stack *B, t_node *best)
{
	int	ca;
	int	cb;

	if (!A || !B || !best)
		return ;

	ca = best->cost_a;
	cb = best->cost_b;

	rotate_both(A, B, &ca, &cb);
	bring_node_to_top_a(A, ca);
	bring_node_to_top_b(B, cb);
}