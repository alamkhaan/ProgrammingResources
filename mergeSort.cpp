#include<bits/stdc++.h>
using namespace std;

#define infinity INT_MAX

void Merge(int a[],int p,int q,int r)
{
    int i,j,k,n1,n2;
    n1 = q-p+1;
    n2 = r - q;
    int L[n1+3],R[n2+3];
    for(i=p,j=0;i<=q;i++,j++)
    {
        L[j] = a[i];
    }
    for(i=q+1,j=0;i<=r;i++,j++)
    {
        R[j] = a[i];
    }

    L[n1] = infinity;
    R[n2] = infinity;
    i = 0;
    j = 0;

    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }


}
void mergesort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q = (p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        Merge(a,p,q,r);
    }
}
int main()
{
    int n,j,i,r,p,a[100000];
        cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
