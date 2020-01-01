#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1009
#define inf 100000000000000
ll n,cost[N][N],temp[N][N];
bool flag[N];
vector <ll> solve;
ll sol(ll j,ll prev)
{
    ll i,ans=0,m,s=j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            temp[i][j] = cost[i][j];
    }
    for(i=1;i<=n;i++)
        temp[prev][i] = inf;
    for(i=1;i<=n;i++)
        temp[i][s] = inf;
    temp[s][prev] = inf;

    for(i=1;i<=n;i++)
    {
        m = inf;
        for(j=1;j<=n;j++)
        {
            m = min(m,temp[i][j]);
        }
        if(m==inf)
            ans += 0;
        else
        {
            ans+= m;
            for(j=1;j<=n;j++)
            {
                if(temp[i][j]!=inf)
                {
                    temp[i][j] -= m;
                }
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        m = inf;
        for(j=1;j<=n;j++)
        {
            m = min(m,temp[j][i]);
        }
        if(m==inf)
            ans += 0;
        else
        {
            ans+= m;
            for(j=1;j<=n;j++)
            {
                if(temp[j][i]!=inf)
                {
                    temp[j][i] -= m;
                }
            }
        }
    }
    return ans;
}
void dup(ll j,ll prev)
{
    ll ans = 0,m,i;
    for(i=1;i<=n;i++)
        cost[prev][i] = inf;
    for(i=1;i<=n;i++)
        cost[i][j] = inf;
    cost[j][prev] = inf;

    for(i=1;i<=n;i++)
    {
        m = inf;
        for(j=1;j<=n;j++)
        {
            m = min(m,cost[i][j]);
        }
        if(m==inf)
            ans += 0;
        else
        {
            ans+= m;
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]!=inf)
                {
                    cost[i][j] -= m;
                }
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        m = inf;
        for(j=1;j<=n;j++)
        {
            m = min(m,cost[j][i]);
        }
        if(m==inf)
            ans += 0;
        else
        {
            ans+= m;
            for(j=1;j<=n;j++)
            {
                if(cost[j][i]!=inf)
                {
                    cost[j][i] -= m;
                }
            }
        }
    }

}
int main()
{
    ll i,j,m,ans=0,prev;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>cost[i][j];
            if(i==j)
                cost[i][j] = inf;
        }
    }
    for(i=1;i<=n;i++)
    {
        m = inf;
        for(j=1;j<=n;j++)
        {
            m = min(m,cost[i][j]);
        }
        ans += m;
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]!=inf)
            {
                cost[i][j] -= m;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        m = inf;
        for(j=1;j<=n;j++)
        {
            m = min(m,cost[j][i]);
        }
        ans += m;
        for(j=1;j<=n;j++)
        {
            if(cost[j][i]!=inf)
            {
                cost[j][i] -= m;
            }
        }
    }
    solve.push_back(1);
    flag[1]= 1;
    prev = 1;
    for(i=2;i<=n;i++)
    {
        m = inf;
        ll ind = -1;
        for(j=2;j<=n;j++)
        {
            if(!flag[j])
            {
                ll p = sol(j,prev);

                if(m>ans+cost[prev][j]+p)
                {
                    m = ans+cost[prev][j]+p;
                    ind = j;
                }
            }
        }
        ans = m;
        flag[ind] = 1;
        dup(ind,prev);
        solve.push_back(ind);
        prev = ind;
    }
    solve.push_back(1);
    cout<<ans<<endl;
    for(i=0;i<solve.size();i++)
        cout<<solve[i]<<" ";

}
