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
#define LN 18
struct data
{
    ll x,cost;
    data()
    {

    }
    data(ll _x,ll _cost)
    {
        x = _x;
        cost = _cost;
    }
};
vector<data> v[100003];
ll n;
ll vis[100003],par[100003],edge[100003];
ll P[100003][18];
ll longest[100003][18];
ll shortest[100003][18];
ll level[100003];
void bfs()
{
    for(ll i=1;i<=n;i++)
    {
        vis[i] = 0;
    }
    level[1] = 0;
    vis[1] = 1;
    par[1] = -1;
    edge[1] = -1;
    queue<ll> q;
    q.push(1);
    while(!q.empty())
    {
        ll temp = q.front();
        q.pop();
        for(ll i=0;i<v[temp].size();i++)
        {
            data p = v[temp][i];
            if(vis[p.x]==0)
            {
                vis[p.x] = 1;
                q.push(p.x);
                par[p.x] = temp;
                edge[p.x] = p.cost;
                level[p.x] = level[temp]+1;
            }
        }
    }
}

void lca_init(ll N)
  {
      memset (P,-1,sizeof(P));
      ll i, j;
      for (i=1;i<=N;i++)
      {
          P[i][0] = par[i];
          longest[i][0] = edge[i];
          shortest[i][0] = edge[i];
      }

      for(j=1;(1<<j)<=N;j++)
      {
         for(i=1;i<=N;i++)
         {
             if(P[i][j-1]!=-1)
             {
                 if(P[P[i][j-1]][j-1]!=-1)
                 {
                    longest[i][j] = max(longest[i][j-1],longest[P[i][j-1]][j-1]);
                    shortest[i][j] = min(shortest[i][j-1],shortest[P[i][j-1]][j-1]);
                 }
                 P[i][j] = P[P[i][j-1]][j-1];
             }
         }
      }
 }

 ll lca_query(ll N,ll p,ll q)
{
      ll tmp,log,i;

      if (level[p]<level[q])
      {
          swap(p,q);
      }
      log=1;
      while(1)
      {
          ll next= log+1;
          if((1<<next)>level[p])
          {
              break;
          }
          log++;
      }
      for (i=log;i>=0;i--)
      {
          if(level[p]-(1<<i)>=level[q])
              p = P[p][i];
      }

      if (p==q)
      {
          return p;
      }
      for (i = log; i >= 0; i--)
      {
          if(P[p][i]!=-1 && P[p][i]!=P[q][i])
          {
              p = P[p][i];
              q = P[q][i];
          }
      }

      return par[p];
}
ll value(ll p,ll q)
{
    ll tmp,j,i;
    for(i=0;;i++)
    {
        if(level[p]-(1<<i)<level[q])
            break;
    }
    if(i!=0)
    {
        i--;
        tmp = longest[p][i];
    }
    else
    {
        return low;
    }
    p = P[p][i];
    for(j=i;j>=0;j--)
    {
        if(level[p]-(1<<j)>=level[q])
        {
            tmp = max(tmp,longest[p][j]);
            p = P[p][j];
        }
    }
    return tmp;
}

ll value2(ll p,ll q)
{
    ll tmp,j,i;
    for(i=0;;i++)
    {
        if(level[p]-(1<<i)<level[q])
            break;
    }
    if(i!=0)
    {
        i--;
        tmp = shortest[p][i];
    }
    else
    {
        return inf;
    }
    p = P[p][i];
    for(j=i;j>=0;j--)
    {
        if(level[p]-(1<<j)>=level[q])
        {
            tmp = min(tmp,shortest[p][j]);
            p = P[p][j];
        }
    }
    return tmp;
}

int main()
{
    ll i,t,k,j,x=0,y=0,m,mx,mn;
    sf(t);
    rep0(i,t)
    {
        sf(n);
        rep0(j,n-1)
        {
            sfff(x,y,k);
            v[x].pb(data(y,k));
            v[y].pb(data(x,k));
        }
        bfs();
        lca_init(n);
        sf(m);
        prf("Case %lld:\n",i+1);
        rep0(j,m)
        {
            sff(x,y);
            k = lca_query(n,x,y);
            mx  =value(x,k);
            mx = max(mx,value(y,k));
            mn  =value2(x,k);
            mn = min(mn,value2(y,k));
            pff(mn,mx);
        }
        repe1(j,n)
        {
            v[j].clear();
        }
    }
    return 0;
}

