#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cost[100009];
ll vis[100009];
ll stBase[100009],enBase[100009];
ll segArray[100009];
ll a[500009],q[500009],lazy1[500009],lazy2[500009];
ll ptr;
void build(ll att,ll L,ll R)
{
    if(L==R)
    {
        a[att] = cost[segArray[L]];
        lazy1[att] = 0;
        return;
    }

    ll mid = (L+R)/2;
    build(att*2,L,mid);
    build(att*2+1,mid+1,R);

    a[att] = a[att*2]+a[att*2+1];
    lazy1[att]  =0;
}

void build2(ll att,ll L,ll R)
{
    if(L==R)
    {
        q[att] = cost[segArray[L]];
        lazy2[att] = 0;
        return;
    }

    ll mid = (L+R)/2;
    build2(att*2,L,mid);
    build2(att*2+1,mid+1,R);

    q[att] = min(q[att*2],q[att*2+1]);
    lazy2[att] = 0;
}

void update(ll att,ll L,ll R,ll l,ll r,ll val)
{
    if(l>R || r<L)
        return;
    if(l<=L && r>=R)
    {
        a[att]+= (R-L+1)*val;
        lazy1[att] += val;
        return;
    }

    ll mid = (L+R)/2;
    update(att*2,L,mid,l,r,val);
    update(att*2+1,mid+1,R,l,r,val);
    a[att] = a[att*2]+a[att*2+1]+(R-L+1)*lazy1[att];
}
void update2(ll att,ll L,ll R,ll l,ll r,ll val)
{
    if(l>R || r<L)
        return;
    if(l<=L && r>=R)
    {
        lazy2[att] += val;
        return;
    }

    ll mid = (L+R)/2;
    update2(att*2,L,mid,l,r,val);
    update2(att*2+1,mid+1,R,l,r,val);
    q[att] = min(q[att*2]+lazy2[att*2],q[att*2+1]+lazy2[att*2+1]);
}
ll query(ll att,ll L,ll R,ll l,ll r,ll carry)
{
    if(l>R || r<L)
        return 0;
    if(l<=L && r>=R)
        return a[att]+carry*(R-L+1);
    ll mid = (L+R)/2;
    ll x = query(att*2,L,mid,l,r,carry+lazy1[att]);
    ll y = query(att*2+1,mid+1,R,l,r,carry+lazy1[att]);

    return x+y;
}

ll query2(ll att,ll L,ll R,ll l,ll r,ll carry)
{
    if(l>R || r<L)
        return 1e15;
    if(l<=L && r>=R)
        return q[att]+carry+lazy2[att];
    ll mid = (L+R)/2;
    ll x = query2(att*2,L,mid,l,r,carry+lazy2[att]);
    ll y = query2(att*2+1,mid+1,R,l,r,carry+lazy2[att]);

    return min(x,y);
}
int main()
{

}
