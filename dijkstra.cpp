#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100009

ll par[N];
ll dis[N];
ll vis[N],n;
struct data
{
    ll node,val;
    data()
    {
        ;
    }
    data(ll x,ll y)
    {
        node = x;
        val = y;
    }
};
vector<data> v[N];
bool operator<(data a,data b)
{
    return a.val>b.val;
}
priority_queue<data> pq;


void dijkstra(ll ver)
{
    for(ll i=1;i<=n;i++)
    {
        dis[i] = 10000000000;
        vis[i] = 0;
    }
    dis[ver] = 0;
    pq.push(data(ver,0));
    while(!pq.empty())
    {
        data temp = pq.top();
        pq.pop();
        if(vis[temp.node]==1)
        {
            continue;
        }
        vis[temp.node] = 1;
        for(ll i=0;i<v[temp.node].size();i++)
        {
            if(dis[temp.node]+v[temp.node][i].val<dis[v[temp.node][i].node])
            {
                dis[v[temp.node][i].node] = dis[temp.node]+v[temp.node][i].val;
                pq.push(data(v[temp.node][i].node,dis[v[temp.node][i].node]));
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<"From node "<<ver<<" to node "<<i<<" shortest distance - "<<dis[i]<<endl;
    }
}
int main()
{
    ll i,m,x,y,k;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>k;
        v[x].push_back(data(y,k));
    }
    dijkstra(1);
}
