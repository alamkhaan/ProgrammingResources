#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
ll dp[1000][1000];

pair<ll,ll> lpstr(string a)
{
    ll i,j,n,l;
    n = a.size();
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            dp[i][j] = 0;
    }
    for(i=0;i<n;i++)
        dp[i][i] = 1;
    ll start=0,maxSize=1;

    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            dp[i][i+1] = 1;
            start = i;
            maxSize = 2;
        }
    }

    for(l=3;l<=n;l++)
    {
        for(i=0;i<n-l+1;i++)
        {
            j = i+l-1;
            if(a[i]==a[j] && dp[i+1][j-1])
            {
                dp[i][j] = 1;
                if(l>maxSize)
                {
                    maxSize = l;
                    start = i;
                }
            }
        }
    }
    return make_pair(start,start+maxSize);
}

int main()
{
    ll i,j,n,m,l;
    cin>>a;
    pair<ll,ll> p = lpstr(a);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}


