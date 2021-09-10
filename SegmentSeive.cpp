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
const int sz = 1e5+9;
#include<bits/stdc++.h>
using namespace std;
vector<ll> ar;
bool arr[3000009];
bool check(ll N,ll pos)
{
    return (bool)(N & (1LL<<pos));
}

ll Set(ll N,ll pos)
{
    return N=N | (1LL<<pos);
}


void normalSieve(ll N)
{

    ll i, j, sqrtN,status[N/64+1];
    memset(status,0,sizeof status);
    sqrtN = ll( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( check(status[i/64],i%64)==0) //if( Check(status[i>>5],i&31)==0)
        {
            for( j = i*i; j <= N; j += 2*i )
            {
                status[j/64]=Set(status[j/64],j % 64)   ; // status[j>>5]=Set(status[j>>5],j & 31)
            }
        }
    }
    ar.push_back(2);
     for(i=3;i<=N;i+=2)
        if( check(status[i/64],i%64)==0)  //if( Check(status[i>>5],i&31)==0)
            ar.push_back(i);
}
int main()
{
    ll a,b;
    ll i,n,t,k,j,x=0,y=0,m;
    ll cs =0;
    string str,str2;
    FAST
    cin>>t;

    while(t--)
    {
        ar.clear();
        memset(arr,0,sizeof arr);
        cin>>a>>b;
        ll l = sqrt(b);
        normalSieve(l);
        for(i=0;i<ar.size() && ar[i]<=l;i++)
        {
            ll p = ar[i];
            ll j = p * p;
            if(j<a)
                j=((a+p-1)/p)*p;

            for(;j<=b;j+=p)
            {
                arr[j-a] = true; // mark them as not prime
            }
        }
        for(ll i=a;i<=b;i++)
        {
            // If it is not marked, then it is a prime
            if(arr[i-a]==0 && i!=1)
                cout<<i<<endl;
        }


    }

    return 0;
}



