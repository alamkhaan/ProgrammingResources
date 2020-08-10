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
#define N 1000000
bool num[1000009];
vector<ll> prime;
void seive()
{
    ll i,j;
    num[1] = true;
    for(i=4; i<=N; i+=2)
        num[i] = true;
    for(i=3; i<=sqrt(N); i+=2)
    {
        if(num[i]==false)
        {
            for(j=i*i; j<=N; j+=2*i)
            {
                num[j] = true;
            }
        }
    }
    prime.pb(2);
    for(i=3; i<=N; i+=2)
    {
        if(!num[i])
            prime.pb(i);
    }
}

ll NOD(ll n)
{
    //sieve(1e6)
    ll res=1;
    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            ll p=0;     // Counter for power of prime
            while(n%prime[i]==0)
            {
                n/=prime[i];
                p++;
            }

            res*=(p+1);     // Multiply with answer
        }
    }
    if(n!=1)
        res*=2;      // Remaining prime has power p^1. So multiply with 2/
    return res;
}

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
    if(x==1 || x==n-1)
        return true;

    while(d!=n-1 )
    {
        d*=2;
        x= mulMod(x,x,n);
        if(x==n-1)
            return true;
        if (x==1)
            return false;
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
    for(ll i=1;; i++)
    {
        x=y=2;
        while(true)
        {
            x=(mulMod(x,x,n)+i)%n;
            y=(mulMod(y,y,n)+i)%n;
            y=(mulMod(y,y,n)+i)%n;
            g=__gcd(abs(x-y),n);
            if(g==n)
                break;
            if(g>1)
                return g;
        }
    }
}
ll NodBig(ll n)
{
    //sieve(1e6)
    ll res=1;
    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            ll p=0;     // Counter for power of prime
            while(n%prime[i]==0)
            {
                n/=prime[i];
                p++;
            }

            res*=(p+1);     // Multiply with answer
        }
    }
    if(n>1)
    {
        if(isPrime(n))
        {
            res = res*2;
        }
        else
        {
            ll n1 = pollard(n);
            if(n1==n)
            {
                res = res*3;
            }
            else
                res =res*4;
        }
    }
    return res;
}

void prime_fact(ll n,vector<pair<ll,ll> > &v)
{
    for(ll i=0;prime[i]*prime[i]<=n && i<prime.size();i++)
    {
        ll cnt =0;
        while(n%prime[i]==0)
        {
            n = n/prime[i];
            cnt++;
        }
        if(cnt>0)
        {
            v.pb({prime[i],cnt});
        }
    }
    if(n>1)
    {
        if(isPrime(n))
        {
            v.pb({n,1});
        }
        else
        {
            ll x = pollard(n);
            if(x*x==n)
            {
                v.pb({x,2});
            }
            else
            {
                v.pb({x,1});
                v.pb({n/x,1});
            }
        }
    }

}


void allDivisor(ll n)
{
    vector<pair<ll,ll> >fact;
    ll j,k,x,y;
    prime_fact(n,fact);
    vector<ll> div;
    div.pb(1);
    for(j=0; j<fact.size(); j++)
    {
        x = div.size();
        y = 1;
        for(ll l=0; l<fact[j].second; l++)
        {
            y = y*fact[j].first;
            for(k=0; k<x; k++)
            {
                div.pb(div[k]*y);
            }
        }
    }
    sort(div.begin(),div.end());
    for(j=0; j<div.size(); j++)
        cout<<div[j]<<" ";
    cout<<endl;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    seive();
    for(i=2;i<=1000000;i++)
        x = max(x,NOD(i));
    cout<<x<<endl;
    ll a[100009];
    sf(n);
    rep0(j,n)
    {
        sf(a[j]);
        cout<<NodBig(a[j])<<endl;
    }
    return 0;
}
