#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000
#define inf 1000000000000000
ll n,m;
struct data
{
    ll node;
    ll cost;
    data()
    {
        ;
    }
    data(ll _nod,ll cos)
    {
        node = _nod;
        cost = cos;
    }
};

bool operator<(data a,data  b)
{
    return a.cost>b.cost;
}
priority_queue<data > pq;
vector<data> v[N];

ll cost[N];
ll vis[N];
ll prim(ll ver)
{
    for(ll i=1;i<=n;i++)
    {
        vis[i] = 0;
        cost[i] = inf;
    }
    cost[ver] = 0;
    pq.push(data(ver,0));
    ll ans = 0;
    while(!pq.empty())
    {
        data temp = pq.top();
        pq.pop();
        if(vis[temp.node]==0)
        {
            vis[temp.node] = 1;
            ans+= temp.cost;
            for (ll i=0;i<v[temp.node].size();i++)
            {
                data pa = v[temp.node][i];
                if(vis[pa.node]==0 && pa.cost<cost[pa.node])
                {
                    cost[pa.node] = pa.cost;
                    pq.push(data(pa.node,pa.cost));
                }
            }
        }

    }
    return ans;
}

int main()
{
    long long t,i,j,k,x=0,y,p,q,r,ans;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>p>>q>>r;
        v[p].push_back(data(q,r));
        v[q].push_back(data(p,r));
    }
    ans = prim(1);
    cout<<ans<<endl;
    return 0;
}
