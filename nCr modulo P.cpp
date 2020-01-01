#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[10000007],invfac[10000007];
ll bigmod(ll a, ll b, ll c)
{
    if(b==0)
        return 1;

    if(b%2==0)
    {
        ll x=bigmod(a,b/2,c);
        return ((x%c)*(x%c))%c;
    }
    else return (a%c * bigmod(a,b-1,c))%c;
}
ll nCrModPLucas(ll n, ll r, ll p)
{
    //where n>=r
    vector<ll> ni,ri;
    fac[1] = invfac[1] = fac[0] = invfac[0] = 1;
    for(ll k=2;k<p;k++)
    {
        fac[k] = (fac[k-1]*k)%p;
        invfac[k] = (bigmod(k,p-2,p)*invfac[k-1])%p;
    }
    ll temp = n;
    while(temp!=0)
    {
        ni.push_back(temp%p);
        temp = temp/p;
    }
    temp = r;
    while(temp!=0)
    {
        ri.push_back(temp%p);
        temp = temp/p;
    }
    ll i = ni.size()-1;
    ll j = ri.size()-1;
    ll ans = 1;
    for(;i>=0;i--,j--)
    {
        if(j<0)
        {
            continue;
        }
        else
        {
            if(ni[i]<ri[j])
            {
                ans= 0;
            }
            else
            {
                cout<<ni[i]<<" "<<ri[j]<<endl;
                ans = (ans*((fac[ni[i]]%p)*(invfac[ri[j]]%p))%p*(invfac[ni[i]-ri[j]]%p)%p)%p;
            }
        }
    }
    ans = ans%p;
    return ans;
}
int main()
{
    // p is a prime
	ll n = 4, r = 2, p = 999377;
	cout << "Value of nCr % p is "<< nCrModPLucas(n, r, p);
	return 0;
}

