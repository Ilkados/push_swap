
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include<stdio.h>


/* =========================
   Data structures
   ========================= */

typedef struct s_node
{
    int             value;

    int             index;
    int             pos;
    int             cost_a;
    int             cost_b;
    struct s_node   *target;

    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node  *Top;
    t_node  *Bottom;
    int     size;
}   t_stack;


/* =========================
 Error.
   ========================= */
   void Error();


/* =========================
 free
   ========================= */
 void free_tokens(char **tokens);
 void	free_stack(t_stack *s);

/* =========================
 parsing 
   ========================= */
char **tokenize_argv(int argc,char **argv );


/* =========================
  Read input:
   ========================= */
int * validate_and_convert( char **tokens,int *size);








/* =========================
  Build the stack
   ========================= */
int init_stack_a(t_stack *stack, int *arr, int size);


/* =========================
   Core operations (no printing)
   ========================= 
*/
int     swap_stack(t_stack *s);                  
int     push_stack(t_stack *from, t_stack *to);  
int     rotate_stack(t_stack *s);                
int     rev_rotate_stack(t_stack *s);   

/* =========================
   Operation Wrapper for A
   ========================= 
*/
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	pa(t_stack *b, t_stack *a);


/* =========================
   Operation Wrapper for B
   ========================= 
*/
void	sb(t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	pb(t_stack *a, t_stack *b);


/* =========================
  indexing stack
   ========================= 
*/
void indexing_stack(t_stack *A);


/* =========================
   set_positions.
   ========================= 
*/
void set_positions(t_stack *A);


/* =========================
  check is stack is sorted.
   ========================= 
*/
int is_sorted(t_stack *A);



/* =========================
  Turklogic.
   ========================= 
*/
void    tiny_sort_3(t_stack *A);
void    Turk_sort(t_stack *A, t_stack *B);
void	sort_stack(t_stack *A, t_stack *B);


#endif
