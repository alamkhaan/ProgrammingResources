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
ll stirling[1009][1009];
ll N  =1e9+7;
ll fact[sz];
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    fact[0]  = 1;
    for(i=1;i<=1000;i++)
    {
        fact[i]  = (i*fact[i-1])%N;
    }
    stirling[0][0]  = 1;
    for(i=1;i<=1000;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0 )
                stirling[i][j]  =0;
            else if(i==j)
                stirling[i][j]  = 1;
            else if(j==1)
                stirling[i][j]  = 1;

            else stirling[i][j]  = (stirling[i-1][j-1] + (j*(stirling[i-1][j]))%N)%N;
        }
    }

    for(i=1;i<=100;i++)
    {
        for(j=1;j<=i;j++)
            cout<<stirling[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


