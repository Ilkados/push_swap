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
        if(cur->index < min->index)
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

            a->next = best;
        }
        if(best)
            b->target= best;
        else
         b->target= minA;
        
      b = b->next;

     }
}
static int calc_cost(int pos, int size)
{
    if(size<=1)
     return 0;

     if(pos <=size/2)
      return pos;

 return  (-(size-pos));
}
void set_consts(t_stack *A, t_stack *B)
{

    t_node *b;

    if(!A || !B)
        return ;

    b=B->Top;

    while(b)
    {
        b->cost_b =calc_cost(b->pos,B->size);

        if(b->target)
          b->cost_a=calc_cost(b->target->pos,A->size);
        else
         b->cost_a=0;
    
         b=b->next;
    }

}

#include "push_swap.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_node	*find_cheapest(t_stack *B)
{
	t_node	*cur;
	t_node	*best;
	int		best_score;
	int		score;

	if (!B || !B->Top)
		return (NULL);

	cur = B->Top;
	best = cur;
	best_score = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);

	cur = cur->next;
	while (cur)
	{
		score = ft_abs(cur->cost_a) + ft_abs(cur->cost_b);
		if (score < best_score)
		{
			best = cur;
			best_score = score;
		}
		cur = cur->next;
	}
	return (best);
}


static void rotate_both(t_stack *A, t_stack *B, int *ca, int *cb)
{
    while(*ca >0 && *cb >0)
    {
        rr(A, B);
		(*ca)--;
		(*cb)--;

    }
    while (*ca < 0 && *cb < 0)
	{
		rrr(A, B);
		(*ca)++;
		(*cb)++;
	}
}

static void	rotate_a(t_stack *A, int ca)
{
	while (ca > 0)
	{
		ra(A);
		ca--;
	}
	while (ca < 0)
	{
		rra(A);
		ca++;
	}
}

static void	rotate_b(t_stack *B, int cb)
{
	while (cb > 0)
	{
		rb(B);
		cb--;
	}
	while (cb < 0)
	{
		rrb(B);
		cb++;
	}
}
void	move_best_to_top(t_stack *A, t_stack *B, t_node *best)
{
	int	ca;
	int	cb;

	if (!A || !B || !best)
		return ;

	ca = best->cost_a;
	cb = best->cost_b;

	rotate_both(A, B, &ca, &cb);
	rotate_a(A, ca);
	rotate_b(B, cb);
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
    set_targets(A,B);
    set_consts(A,B);

    t_node  *Best = find_cheapest(B);
    }
   
}