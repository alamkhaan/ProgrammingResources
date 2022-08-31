/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef deque<ll> dl;
typedef stack<ll> stl;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll,ll> mll;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
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
#define endl  "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
vector<ll> v[100009];
vector<ll> v2[100009];
stack<ll> s;
ll vis[10009];
void dfs(ll node)
{
    vis[node]  =1;
    for(ll i=0;i<v[node].size();i++)
    {
        if(vis[v[node][i]]==0)
        {
            dfs(v[node][i]);
        }
    }
    s.push(node);
}

void dfs2(ll node)
{
    vis[node]  =1;
    cout<<node<<" ";
    for(ll i=0;i<v2[node].size();i++)
    {
        if(vis[v2[node][i]]==0)
        {
            dfs2(v2[node][i]);
        }
    }

}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n>>m;

        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            v[x].pb(y);
            v2[y].pb(x);
        }
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }
        for(i=1;i<=n;i++)
        {
            vis[i] = 0;
        }
        y  =0;
        while(!s.empty())
        {
            x =s.top();
            s.pop();
            if(vis[x]==0)
            {
                y++;
                dfs2(x);
                cout<<endl;
            }
        }
        pfcs(j,y);
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            v2[i].clear();
            vis[i] = 0;
        }


    }
    return 0;
}

