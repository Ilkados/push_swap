
includeB`:wq!

int valid_sign( char *token)
{
    int i=0;
    int sign_count = 0;

    if((token[i]== '+' || token[i]=='-') && token[i+1]== '\0')
    {
        return 0;
    }
    while(token[i])
    {
        if(token[i]=='-' || token[i]=='+')
        {
            sign_count++;
        }
        i++;
    }

    if(sign_count >1)
    {
        return 0;
    }
    return 1;

}
