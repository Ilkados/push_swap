
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include<stdio.h>


/* =========================
 Error.
   ========================= */
   void Error();


/* =========================
 parsing 
   ========================= */
 void free_tokens(char **tokens);


/* =========================
 parsing 
   ========================= */
char **tokenize_argv(int argc,char **argv );


/* =========================
  Read input:
   ========================= */
int * validate_and_convert( char **tokens,int *size);





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
  Build the stack
   ========================= */
int init_stack_a(t_stack *stack, int *arr, int size);

/* =========================
   Parsing / validation     
   ========================= 

int     valid_str(const char *token);
int     ft_atoi_safe(const char *token, int *out);
p
int     count_tokens(char **tokens);
int     duplicate_exist(int *arr, int size);

int     *valid_tokens(char **tokens, int *size_out);
int     *validate_and_convert(char **tokens, int *size_out);
=========================
   Stack building
   ========================= 

void    init_stack(t_stack *s);
t_node  *new_node(int value);
void    append_bottom(t_stack *stack, t_node *node);
void    free_stack(t_stack *stack);
int     init_stack_a(t_stack *stack, int *arr, int size);

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
#endif
