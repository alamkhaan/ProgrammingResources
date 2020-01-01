#include<bits/stdc++.h>
using namespace std;
int a[1000],n,heapSize;

void maxHeapify(int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest;

    if(l<=heapSize && a[l]>a[i])
        largest = l;
    else largest = i;

    if(r<=heapSize && a[r]>a[largest])
        largest = r;

    if(largest!=i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxHeapify(largest);
    }

}

void buildMaxHeap()
{
    heapSize = n;
    for(int i=n/2;i>=1;i--)
    {
        maxHeapify(i);
    }
}


void heapsort()
{
    buildMaxHeap();
    for(int i=n;i>1;i--)
    {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapSize--;
        maxHeapify(1);
    }
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    heapsort();
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";

}
