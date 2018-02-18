#include <string.h>
#include <stdio.h>
#include <stdlib.h>

long long int prod(char *temp, char* sub)
{
    long long int n= strlen(sub);
    long long int count=0;
    while(temp=(strstr(temp,sub)))
    {
        count++;
        temp++;
    }
//printf("Number of occurences is %d\n", count);
    return count*n;
}
int main(void)
{
    char *s=;
    long long int count=0;
    long long int max=-1;
    char pr[100]="";
    //scanf("%[^\n]s",s);
    long long int n= strlen(s);
    //printf("%d\n",n);
    long long int i,j;

    for(i=0;i<n;i++)
    {   char pr[100]="";
        for(j=i;j<n;j++)
        {
            strncat(pr,&s[j],1);
            //printf("%s\n",pr);
            //printf("%d\n",prod(s,pr));
            if(prod(s,pr)>max)
            {
                max=prod(s,pr);
            }

        }

    }

    printf("%lld\n", max);

    return 0;
}
