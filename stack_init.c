#include"push_swap.h"
#include<stdio.h>
#include<string.h>


typedef struct s_node
{
    int             value;
    struct  s_node  *next;
    struct  s_node  *prev;
}   t_node;


typedef  struct s_stack
{

    t_node  *Top;
    t_node  *Bottom;
    int size;
}   t_stack;


// here we have to create new_node(int value)

t_node *new_node(int Value)
{
    t_node *node=malloc(sizeof(t_node));
    
    if(!node)
    {
        return NULL;
    }
    node->value=Value;
    node->next=NULL;
    node->prev=NULL;

    return node;
}


// here we have to connect that node into stack:

void  append_bottom(t_stack *stack, t_node *node)
{
    if(!stack->Top)
    {
        stack->Bottom=node;
        stack->Top=node;
        stack->size=1;
        node->next=NULL;
        node->prev=NULL;

    }
    else
    {
        t_node *old_botttom;
         old_botttom = stack->Bottom;
        node->prev=old_botttom;
         old_botttom->next=node;
         node->next=NULL;
         stack->Bottom=node;
         stack->size++;
    }

}

void init_stack_a(char *arr, int size)
{
    int i=0;
    t_stack *stack;
    while(i<size)
    {
        t_node *node = new_node(arr[i]);

        append_bottom(stack,node);
        i++;
    }
}
void list_node()
{

}