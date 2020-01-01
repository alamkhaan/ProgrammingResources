#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge
{
    ll u,v,w;
    Edge()
    {
        ;
    }
    Edge(ll _u,ll _v,ll _w)
    {
        w = _w;
        u = _u;
        v = _v;
    }
};

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

ll par[1000],n;
vector<Edge> E;

ll Find(ll x)
{
    if(par[x]==x)
        return x;
    return par[x] = Find(par[x]);
}

void kruskal()
{
    sort(E.begin(),E.end(),cmp);
    ll ans = 0;
    for(ll i=0;i<E.size();i++)
    {
        if(Find(E[i].u)!=Find(E[i].v))
        {
            par[par[E[i].u]] = par[E[i].v];
            ans+= E[i].w;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    long long m,t,i,j,k,x=0,y,p,q,r;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>p>>q>>r;
        E.push_back(Edge(p,q,r));
    }
    for(i=1;i<=n;i++)
        par[i] = i;
    kruskal();
    return 0;
}

