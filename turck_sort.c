#include"push_swap.h"
void Turk_sort(t_stack *A , t_stack B)
{
    int size= A->size;
    int *arr=malloc(sizeof(int)*size);
    if(!arr)
    {
        free(arr);
        return ;
        
    }
    int i=0;
    t_node *cur = A->Top;
    while(cur!=NULL)
    {
        arr[i]=cur->value;
        i++;
        cur=cur->next;
    }

    sort_int_array(arr,i);
    assgn_indexes(A,arr,i);
}