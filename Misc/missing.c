#include<stdio.h>

int main()
{
    int a[]={0,1,2,3,4,5,7,8,9};
    int n=9;
    int l=0,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(mid!=a[mid])
        {
            if(mid==0||a[mid-1]==mid-1)
            {
                printf("\n Missing %d\n",mid);
                return 0;
            }
            r=mid-1;
        }
        else
            l=mid+1;
        if(l==n)
            {
                printf("\n Missing %d\n",l);
                return 0;
            }
    }
    return 0;
}
