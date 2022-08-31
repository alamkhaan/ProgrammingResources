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
ll a[sz],b[sz],n;
ll N = 51123987;
string str,str2;
ll dp[155][155][155][4];

ll sol(ll pos,ll cnt1,ll cnt2,ll pre)
{
    if(dp[pos][cnt1][cnt2][pre]!=-1)
    {
        return dp[pos][cnt1][cnt2][pre];
    }
    if(pos==n)
    {
        if(abs(cnt1-cnt2)<=1 && abs((n-(cnt1+cnt2))-(cnt1))<=1 && abs((n-(cnt1+cnt2))-(cnt1))<=1)
        {
            return dp[pos][cnt1][cnt2][pre]  = 1;
        }
        else
            return dp[pos][cnt1][cnt2][pre] = 0;
    }
    ll ans = 0;
    if(pos==n-1)
    {
        if(pre==1)
        {
            return sol(pos+1,cnt+1,cnt2,0);
        }
        else if(pre==2)
        {
            return sol(pos+1,cnt,cnt2+1,0);
        }
        else
            return sol(pos+1,cnt,cnt2,0);
    }
    if(pre==1)
    {
        return sol(pos+1,cnt+1,cnt2,str[pos+1]-96);
    }
    else if(pre==2)
    {
        return sol(pos+1,cnt,cnt2+1,str[pos+1]-96);
    }
    else
        return sol(pos+1,cnt,cnt2,str[pos+1]-96);

    if(pre!=str[pos+1]-96)
    {

    }



}

int main()
{
    ll i,t,k,j,x=0,y=0,m;
    FAST
    cin>>n;
    cin>>str;
    memset(dp,-1,sizeof dp);
    cout<<sol(0,0,0,str[0]-96)<<endl;
    return 0;
}

