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
const int sz = 1e5+9;
#define MAX 20007
#define NIL 0
#define INF (1<<28)

vector< pair<ll,ll> >G[MAX];
ll n, m, match[MAX], dist[MAX];

bool bfs(ll mid) {
    ll i, u, v, len;
    queue< ll > Q;
    for(i=1; i<=n; i++) {
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
                v = G[u][i].first;
                if(G[u][i].second>mid)
                {
                    continue;
                }
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(ll u,ll mid) {
    ll i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i].first;
            if(G[u][i].second>mid)
            {
                continue;
            }
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v],mid)) {
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

ll hopcroft_karp(ll mid) {
    ll matching = 0, i;
    memset(match,0,sizeof match);
    memset(dist,0,sizeof dist);

    while(bfs(mid))
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i,mid))
                matching++;
    return matching;
}
int main(){
	ll pairs,x,i=0,z;
	scanf("%lld %lld",&n,&pairs);
	while( pairs-- ){
		ll x , y ;
		scanf("%lld %lld %lld",&x,&y,&z);
		G[x].push_back({y+n,z});
		G[y+n].push_back({x,z});
	}
	ll lo = 1;
	ll hi = 1e9;
	ll mid;
	ll ans = -1;
	while(lo<=hi)
    {
        mid = (lo+hi)/2;
        x = hopcroft_karp(mid);
        if(x==n)
        {
            ans =  mid;
            hi  = mid-1;
        }
        else lo = mid+1;
    }

	printf("%lld\n",ans);
}

