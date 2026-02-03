
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
   void error();


/* =========================
 free
   ========================= */
 void free_tokens(char **tokens);
 void	free_stack(t_stack *s);

/* =========================
 split_utils.
   ========================= */
int	white_space(char c);
int	skip_spaces(char *s, int i);
int	word_end(char *s, int i);
int	count_words(const char *s);
char	*substr_range(const char *s, int start, int end);
char	**split(char *s);

/* =========================
 parsing 
   ========================= */
int	duplicate_esist(int *arr, int size);
int	*valid_tokens(char **tokens, int *Size);
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
int     swap_nodes(t_stack *s);                  
int     push_node_to_stack(t_stack *from, t_stack *to);  
int     rotate_stack(t_stack *s);                
int     rev_rotate_stack(t_stack *s);

/* =========================
   Validate operations
   ========================= 
*/
int condition_for_sa(t_node *fir, t_node *sec, t_node *thir);
int condition_for_sa_and_rra(t_node *fir, t_node *sec, t_node *thir);
int condition_for_ra(t_node *fir, t_node *sec, t_node *thir);
int condition_for_sa_and_ra(t_node *fir, t_node *sec, t_node *thir);
int condition_for_rra(t_node *fir, t_node *sec, t_node *thir);



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
   Operation Wrapper both
   ========================= 
*/
 void rr(t_stack *A, t_stack *B);
 void rrr(t_stack *A, t_stack *B);


 void rotate_both(t_stack *A, t_stack *B, int *ca, int *cb);
 void	rotate_a(t_stack *A, int ca);
 void	rotate_b(t_stack *B, int cb);

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
  utils 
   ========================= 
*/
void	rotate_both(t_stack *A, t_stack *B, int *ca, int *cb);
void	bring_node_to_top_a(t_stack *A, int ca);
void	bring_node_to_top_b(t_stack *B, int cb);
void    move_best_to_top(t_stack *A, t_stack *B, t_node *best);
void    final_rotate_min_to_top(t_stack *A);

/* =========================
  Turk logic.
   ========================= 
*/
void	set_costs(t_stack *a, t_stack *b);
void	set_targets(t_stack *a, t_stack *b);
int	ft_abs(int x);




/* =========================
  Turk logic.
   ========================= 
*/
void    tiny_sort_3(t_stack *A);
void    turk_sort(t_stack *A, t_stack *B);
void	sort_stack(t_stack *A, t_stack *B);


#endif
