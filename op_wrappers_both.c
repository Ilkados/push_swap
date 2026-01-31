#include"push_swap.h"

 
 void rr(t_stack *A, t_stack *B)
 {
	if(!A || !B || A->size < 2 || B->size < 2)
	{
		return ;
	}
		rotate_stack(A);
		rotate_stack(B);
		write(1,"rr\n",3);
 }



 void rrr(t_stack *A, t_stack *B)
 {
	if(!A || !B || A->size < 2 || B->size < 2)
	{
		return ;
	}
		rev_rotate_stack(A);
		rev_rotate_stack(B);
		write(1,"rrr\n",4);

 }


