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
ll vis[sz];
vector<ll> v[sz],v2[sz];
vector<ll> topSort;
void topsort(ll node)
{
    vis[node]  = 1;
    for(ll i=0;i<v[node].size();i++)
    {
        if(vis[v[node][i]]==0)
        {
            topsort(v[node][i]);
        }
    }
    topSort.pb(node);

}
ll cnt = 0;
void dfs(ll node)
{
    vis[node]  = 1;
    cnt++;
    for(ll i=0;i<v2[node].size();i++)
    {
        if(vis[v2[node][i]]==0)
        {
            dfs(v2[node][i]);
        }
    }
}
int main()
{

    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    cin>>t;
    ll cs  =0;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            vis[i]  =0;
            v[i].clear();
            v2[i].clear();

        }
        topSort.clear();
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            if(x!=y)
            {
                v[x].pb(y);
                v2[y].pb(x);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                topsort(i);
            }
        }
        k  =0;
        for(i=1;i<=n;i++)
            vis[i]  =0;
        for(j = topSort.size()-1;j>=0;j--)
        {
            if(!vis[topSort[j]])
            {
                cnt =  0;
                dfs(topSort[j]);
                k++;//number of SCC
            }
        }
        cout<<"Case "<<++cs<<": "<<k<<endl;
    }


    return 0;
}
