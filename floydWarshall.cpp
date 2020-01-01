#include<bits/stdc++.h>
using namespace std;
#define inf 100000000000000
#define N 10009
typedef long long ll;
ll cost[N][N],n,m,par[N][N];


void floyedWarshall()
{
    ll i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]>cost[i][k]+cost[k][j])
                {
                    cost[i][j] = cost[i][k]+cost[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }

}

void Path(ll x,ll y)
{
    if(x==y)
    {
        cout<<x<<" ";
        return;
    }
    Path(x,par[x][y]);
    cout<<y<<" ";

}


int main()
{
    ll i,j,k,x,y,q;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                cost[i][j] = 0;
            }
            else cost[i][j] = inf;
        }
    }
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>k;
        cost[x][y] = cost[y][x] = k;
        par[x][y] = x;
        par[y][x] = y;
    }
    floyedWarshall();
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(cost[x][y]==inf)
        {
            cout<<"No Path"<<endl;
        }
        else
        {
            cout<<cost[x][y]<<endl;
            Path(x,y);
            cout<<endl;
        }
    }
}
