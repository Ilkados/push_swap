#include"push_swap.h"

 void rr(t_stack *A, t_stack *B,int cr)
 {
	while (cr > 0)
	{
		ra(A);
		rb(B);
		cr--;
	}
 }



 void rrr(t_stack *A, t_stack *B,int crrr)
 {
	while (crr > 0)
	{
		ra(A);
		rb(B);
		crrr--;
	}
 }
 void rotate_both(t_stack *A, t_stack *B, int *ca, int *cb)
{
    while(*ca >0 && *cb >0)
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

 void	rotate_a(t_stack *A, int ca)
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

 void	rotate_b(t_stack *B, int cb)
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

