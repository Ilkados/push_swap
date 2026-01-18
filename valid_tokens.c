
#include<stdio.h>
#include<unistd.h>
int valid_str(char *token)
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

int ft_atoi_safe(char *token, int *out)
{
    int i=0;
    int sign=1;
    long result=0;
    char value=1;

    if(token[i]=='+' || token[i]=='-')
    {
        if(token[i]=='-')
        {
            sign=-1;
        }
        i++;
    }

    while(token[i])
    {
        result=result*10 +(token[i]-'0');
        i++;
    }

    result*=sign;
    if(result > 2147483647 || result <-2147483648 )
    {
         return 0 ;
    }
    *out=result;
    return 1;
}

