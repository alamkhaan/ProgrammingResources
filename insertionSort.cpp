#include<bits/stdc++.h>
using namespace std;
int a[1000],n;

void insertion_sort()
{
    int i,j,temp;
    for(j=2;j<=n;j++)
    {
        temp = a[j];
        i = j-1;
        while(a[i]>temp)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = temp;
    }
}
int main()
{
    int i,j;
    cin>>n;
    a[0] = INT_MIN;
    for(i=1;i<=n;i++)
       cin>>a[i];
    insertion_sort();
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
