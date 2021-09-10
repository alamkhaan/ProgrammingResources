#include<bits/stdc++.h>
using namespace std;
int a[100003];
int st[100003][19];
int b[100009];
void SparseTable(int n)
{
    a[1]=0;
    for(int i=2; i<=n; i++)
    {
        a[i]= a[i/2]+1;
    }
    for (int i = 0; i < n; i++)
        st[i][0] = b[i];


    for (int j = 1; j <= 18; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L,int R)
{
    int j = a[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

