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
ll a[10009];
ll cost[10009];

ll sol(ll x,ll n)
{
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        ans+= abs(x-a[i])*cost[i];
    }
    return ans;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ma = low,mi = inf;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            ma = max(ma,a[i]);
            mi  =min(mi,a[i]);
        }
        for(i=0;i<n;i++)
            cin>>cost[i];
        ll lo,hi,mid1,mid2;

        lo = mi;
        hi = ma;
        ll ans=  inf;
        while(hi-lo>=3)
        {
            mid1 = lo+(hi-lo)/3;
            mid2 = hi  - (hi-lo)/3;
            ll x1 = sol(mid1,n);
            ll x2  = sol(mid2,n);

            if(x1<x2)
            {
                hi = mid2; //for maximum lo = mid1;
            }
            else if(x1>x2)
            {
                lo = mid1;  //for maximum hi = mid2;
            }
            else if(x1==x2)
            {
                lo = mid1;
                hi = mid2;
            }

        }
        for(j=lo;j<=hi;j++)
        {
            ans = min(ans,sol(j,n));
        }
        cout<<ans<<endl;
    }
    return 0;
}

