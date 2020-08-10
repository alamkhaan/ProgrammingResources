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
ll mulMod(ll a,ll b,ll n)
{
    ll res = 0;
    a = a%n;
    while(b>0)
    {
        if(b%2==1)
        {
            res = (res+a)%n;
        }
        a = (a*2)%n;
        b/= 2;
    }
    return res;
}
ll bigMod(ll x,ll y, ll p)
{
    ll res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = mulMod(res,x,p);


        y = y>>1;
        x =  mulMod(x,x,p);
    }
    return res;
}
ll primetest[9] = {2,3,5,7,11,13,17,19,23};

bool millerTest(ll a,ll d,ll n)
{
    ll x = bigMod(a,d,n);
    if(x==1 || x==n-1) return true;

    while(d!=n-1 )
    {
        d*=2;
        x= mulMod(x,x,n);
        if(x==n-1) return true;
        if (x==1)  return false;
    }
    return  false;
}

bool isPrime(ll n)
{
    if (n <= 1 || n == 4)
        return false;

    if (n <= 3)
        return true;


    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    ll k = 9;
    for (ll i = 0; i < k && primetest[i]<n; i++)
    {
         if(!millerTest(primetest[i],d, n))
              return false;
    }

    return true;
}
ll pollard(ll n)
{
    ll x,y,g,j;
    if(n%2==0)
        return 2;
    for(ll i=1;;i++)
    {
        x=y=2;
        while(true)
        {
            x=(mulMod(x,x,n)+i)%n;
            y=(mulMod(y,y,n)+i)%n;
            y=(mulMod(y,y,n)+i)%n;
            g=__gcd(abs(x-y),n);
            if(g==n) break;
            if(g>1) return g;
        }
    }
}

int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    while(cin>>n)
    {
        if(n==-1)
            break;
        //cout<<isPrime(n)<<endl;
        cout<<pollard(n*n)<<endl;
    }
    return 0;
}

