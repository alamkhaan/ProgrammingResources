#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll dp[1000][1000];

ll lps(string a)
{
    ll i,j,n = a.size(),l;
    for(i=0;i<n;i++)
        dp[i][i] = 1;
    for(l=2;l<=n;l++)
    {
        for(i=0;i<n-l+1;i++)
        {
            j = i+l-1;
            if(a[i]==a[j] && l==2)
                dp[i][j] = 2;
            else if(a[i]==a[j])
            {
                dp[i][j] = dp[i+1][j-1]+2;
            }
            else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];

}

int main()
{
    ll i,j,n,m,l;
    cin>>a;
    cout<<lps(a)<<endl;
    return 0;
}


