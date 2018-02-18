#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,max=-1,secondmax=-1;
    scanf("%d", &n);
    int *a=(int *)malloc(n*sizeof(int));
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
    {
        int max=a[i];
        int maxi=i;
        for(j=i+1;j<n;j++)
            if(a[j]>max)
        {
            max=a[j];
            maxi=j;
        }
        int temp=a[i];
        a[i]=a[maxi];
        a[maxi]=temp;
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    int count=0;
    for(i=0;i<n;)
    {
        count=0;
        j=i;
        while(j<n&&a[j]==a[i])
            {
                count++;
                j++;
                printf("%d %d %d\n",i,j,count);
            }
        if(count%2!=0)
        {
            printf("VISHAL");
            return;
        }
        i=j;
    }
    printf("TANMAY");
    return;
}


