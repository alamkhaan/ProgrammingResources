#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll dp[1000][1000];

void path(ll i,ll j)
{
    if(i==0 || j==0)
        return;
    if(a[i-1]==b[j-1])
    {
        path(i-1,j-1);
        cout<<a[i-1];
    }
    else
    {
        if(dp[i][j]==dp[i-1][j])
        {
            path(i-1,j);
        }
        else path(i,j-1);
    }
}
int main()
{
    ll i,j,n,m;
    cin>>a;
    cin>>b;
    n = a.size();
    m = b.size();
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    path(n,m);
    return 0;
}

