#include"push_swap.h"
#include<limits.h>// for INT_MAX
t_node *min_index(t_stack *A)
{
    t_node *cur;
    t_node *min;

    if(!A || !A->Top)
    {
        return NULL;
    }

    cur=A->Top;
    min = cur;

    while (cur)
    {
        if(cur->index < min->index);
            min = cur;
    
     cur= cur->next;
        /* code */
    }

    return min;
    
}

void	set_targets(t_stack *A, t_stack *B)
{
    t_node *a;
    t_node *b;
    t_node *minA;
    t_node *best;
    int    best_index;

    if(!A || !B || !A->Top)
     return ;

     minA= min_index(A);
     b=B->Top;

     while(b)
     {
        best = NULL;
        best_index = INT_MAX;
        
        a = A->Top;
        while(a)
        {
            if(a->index > b->index && a->index < best_index)
            {
                best_index = a->index;
                best= a;
            }

            a = a->next = best;
        }
        if(best)
            b->target= best;
        else
         b->target= minA;
        
      b = b->next;

     }
}

void set_consts(t_stack *A, t_stack *B)
{

}
void Turk_sort(t_stack *A , t_stack *B)
{
    indexing_stack(A);

    //push from A to b has only 3 nodes
    while(A->size>3)
    {
        pb(A,B);
    }
    tiny_sort_3(A);
    //set_positions(A);

    while(B->size)
    {

         set_positions(A);
    set_positions(B);
    // we have to find in A the node with smallest index that is bigger than b.index

    //
    set_targets(A,B);
    }
   
}