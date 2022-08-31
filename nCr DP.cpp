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
ll fact[sz];
ll invfact[sz];
ll inv[sz];
ll N = 1e9+7;
void pre_compute(ll n)
{
    fact[0]  =1;
    ll i;
    for(i=1;i<=n;i++)
    {
        fact[i]  =(i*fact[i-1])%N;
    }

    inv[1] = 1;
    for( i = 2; i <=n; ++i)
        inv[i] = inv[N % i] * (N -N/ i) % N;

    invfact[0]  =1;

    for(i=1;i<=n;i++)
    {
        invfact[i]  =(inv[i]*invfact[i-1])%N;
    }
}

ll binomial(ll n,ll r,ll p)
{
    ll ans = (((fact[n] * invfact[r])% p )* invfact[n-r])% p;
    return ans;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    pre_compute(2e5);
    cout<<binomial(5,2,N)<<endl;;
    return 0;
}

