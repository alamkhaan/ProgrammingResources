#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<ll> adj[10000];
ll cnt = 0;
ll col[100000];
void coloring(ll node)
{
    if(node==n+1)
    {
        cnt++;
        for(ll i=1;i<=n;i++)
            cout<<col[i]<<" ";
        cout<<endl;
        return;
    }
    ll i,j;
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
            coloring(node+1);
        }
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
    cin>>m;
    coloring(1);
    cout<<cnt<<endl;
}
