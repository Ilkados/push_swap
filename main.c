
#include"push_swap.h"

int main(int argc, char **argv)
{

    // parting of handle parsing : 
    

    int size;
    char **tokens= tokenize_argv(argc,argv);
   
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

 
 free_tokens(tokens);
    

    // building Stack A;


   t_stack A;
   t_stack B;

A.Top = NULL; A.Bottom = NULL; A.size = 0;
B.Top = NULL; B.Bottom = NULL; B.size = 0;

    init_stack_a(&A, arr, size);
     free(arr);
	sort_stack(&A, &B);


 free_stack(&A);
 free_stack(&B);
    return 0;
}   