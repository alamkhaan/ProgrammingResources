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
ll a[100009];
bool num[100009];
vector<ll> prime;
void seive()
{
    ll i,j;
    num[1] = true;
    for(i=4;i<=N;i+=2)
        num[i] = true;
    for(i=3;i<=sqrt(N);i+=2)
    {
        if(num[i]==false)
        {
            for(j=i*i;j<=N;j+=2*i)
            {
                num[j] = true;
            }
        }
    }
    prime.pb(2);
    for(i=3;i<=N;i+=2)
    {
        if(!num[i])
            prime.pb(i);
    }
}

ll nod(ll n)
{
    if(!num[n])
    {
        return 2;
    }
    ll cnt = 0,ans=0;
    while(n%2==0)
    {
        n = n/2;
        cnt++;
    }
    ll i = 1;
    ans = cnt+1;
    cnt = 0;
    while(prime[i]<=sqrt(n))
    {
        if(n%prime[i]==0)
        {
            cnt++;
            n = n/prime[i];
        }
        else
        {
            i++;
            ans = ans*(cnt+1);
            cnt = 0;
        }
    }
    if(n>1)
    {
        if(cnt==0)
            ans = ans*2;
        else
        {
            if(prime[i]==n)
            {
                cnt++;
                ans = ans*(cnt+1);
            }
            else
            {
                ans = ans*(cnt+1);
                ans = ans*2;
            }
        }
    }
    return ans;
}

ll NOD(ll n)  //substitute
{
    //sieve(1e6)
    ll sqrtn = sqrt(n);
    ll res=1;
    for(int i=0; i<prime.size() && prime[i]<=sqrtn; i++)
    {
        if(n%prime[i]==0)
        {
            ll p=0;     // Counter for power of prime
            while(n%prime[i]==0)
            {
                n/=prime[i];
                p++;
            }
            p++;        // Increase it by one at end
            sqrtn = sqrt(n);
            res*=p;     // Multiply with answer
        }
    }
    if(n!=1)
        res*=2;      // Remaining prime has power p^1. So multiply with 2/
    return res;
}


int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    seive();
    sf(n);
    rep0(j,n)
    {
        sf(a[j]);
        cout<<nod(a[j])<<endl;
    }
    return 0;
}
