#include<stdio.h>
#include<unistd.h>
int valid_str(const char *token)
{
    int i = 0;

    if (!token || token[0] == '\0')
        return 0;

    if (token[i] == '+' || token[i] == '-')
        i++;

    if (token[i] == '\0')
        return 0;

    while (token[i])
    {
        if (token[i] < '0' || token[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int ft_atoi_safe(const char *token, int *out)
{
    int  i = 0;
    int  sign = 1;
    long result = 0;

    if (!token || !out)
        return 0;

    if (token[i] == '+' || token[i] == '-')
    {
        if (token[i] == '-')
            sign = -1;
        i++;
    }

    while (token[i])
    {
        result = result * 10 + (token[i] - '0');
        i++;
    }

    result *= sign;
    if (result > 2147483647L || result < -2147483648L)
        return 0;

    *out = (int)result;
    return 1;
}

int count_tokens(char **token)
{
    int i=0;

    while(token[i])
    {
        i++;
    }
    return i;
}

int duplicate_esist(int *arr,int size)
{

    int i=0;

    while(i<size-1)
    {
        int k=i+1;

        while(k<size)
        {
            if(arr[k]==arr[i])
            {
                return 1;
            }
            k++;
        }
        i++;
    }
    return 0;
   
}


int *valid_tokens(char **tokens,int *Size)
{
    int size = count_tokens(tokens);
    if(Size!=NULL)
       *Size=size;
    int *arr = (int *)malloc(sizeof(int) * size);
    int i = 0;
    int value;

    if (!arr)
        return NULL;

    while (i < size)
    {
        if (!valid_str(tokens[i]) || !ft_atoi_safe(tokens[i], &value))
        {
            free(arr);
            write(2,"Error\n",6);
            return NULL;
        }
        arr[i] = value;
        i++;
    }
    return arr;
}


int * validate_and_convert( char **tokens,int *size)
{
    int *arr=valid_tokens(tokens,*size);

    if(arr==NULL || duplicate_esist(arr,*size)==1 )
    {
        write(2,"Error\n",6);
        free(arr);
        return NULL;
    }
    
    return arr;
    
}
