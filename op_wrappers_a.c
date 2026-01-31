#include"push_swap.h"

void	sa(t_stack *a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	rev_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	pa(t_stack *b, t_stack *a)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}
