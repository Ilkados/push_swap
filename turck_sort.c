#include"push_swap.h"

void sort_int_array(int *arr, int size)
{

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
void Turk_sort(t_stack *A , t_stack B)
{
    int size= A->size;
    int *arr=(int)malloc(sizeof(int)*size);

    int i=0;
    t_node *cur = A->Top;
    while(cur!=NULL)
    {
        arr[i]=cur->value;
        i++;
        cur=cur->next;
    }
}