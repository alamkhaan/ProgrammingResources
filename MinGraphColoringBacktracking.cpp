#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<ll> adj[10000];
ll col[100000];
void coloring(ll node)
{
    if(node==n+1)
    {
        for(ll i=1;i<=n;i++)
            cout<<col[i]<<" ";
        cout<<endl;
        return;
    }
    ll i,j;
    bool flag2 = false;
    for(i=1;i<=m;i++)
    {
        col[node] = i;
        bool flag = false;
        for(j=0;j<adj[node].size();j++)
        {
            if(col[adj[node][j]]==col[node])
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            flag2 = true;
            coloring(node+1);
        }
    }
    if(!flag2)
    {
        col[node] = ++m;
        coloring(node+1);
    }
    col[node] = 0;
}


int main()
{
    ll i,j,x,y,k;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    m  = 1;
    coloring(1);
    cout<<m<<endl;
}
