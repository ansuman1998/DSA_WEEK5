#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int maxofcolumn(int **a,int index, int n, int m)
{
    int i;
    int j=index;
    int max=-1;
    int maxi=-1;

    for(i=0;i<n;i++)
    {for(j=0;j<m;j++)
        printf("%d ", a[i][j]);
    printf("\n");
    }
    for(i=0;i<n;i++)
    {
        if(a[i][index]>max)
            {

                max=a[i][index];
                maxi=i;

            }
    }

    return maxi;
}
int find_peak(int **a, int n, int m, int low, int high)
{
   int mid=(low+high)>>1;
   printf("Current middle %d\n", mid);
   if(mid==0||mid==m-1)
   {
       return a[maxofcolumn(a,mid,n,m)][mid];
   }

   int max_index = maxofcolumn(a,mid,n,m);
   printf("Maximum ka index %d\n",max_index);
   int max = a[max_index][mid];
   printf("%d\n",max);
   if(a[max_index][mid-1]>max ||(max_index+1<n) && a[max_index+1][mid-1] > max || (max_index-1>=0) && a[max_index-1][mid-1]>max)
    find_peak(a,n,m,low,mid);
   else if(a[max_index][mid+1]>max ||(max_index+1<n) && a[max_index+1][mid+1] > max || (max_index-1>=0) && a[max_index-1][mid+1]>max)
    find_peak(a,n,m,mid+1,high);


}
int main()
{
   int m=3,n=3;

   scanf("%d %d", &n, &m);
   int **a=(int **)malloc(n*sizeof(int));
   int i,j;
   for(i=0;i<n;i++)
    a[i]=(int *)malloc(m*sizeof(int));

   for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%d",&a[i][j]);



    printf("Array accepted\n");
    printf("%d\n",find_peak(a,n,m,0,m-1));
}
