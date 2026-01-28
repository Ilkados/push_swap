#include"push_swap.h"
void	sb(t_stack *b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rrb(t_stack *b)
{
	rev_rotate_stack(b);
	write(1, "rrv\n", 4);
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}

