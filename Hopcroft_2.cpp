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
#define inf     2e18
#define low     -2e18
#define PI        acos(-1.0)
#define endl  "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
const int sz = 3e5+9;
ll a[sz],b[sz];
string str,str2;
#define MAX 1007
#define NIL 0
#define INF (1<<28)

vector< ll >G[MAX];
ll N, m, match[MAX], dist[MAX];

bool bfs() {
    ll i, u, v, len;
    queue< ll > Q;
    for(i=1; i<=N; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(ll u) {
    ll i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

ll hopcroft_karp() {
    ll matching = 0, i;
    memset(match,0,sizeof match);
    memset(dist,0,sizeof dist);

    while(bfs())
        for(i=1; i<=N; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    cin>>t;
    for(ll cs= 1;cs<=t;cs++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>b[i];
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i]==0)
                {
                    if(b[j]==0)
                    {
                        G[i].pb(j+n);
                        G[j+n].pb(i);
                    }
                }
                else if(b[j]%a[i]==0)
                {
                    G[i].pb(j+n);
                    G[j+n].pb(i);
                }
            }
        }
        N = n+m;
        cout<<"Case "<<cs<<": "<<hopcroft_karp()<<endl;
        for(i=1;i<=n+m;i++)
            G[i].clear();
    }
    return 0;
}


