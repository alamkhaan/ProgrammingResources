/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef deque<ll> dl;
typedef stack<ll> stl;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll,ll> mll;
#define sf(n)     scanf("%lld",&n)
#define sff(n,m)     scanf("%lld %lld",&n,&m)
#define sfff(n,m,r)     scanf("%lld %lld %lld",&n,&m,&r)
#define sfs(n)     scanf("%s",n)
#define pf(n)     printf("%lld\n",n)
#define pff(n,m)     printf("%lld %lld\n",n,m)
#define pfff(n,m,r)     printf("%lld %lld %lld\n",n,m,r)
#define pfs(n)     printf("%s\n",n)
#define pfcs(i,n)     printf("Case %lld: %lld\n",i,n)
#define pb     push_back
#define prf     printf
#define inf     2e18
#define low     -1000000000000
#define PI        acos(-1.0)
#define rep1(i,n) for(i=1;i<n;i++)
#define rep0(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
#define repe1(i,n) for(i=1;i<=n;i++)
#define repe0(i,n) for(i=0;i<=n;i++)
#define repe(i,a,n) for(i=a;i<=n;i++)
vector<ll> v[100009];
ll vis[100009];
vector<ll> topSort;
void topsort(ll node,ll n)
{
    vis[node]  = 1;
    for(ll i=0;i<v[node].size();i++)
    {
        if(vis[v[node][i]]==0)
        {
            topsort(v[node][i],n);
        }
    }
    topSort.pb(node);

}

void bfs(ll node,ll n)
{
    vis[node] = 1;
    queue<ll> q;
    q.push(node);
    while(!q.empty())
    {
        ll temp = q.front();
        q.pop();
        for(ll i=0;i<v[temp].size();i++)
        {
            if(vis[v[temp][i]]==0)
            {
                vis[v[temp][i]] = 1;
                q.push(v[temp][i]);
            }
        }
    }
}


void dfs(ll node,ll n)
{
    vis[node]  = 1;
    for(ll i=0;i<v[node].size();i++)
    {
        if(vis[v[node][i]]==0)
        {
            dfs(v[node][i],n);
        }
    }
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m,ans;
    sf(t);
    rep0(i,t)
    {
        sff(n,m);
        rep0(j,m)
        {
            sff(x,y);
            v[x].pb(y);
        }
        repe1(j,n)
        {
            if(!vis[j])
            {
                topsort(j,n);
            }
        }
        repe1(j,n)
            vis[j] = 0;
        ll pq = 0;
        for(j = topSort.size()-1;j>=0;j--) // topsort
        {
            if(!vis[topSort[j]])
            {
                dfs(topSort[j],n); //or you can do it using dfs(topSort[j],n);
                pq++;
            }
        }
       // for(j=0;j<topSort.size();j++)
         //   cout<<topSort[j]<<endl;
       //repe1(j,n)
           // pff(j,id[j]);

        pfcs(i+1,pq);
        repe1(j,n)
        {
            vis[j] = 0;
            v[j].clear();
        }
        topSort.clear();
    }
    return 0;
}
