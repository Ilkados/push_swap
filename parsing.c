
#include<unistd.h>
#include<stdlib.h>
#include <stdio.h>

#include"push_swap.h"

int white_space(char c)
{
    if((c>=9 && c<=13) || c==32)
      return 1;
  return 0;
}

static int  count_words(const char *s)
{
    int i = 0;
    int count = 0;

    if (!s)
        return 0;

    while (s[i])
    {
        while (s[i] && white_space(s[i]))
            i++;
        if (s[i] && !white_space(s[i]))
        {
            count++;
            while (s[i] && !white_space(s[i]))
                i++;
        }
    }
    return count;
}
char *substr_range(const char *s, int start , int end)
{
    int len= end - start;

    int i=0;
    char *out;

    if(len<=0)
        len=0;
    
    out =(char *)malloc(sizeof(char) *(len+1));

    if(!out)
      return NULL;

    while(i<len)
    {
        out[i]=s[start+i];
        i++;
    }
    out[i]='\0';
    return out;
}
char **split_whitespace(char *s)
{
    int i=0;
    int k=0;
    int start;
    int end;
    int size=count_words(s);
    char **array=(char **)malloc((size+1)*sizeof(char*));

    if(!
        array)
    {
        return NULL;
    }
    
     while(s && s[i])
     {

        while(s[i] && white_space(s[i]))
            i++;
        
         if(!s[i])
           break;

        start = i;

        while(s[i] && !white_space(s[i]))
            i++;
        end=i;

         array[k]=substr_range(s,start,end);

         if(!array[k])
         {
            free_tokens(array);
            return NULL;
         }
         k++;
     }
     array[k]=NULL;
     return array;

}

int total_tokens(char **argv, int argc)
{
    int  i=1;
    int count =0;

    while(i<argc)
    {
        count += count_words(argv[i]);
        i++;
    }

    return count;
}
char **tokenize_argv(int argc ,char **argv)
{
    int total = total_tokens(argv, argc);
     char **array=(char **)malloc((total+1)*sizeof(char*));
    char ** temp;
     
     int k=0;
     if(!array)
     {
        return NULL;
     }

     int i=1;
     while(i< argc)
     {
       
         temp=split_whitespace(argv[i]);
         
         if(!temp)
         {
             array[k]=NULL;
             free_tokens(array);
             return NULL;
         }

          int j=0;
         while(temp[j]!=NULL)
         {
            array[k]= temp[j];
            k++;
            j++;
         }
         free(temp); /*free ONLY the container, strings were moved */
         i++;
     }
     array[k]=NULL;
     return array;
     
}
