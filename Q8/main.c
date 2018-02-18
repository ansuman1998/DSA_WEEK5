#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//typedef long long int lld;

struct node
{
    char s[100];
    long long int ascii;
    int weight;
};
struct node data[100];
struct node sorted[100];
int main()
{
    int n,m;
    scanf("%d ",&n);
    int i,maxweight=-1,j;
    for(i=0;i<n;i++)
    {
        scanf("%s",&data[i].s);
        data[i].ascii=0;
        data[i].weight=0;
        m = strlen(data[i].s);
        for(j=0;j<m;j++)
            data[i].ascii+=data[i].s[j];
        long long int temp=data[i].ascii;
        while(temp!=0)
        {
            if(temp%2!=0)
                data[i].weight++;
            temp/=2;
        }
        if(data[i].weight>maxweight)
            maxweight=data[i].weight;
        printf("%s %lld %d\n",data[i].s, data[i].ascii, data[i].weight);

    }

    printf("%d\n",maxweight);
    int *c = (int *)malloc((maxweight+1)*sizeof(int));
    for(i=0;i<=maxweight;i++)
        c[i]=0;
    for(i=0;i<n;i++)
        c[data[i].weight]++;
      for(i=0;i<=maxweight;i++)
        printf("%d ", c[i]);
    printf("\n");

    for(i=1;i<=maxweight;i++)
        c[i]+=c[i-1];
    for(i=0;i<=maxweight;i++)
        printf("%d ", c[i]);
    printf("\n");

    for(i=n-1;i>=0;i--)
    {
        int index=c[data[i].weight]-1;
        strcpy(sorted[index].s,data[i].s);
        sorted[index].weight=data[i].weight;
        c[data[i].weight]--;
    }
    for(i=0;i<n;i++)
        printf("%s %d\n",sorted[i].s, sorted[i].weight);

}
