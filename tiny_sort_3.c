#include"push_swap.h"
void	tiny_sort_3(t_stack *A)
{
	t_node	*F;
	t_node	*S;
	t_node	*T;

	F = A->Top;
	S = F->next;
	T = A->Bottom;

	/* already sorted */
	if (F->value < S->value && S->value < T->value)
		return ;

	/* 2 1 3 */
	else if (F->value > S->value && S->value < T->value && F->value < T->value)
		sa(A);

	/* 3 2 1 */
	else if (F->value > S->value && S->value > T->value)
	{
		sa(A);
		rra(A);
	}

	/* 3 1 2 */
	else if (F->value > S->value && S->value < T->value && F->value > T->value)
		ra(A);

	/* 1 3 2 */
	else if (F->value < S->value && S->value > T->value && F->value < T->value)
	{
		sa(A);
		ra(A);
	}

	/* 2 3 1 */
	else if (F->value < S->value && S->value > T->value && F->value > T->value)
		rra(A);
}
