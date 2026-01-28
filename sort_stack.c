#include"push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	(void)b; /* unused for now */

	if (!a || a->size < 2)
		return ;
	if (is_sorted(a))
		return ;

	if (a->size == 2)
	{
		if (a->Top->value > a->Top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		tiny_sort_3(a);
	else
	{
		/* later: indexing + Turk */
		/* turk_sort(a, b); */
	}
}
