#include <stdio.h>
#include <stdlib.h>
void print(long int *a, long int n)
{
    long int i;
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}
long int factors(long int n)
{   long int prod=1,i;
    long int *S=(long int*)malloc((n+1)*sizeof(long int));
    long int *prime=(long int*)malloc((n+1)*sizeof(long int));
    for(i=1;i<=n;i++)
        prime[i]=1;
    for(i=0;i<=n;i++)
        S[i]=i;
    long int p;
    for(p=2;p<=n;p++)
    {
        if(prime[p]==1)
        {
            long inti;
            for(i=p;i<=n;i+=p)
            {   if(prime[i]==1)
                    S[i]=p;
                prime[i]=0;

            }
        }
    }

    print(S,n+1);

    long int N=n;
    long int curr,count;
    while(N>1)
    {
        curr=S[N];
        count=0;
        while(curr==S[N])
        {
            count++;
            N/=S[N];

        }
        //printf("%d %d\n",curr,count);
        prod*=(count+1);
    }
    printf("%d\n",prod);
    return prod;
}
long int main()
{
    /* MY FIRST SIEVE OF ERATOSTHENES IMPLEMENTATION */
    long int a,b,n;
    long int count=0;
    scanf("%ld %ld %ld",&a,&b,&n);
    long int i;
    for(i=a;i<=b;i++)
    {
        if(factors(i)==n)
            count++;
    }
    //factors(100);
    printf("%ld\n",count);

}
