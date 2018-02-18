#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int count(long long int n, long long int x)
{
    long long int m=ceil(log(n)/log(2)); //m<=64. So we can place an upper limit of 64 and hence we get O(n)
    //printf("%lf\n",log(n));
    //printf("%lld\n",m);
    long long int j; //Iterator on numbers from 0 to n.
    long long int *bits=(long long int *)malloc((n+1)*sizeof(long long int));
    for(j=0;j<=n;j++)   //O(n)
        bits[j]=0;
    long long int i;//iterator through BIT positions
    long long int k; //Will hold current BIT Value

    for(i=1;i<=m;i++) //Constant, at most 64.
    {
        k=0; //Since for 0 all bits are Zero
        long long int shiftgap=(1 << (i-1)); //ith bit will toggle after 2^(i-1) spaces
        //printf("GAP is %lld\n",shiftgap);
        long long int shiftcount=0;
        for(j=0;j<=n;j++)
        {
            if(shiftcount==shiftgap)
            {
                shiftcount=0;
                if(k==0)
                    k=1;
                else if(k==1)
                    k=0;
                //printf("BIT %lld flips at %lld\n", i, j);
                bits[j]+=k;
                shiftcount++;
            }
            else
            {
                bits[j]+=k;
                shiftcount++;
            }

        }
    }
long long int answer=0;
    for(j=0;j<=n;j++)
        {
        //printf("%lld %lld\n",j, bits[j]);
        if(bits[j]==x)
        answer++;
        }

    printf("Answer is %d\n", answer);
    return answer;

}
long long int main()
{
    long long int m,k;
    scanf("%lld %lld",&m,&k);
    long long int high=1e8;
    long long int low=(1 << k)-1;
    //printf("%lld\n", low);
    while(low <= high)
    {
        long long int mid=(low+high)/2;
        printf("Current high %lld, mid %lld, low %lld \n",high, mid, low);
        int result=count(2*mid,k)-count(mid,k);
        if(result==m)
        {
            printf("%lld\n",mid);
            return;
        }

        else if(result<m)
            low=mid+1;
        else if(result>m)
            high=mid-1;
    }
    //printf("%lld\n",count(10,2));
}
