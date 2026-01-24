#include "push_swap.h"

int swap_stack(t_stack *s)
{
    t_node *a;
    t_node *b;
    t_node *c;

    if (!s || s->size < 2 || !s->Top || !s->Top->next)
        return 0;

    a = s->Top;
    b = a->next;
    c = b->next;         

    s->Top = b;
    b->prev = NULL;
    b->next = a;

    a->prev = b;
    a->next = c;

    if (c)
        c->prev = a;

    if (!c)
        s->Bottom = a;

    return 1;
}
int     push_stack(t_stack *from, t_stack *to)  // pa/pb base
{
    t_node *move;


    if(from ==NULL || to == NULL || from->Top == NULL || from->size==0)
        return 0;

    move = from->Top;

    from->Top= move->next;

    if(from->Top!=NULL)
    {
        from->Top->prev=NULL;
    }

    if(from->Top == NULL)
    {
        from->Bottom=NULL;
    }
    from->size--;


    move->prev=NULL;
    move->next=NULL;
    
    if(to->Top == NULL || to->size==0)
    {
        to->Top=move;
        to->Bottom=move;
        move->prev=NULL;
        move->next=NULL;
        to->size++;
        return 1;
    }

    t_node * old_top =to->Top;

    move->next =old_top;
    old_top->prev=move;

    move->prev=NULL;
    to->Top=move;
    to->size++;
    return 1;
} 


int rotate_stack(t_stack *s)
{
    if(s==NULL || s->size<2 || s->Top==NULL || s->Top->next==NULL)
        return 0;

    t_node *First = s->Top;

    t_node Second = fyd
}