#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll dp[1000][1000];
ll lcs(ll i,ll j)
{
    if(i==0 || j==0)
        return dp[i][j] = 0;
    else if(dp[i][j]!=-1)
        return dp[i][j];
    else if(a[i-1]==b[j-1])
    {
        return dp[i][j] = lcs(i-1,j-1)+1;
    }
    else
    {
        return dp[i][j] = max(lcs(i-1,j),lcs(i,j-1));
    }
}
int main()
{
    ll i,j,n,m;
    memset(dp,-1,sizeof(dp));
    cin>>a;
    cin>>b;
    n = a.size();
    m = b.size();
    cout<<lcs(n,m)<<endl;
    return 0;
}

