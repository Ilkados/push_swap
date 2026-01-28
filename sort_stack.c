#include"push_swap.h"

void	sort_stack(t_stack *A, t_stack *B, int argc, char **argv)
{
	int size;
    char **tokens= tokenize_argv(argc,argv);
    int i=0;
    if(!tokens)
    {
        return (Error(),1);
    }

    if (argc > 1 && tokens[0] == NULL)
    {
        free_tokens(tokens);
        return (Error(), 1);
    }
    int *arr=  validate_and_convert( tokens, &size);

    if(arr==NULL)
    {
        Error();
        free_tokens(tokens);
        free(arr);
        return 1;
    }
 A->Top = NULL; A->Bottom = NULL; A->size = 0;
 B->Top = NULL; B->Bottom = NULL; B->size = 0;

init_stack_a(&A, arr, size);
indexing_stack(&A);
set_positions(&A);
	(void)B; /* unused for now */

	if (!A || A->size < 2)
		return ;
	if (is_sorted(A))
		return ;

	if (A->size == 2)
	{
		if (A->Top->value > A->Top->next->value)
			sa(A);
	}
	else if (A->size == 3)
		tiny_sort_3(A);
	else
	{
		/* later: indexing + Turk */
		/* turk_sort(a, b); */
	}
}
