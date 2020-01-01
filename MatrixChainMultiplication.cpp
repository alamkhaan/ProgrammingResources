#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define inf 1000000000000000
typedef long long ll;
ll p[N];
ll s[N][N],m[N][N];

void Print_Optimal_Parens(ll i,ll j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        Print_Optimal_Parens(i,s[i][j]);
        Print_Optimal_Parens(s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{

    ll n,t,i,j,k,x=0,y,l,q;
    cin>>n;
    for(i=0;i<=n;i++)
        cin>>p[i];
    for(i=1;i<=n;i++)
        m[i][i] = 0;
    for(l= 2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j = i+l-1;
            m[i][j] = inf;
            for(k=i;k<j;k++)
            {
                q = m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<m[1][n]<<endl;
    Print_Optimal_Parens(1,n);

    return 0;
}

