#include "push_swap.h"

void sort_int_array(int *arr, int size)
{
    if(size<2)
     return ;
    int i=0;
    while(i<size-1)
    {
        int k=i+1;
        while(k<size)
        {
            if(arr[i]>arr[k])
            {
                int temp;

                temp=arr[i];
                arr[i]=arr[k];
                arr[k]=temp;
            }
            k++;
        }
        i++;
    }

}
int find_index(int value,int *sorted_arr,int size)
{
    int j=0;

    while(j<size)
    {
        if(sorted_arr[j]==value)
         return j;
     j++;
    }
    return -1;
}
void assign_indexes(t_stack *A, int *sorted_arr,int size)
{
    t_node *cur=A->Top;

    while(cur)
    {
        cur->index=find_index(cur->value,sorted_arr,size);
        cur=cur->next;
    } 
}

void indexing_stack(t_stack *A)
{
    int size= A->size;
    if(size<2)
     return ;
    int *arr=malloc(sizeof(int)*size);
    if(!arr)
    {
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
    assign_indexes(A,arr,i);
    free(arr);
}