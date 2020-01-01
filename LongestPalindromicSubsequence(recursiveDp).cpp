#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll dp[1000][1000];

ll lps(ll i,ll j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    else if(i==j)
        return dp[i][j] = 1;
    else if(a[i]==a[j] && i+1==j)
        return dp[i][j] = 2;
    else if(a[i]==a[j])
        return dp[i][j] = lps(i+1,j-1)+2;
    return dp[i][j] = max(lps(i,j-1),lps(i+1,j));
}
int main()
{
    ll i,j,n,m;
    cin>>a;
    n = a.size();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            dp[i][j] = -1;
    }
    cout<<lps(0,n-1)<<endl;

    return 0;
}


