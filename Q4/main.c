#include <stdio.h>
#include <stdlib.h>
void print(int **a, int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");


}
void rotate(int **a, int lowr, int highr, int lowc, int highc, int m, int n)
{
    int temp = a[lowr][lowc];
    //printf("%d\n", temp);
    int i,j;
    j=lowc;
    i=lowr;
    for(j=lowc;j<highc;j++)
    {
        a[i][j]=a[i][j+1];
    }
    print(a,m,n);
    for(i=lowr+1;i<=highr;i++)
    {
        a[i-1][j]=a[i][j];
    }
    print(a,m,n);
    i=highr;
    for(j=highc;j>lowc;j--)
    {
        a[i][j]=a[i][j-1];
    }
    print(a,m,n);

    for(i=highr;i>lowr;i--)
    {
        a[i][j]=a[i-1][j];
    }

    print(a,m,n);
    a[lowr+1][lowc]=temp;

}
int main()
{
    int m, n, r;
    scanf("%d %d %d",&m, &n, &r);
    int **a=(int **)malloc(m*sizeof(int *));
    int i,j;
    for(i=0;i<m;i++)
        a[i]=(int *)malloc(n*sizeof(int));
    int k=1;
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            a[i][j]=k++;
            k+=2;
        }
    print(a,m,n);
    int numberofrings;
    if(m<n)
        numberofrings=m/2;
    else
        numberofrings=n/2;
    printf("Number of rings is %d\n", numberofrings);
    for(i=0;i<numberofrings;i++)
    {   int lengthofring=(m-2*i)*(n-2*i)-(m-2*i-2)*(n-2*i-2);
        int rot = r%lengthofring;
        while(rot!=0)
        {rotate(a,i,m-1-i,i,n-1-i,m,n);
        rot--;
        }
        //rotate(a,i,m-1-i,i,n-1-i,m,n);
    }
    //rotate(a,1,m-2,1,n-2,m,n);
    print(a,m,n);
}
