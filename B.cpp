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
const int sz = 1e3+9;
ll a[sz],b[sz];
string str,str2;
vector<ll> v[sz];
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    cin>>n>>m;
    cin>>k;
    ll total  = k;
    for(i=0;i<k;i++)
    {
        cin>>x;
        a[x]  = 1;
    }
    for(i=0;i<n;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>x;
            v[i].pb(x);
        }
    }
    for(i=0;i<10*n;i++)
    {
        x = i%n;
        for(j=0;j<v[x].size();j++)
        {
            if(a[v[x][j]]==0)
            {
                total++;
            }
            else total--;
            a[v[x][j]] = !a[v[x][j]];
        }
        if(total==0)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}

