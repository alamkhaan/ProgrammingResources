#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main()
{
    cout<<bigmod(2,29,31)<<endl;
}

