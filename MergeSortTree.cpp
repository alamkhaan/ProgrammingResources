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
#define endl  "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
#define all(v) v.begin(), v.end()
ll num[100009];
vector<ll> v[400009];
void build(ll att,ll L,ll R)
{
    if(L==R)
    {
        v[att].pb(num[L-1]);
        return;
    }

    ll mid = (L+R)/2;
    build(att*2,L,mid);
    build(att*2+1,mid+1,R);
    merge(all(v[att*2]), all(v[att*2+1]), back_inserter(v[att]));
}
ll query(ll att,ll L,ll R,ll l,ll r,ll p,ll q)
{
    if(l>R || r<L)
        return 0;
    if(l<=L && r>=R)
    {
        for(ll i=0;i<v[att].size();i++)
            cout<<v[att][i]<<" ";
        cout<<endl;
        ll x = lower_bound(v[att].begin(),v[att].end(),p) - v[att].begin();
        ll y = upper_bound(v[att].begin(),v[att].end(),q) - v[att].begin();
        return y-x;
    }
    ll mid = (L+R)/2;
    ll x = query(att*2,L,mid,l,r,p,q);
    ll y = query(att*2+1,mid+1,R,l,r,p,q);

    return x+y;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m,p,q;
    sf(n);
    rep0(i,n)
    {
        sf(num[i]);
    }
    build(1,1,n);
    sf(m);
    for(i=1;i<=m;i++)
    {
        sff(x,y);
        sff(p,q);
        cout<<query(1,1,n,x,y,p,q)<<endl;
    }
    return 0;
}

