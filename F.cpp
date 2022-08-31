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
ll flag[1000];
struct dat
{
    ll val,sc;
    dat()
    {
        ;
    }
    dat(ll x,ll y)
    {
        val  =x;
        sc = y;
    }
};

bool cmp(dat a,dat b)
{
    if(a.val==b.val)
    {
        return a.sc>b.sc;
    }
    return a.val<b.val;
}

bool cmp2(dat a,dat b)
{
    if(a.val-a.sc==b.val-b.sc)
    {
        return a.sc>b.sc;
    }
    return (a.val-a.sc)>(b.val-b.sc);
}

int main()
{
    ll i,n,t,k,j,x=0,y=0,m,r;
    FAST
    cin>>n>>r;
    vector<dat> v1,v2;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        if(y>=0)
        {
            v1.pb(dat(x,y));
        }
        else v2.pb(dat(x,-y));
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp2);


    for(i=0;i<v1.size();i++)
    {
        if(r<v1[i].val)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        r+= v1[i].sc;
    }
    memset(flag,0,sizeof flag);
    for(i=0;i<v2.size();i++)
    {
        //cout<<v2[i].val<<" "<<v2[i].sc<<endl;
    }
    for(i=0;i<v2.size();i++)
    {
        if(v2[i].val<=r )
        {
            r-= v2[i].sc;
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }


    }
    if(r<0)
        cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}

