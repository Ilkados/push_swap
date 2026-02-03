#include "push_swap.h"

void	sort_stack(t_stack *A, t_stack *B)
{
	if (!A || A->size < 2)
		return ;
	if (is_sorted(A))
		return ;
	if (A->size == 2)
	{
		if (A->Top->value > A->Top->next->value)
			sa(A);
	}
	else if (A->size == 3)
		tiny_sort_3(A);
	else
	{
		turk_sort(A, B);
	}
}
