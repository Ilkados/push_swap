
#include"push_swap.h"
int main(int argc, char **argv)
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

    i = 0;
    while (tokens[i])
    {
        printf("tokens[%d] : %s\n", i, tokens[i]);
        i++;
    }

    free_tokens(tokens);
    return 0;
}