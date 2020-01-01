#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100009

struct Edge
{
    ll u,v,w;
    Edge()
    {
        ;
    }
    Edge(ll _u,ll _v,ll _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

ll dis[N];
vector<Edge> E;
ll n;
bool flag;

void bellmanFord(ll s)
{
    for(ll i=1;i<=n;i++)
    {
        dis[i] = 10000000000;
    }
    dis[s] = 0;
    for(ll i=1;i<=n+1;i++)
    {
        flag = false;
        for(ll j=0;j<E.size();j++)
        {
            if(dis[E[j].v]>dis[E[j].u]+E[j].w)
            {
                dis[E[j].v] = dis[E[j].u]+E[j].w;
                flag = true;
            }
        }
        if(flag && i==n+1)
        {
            cout<<"Negative cycle exist"<<endl;
            return;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<"From node "<<s<<" to node "<<i<<" shortest distance - "<<dis[i]<<endl;
    }
}

int main()
{
    ll i,m,x,y,k;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>k;
        E.push_back(Edge(x,y,k));
        E.push_back(Edge(y,x,k));
    }
    bellmanFord(1);
}
