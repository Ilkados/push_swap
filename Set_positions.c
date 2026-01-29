#include "push_swap.h"
void set_positions(t_stack *A)
{
    int i=0;

    t_node *Cur= A->Top;

    while(Cur)
    {
        Cur->pos=i;
        i++;
        Cur=Cur->next;
    }
}