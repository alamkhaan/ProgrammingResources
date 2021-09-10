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
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define pb     push_back
#define inf     1e9
#define low     -2e18
#define PI        acos(-1.0)
#define endl  "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
const int sz = 1e5+9;
int vis[sz],par[sz],level[sz],d[sz],a[sz],query[12],m;
int cen_par[sz];
vector< vector<int> > v;
string str,str2;
const int N  = 1<<17;
ll ans[12];
const int LN = 17;
int P[N+9][LN];
void dfs(int node)
{
    vis[node]  =1;
    d[node]  += a[node];
    for(int i=0;i<v[node].size();i++)
    {
        if(vis[v[node][i]]==0)
        {
            P[v[node][i]][0]  = node;
            d[v[node][i]]  = d[node];
            level[v[node][i]]  = level[node]+1;
            dfs(v[node][i]);
        }
    }
}
void lca_init(int N)
{

    int i, j;
    for(j=1; (1<<j)<=N; j++)
    {
        for(i=1; i<=N; i++)
        {
            if(P[i][j-1]!=-1)
            {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int lca_query(int u,int v)
{
	if(level[u]<level[v])
        swap(u,v);

	int diff = level[u]-level[v];

	for(int i=0; i<LN; i++)
    {
        if((diff>>i)&1)
            u = P[u][i];
        if(u == v)
            return u;
    }

	for(int i=LN-1; i>=0; i--)
    {
        if(P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    }

	return P[u][0];
}
int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead)
{
    static vector<int> sz(g.size());
    function<void (int, int)> get_sz = [&](int u, int prev)
    {
        sz[u] = 1;
        for (auto v : g[u])
        {
            if (v != prev && !dead[v])
            {
                get_sz(v, u);
                sz[u] += sz[v];
            }
        }
    };
    get_sz(root, -1);
    int n = sz[root];
    function<int (int, int)> dfs = [&](int u, int prev)
    {
        for (auto v : g[u])
        {
            if (v != prev && !dead[v])
            {
                if (sz[v] > n / 2)
                {
                    return dfs(v, u);
                }
            }
        }
        return u;
    };
    return dfs(root, -1);
}

int dist(int p,int q)
{
    int r = lca_query(p,q);

    return d[p]+d[q]-2*d[r]+a[r];
}
void CentroidDecomposition(const vector<vector<int>> &g)
{
    int n = (int) g.size();
    vector<bool> dead(n, false);
    vector< vector<ll> > v2;
    v2.resize(n+3);
    ordered_set val[n+3];
    ordered_set ::  iterator it;
    function<void (int,int)> rec = [&](int start,int en)
    {
        int c = OneCentroid(start, g, dead);
        cen_par[c] = en==-1 ? c :  en;
        dead[c] = true;
        for (auto u : g[c])
            if (!dead[u])
            {
                rec(u,c);
            }
        if(en!=-1)
        {
            ll y;
            v2[c].pb(c);
            vector<ll> temp;
            for(ll j=0;j<v2[c].size();j++)
            {
                y = dist(cen_par[c],v2[c][j]);
                temp.pb(y);
                for(ll k=0;k<m;k++)
                {
                    if(y<=query[k])
                    {
                        ans[k]+=2;
                        ans[k]+= 2*val[cen_par[c]].order_of_key(query[k]-(y-a[cen_par[c]])+1);
                    }
                }
            }
            for(ll j=0;j<v2[c].size();j++)
            {
                v2[cen_par[c]].pb(v2[c][j]);
                val[cen_par[c]].insert(temp[j]);
            }
        }
        dead[c] = false;
    };
    rec(1,-1);
}

int main()
{
    int i,n,t,k,j,x=0,y=0;
    FAST
    cin>>n;
    v.resize(n+3);
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n-1; i++)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    memset (P,-1,sizeof(P));
    P[1][0]  =1;
    level[1] = 1;
    dfs(1);

    lca_init(n);
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>query[i];
    }

    CentroidDecomposition(v);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i]<=query[j])
                ans[j]++;
        }
    }
    for(i=0;i<m;i++)
        cout<<ans[i]<<endl;
}
