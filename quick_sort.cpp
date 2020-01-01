#include<bits/stdc++.h>
using namespace std;

int a[100000];
void quick(int f,int l)
{
    if(f<l)
    {
        int i,j,temp;
        i  = f+1;
        while(a[i]<a[f])
            i++;
        j = l;
        while(a[j]>a[f])
            j--;
        while(i<j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;

            while(a[i]<a[f])
                i++;
            while(a[j]>a[f])
                j--;

        }
        temp = a[j];
        a[j] = a[f];
        a[f] = temp;
        quick(f,j-1);
        quick(j+1,l);
    }
}


int main()
{
    int n,j,i,r,p;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    quick(0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

