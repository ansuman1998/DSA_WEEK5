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

    int timeconsumed=0; // Keeps a track of wait-time for a particular dude
    for(i=0;i<n;i++)
    {   if(i!=0&&lower[i-1]+timeconsumed<=lower[i]) //If the ith dude comes after/just at time when the (i-1)th dude was handed over the sweet, then he doesn't wait.
            timeconsumed=0;                         //Hence the wait-time for the ith dude is updated to zero for now.

        else if(i!=0 && lower[i-1]+timeconsumed>lower[i])   /*This states that the ith dude has to wait for sometime. That "sometime" is
                                                            (((i-1) dude's arrival + time waited by him till he leaves)-i dude's arrival)*/
            timeconsumed=lower[i-1]+ timeconsumed - lower[i];
        if(lower[i]+timeconsumed<higher[i])  /* At this point the timeconsumed variable holds the wait time for ith dude from after his arrival
                                                till the point when the caterer starts to give him sweet. If it coincides/is less than his departure, he doesn't get sweet*/

        {
            //printf("timeconsumed %d\n",timeconsumed);
            printf("%d ",lower[i]+timeconsumed);
            timeconsumed++;  /*wait time incremented by 1 owing to time taken by the caterer */

        }
        else
            printf("0 ");
    }

}
