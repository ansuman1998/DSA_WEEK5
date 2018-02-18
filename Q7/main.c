#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *lower=(int *)malloc(n*sizeof(int));
    int *higher=(int *)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++)
        scanf("%d %d", &lower[i], &higher[i]);

    int timeconsumed=0;
    for(i=0;i<n;i++)
    {   if(i!=0&&lower[i-1]+timeconsumed<=lower[i])
            timeconsumed=0;
        else if(i!=0 && lower[i-1]+timeconsumed>lower[i])
            timeconsumed=lower[i-1]+ timeconsumed - lower[i];
        if(lower[i]+timeconsumed<=higher[i])

        {
            //printf("timeconsumed %d\n",timeconsumed);
            printf("%d ",lower[i]+timeconsumed);
            timeconsumed++;

        }
        else
            printf("0 ");
    }

}
