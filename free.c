 #include"push_swap.h"
 void free_tokens(char **tokens)
{
    int i = 0;

    if (!tokens)
        return;
    while (tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}