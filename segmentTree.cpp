#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[400009],num[100009];
void build(ll att,ll L,ll R)
{
    if(L==R)
    {
        a[att] = num[L];
        return;
    }

    ll mid = (L+R)/2;
    build(att*2,L,mid);
    build(att*2+1,mid+1,R);

    a[att] = a[att*2]+a[att*2+1];
}

void update(ll att,ll L,ll R,ll pos,ll val)
{
    if(L==R)
    {
        a[att]+= val;
        return;
    }
    ll mid = (L+R)/2;
    if(pos<=mid)
        update(att*2,L,mid,pos,val);
    else update(att*2+1,mid+1,R,pos,val);
    a[att] = a[att*2]+a[att*2+1];
}

ll query(ll att,ll L,ll R,ll l,ll r)
{
    if(l>R || r<L)
        return 0;
    if(l<=L && r>=R)
        return a[att];
    ll mid = (L+R)/2;
    ll x = query(att*2,L,mid,l,r);
    ll y = query(att*2+1,mid+1,R,l,r);

    return x+y;
}


int main()
{
    ll i,j,k,n,l,r;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>num[i];
    build(1,1,n);
    for(i=0;i<k;i++)
    {
        cin>>l>>r;
        cout<<query(1,1,n,l,r)<<endl;
    }
}
