
#include"push_swap.h"

void print_node_index(t_stack *s)
{
    t_node *cur = s->Top;

    while(cur !=NULL)
    {
        printf("index  of value %d is  : %d\n", cur->value, cur->pos);
        cur=cur->next;
    }
}
int main(int argc, char **argv)
{

    // parting of handle parsing : 
    

    

 free_tokens(tokens);
    

    // building Stack A;

t_stack A;
t_stack B;

A.Top = NULL; A.Bottom = NULL; A.size = 0;
B.Top = NULL; B.Bottom = NULL; B.size = 0;

init_stack_a(&A, arr, size);
indexing_stack(&A);
set_positions(&A);
free_stack(&A);
free_stack(&B);
free(arr);
   // free_tokens(tokens);

    //building stack B
    return 0;
}   