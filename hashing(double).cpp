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
const int sz = 1e6+9;
ll modInverse(ll a, ll m)
{
	ll m0 = m;
	ll y = 0, x = 1;

	if (m == 1)
	return 0;

	while (a > 1)
	{
		ll q = a / m;
		ll t = m;

		m = a % m, a = t;
		t = y;

		y = x - q * y;
		x = t;
	}

	if (x < 0)
	x += m0;

	return x;
}

ll p_pow[sz],modIn[sz];
ll hash_val[sz];
const ll p = 31;
const ll m = 1e9 + 7;
void compute_hash(string const& s)
{
    hash_val[0] = s[0] - 'a' + 1;
    for (ll i =1;i<s.size();i++)
    {
        hash_val[i] = (hash_val[i-1] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    }
}
ll get_hash(string const& s)
{
    ll x = s[0] - 'a' + 1;
    for (ll i =1;i<s.size();i++)
    {
        x = (x + (s[i] - 'a' + 1) * p_pow[i]) % m;

    }
    return x;
}
void powCalc(ll n)
{
    p_pow[0] = 1;
    for(ll i=1;i<=n;i++)
    {
        p_pow[i] = (p*p_pow[i-1])%m;
        modIn[i]  =  modInverse(p_pow[i],m);
    }
}
ll query_hash(ll l,ll r)
{
    if(r<l)
        return 0;
    if(l==0)
        return hash_val[r];
    else return ((((hash_val[r] - hash_val[l-1])+m)%m)*modIn[l])%m;
}
ll p_pow2[sz],modIn2[sz];
ll hash_val2[sz];
const ll p2 = 137;
const ll m2 = 982563121;
void compute_hash2(string const& s)
{
    hash_val2[0] = s[0] - 'a' + 1;
    for (ll i =1;i<s.size();i++)
    {
        hash_val2[i] = (hash_val2[i-1] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;

    }
}
ll get_hash2(string const& s)
{
    ll x = s[0] - 'a' + 1;
    for (ll i =1;i<s.size();i++)
    {
        x = (x + (s[i] - 'a' + 1) * p_pow2[i]) % m2;

    }
    return x;
}
void powCalc2(ll n)
{
    p_pow2[0] = 1;
    for(ll i=1;i<=n;i++)
    {
        p_pow2[i] = (p2*p_pow2[i-1])%m2;
        modIn2[i]  =  modInverse(p_pow2[i],m2);
    }
}
ll query_hash2(ll l,ll r)
{
    if(r<l)
        return 0;
    if(l==0)
        return hash_val2[r];
    else return ((((hash_val2[r] - hash_val2[l-1])+m2)%m2)*modIn2[l])%m2;
}
ll mergeHash(ll l1,ll r1,ll l2,ll r2)
{
    return (query_hash(l1,r1)   + query_hash(l2,r2)*p_pow[r1-l1+1])%m;
}
ll mergeHash2(ll l1,ll r1,ll l2,ll r2)
{
    return (query_hash2(l1,r1)   + query_hash2(l2,r2)*p_pow2[r1-l1+1])%m2;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0;
    string str;
    cin>>str;
    n = str.size();
    powCalc(n);
    compute_hash(str);
    for(i=0;i<=n;i++)
    {
        cout<<i<<" "<<hash_val[i]<<endl;
    }
    cout<<query_hash(2,3)<<endl;
    cout<<query_hash(0,1)<<endl;
    return 0;
}

