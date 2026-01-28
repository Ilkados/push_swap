#include"push_swap.h"

int is_sorted(t_stack *A)
{
    t_node *cur = A->Top;

    if(!A || A->size<2)
     return 1;
    while(cur!=NULL && cur->next)
    {
        if(cur->value > cur->next->value)
        {
            return 0;
        }
        cur=cur->next;
    }
    return 1;
}

void sort_stack(t_stack *A, t_stack *B)
{
    if(is_sorted(&A))
    {
       return;
    }
    else
    {}

}