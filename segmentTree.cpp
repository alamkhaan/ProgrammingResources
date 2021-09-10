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

void update(ll att,ll L,ll R,ll pos,ll val) //single update
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

void update(ll att,ll L,ll R,ll l,ll r,ll val) //range update
{
    if(l>R || r<L)
        return;
    if(l<=L && r>=R)
    {
         a[att]+= val;
         return;
    }
    ll mid = (L+R)/2;
    update(att*2,L,mid,l,r,val);
    update(att*2+1,mid+1,R,l,r,val);

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

    return max(x,y);
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


ll query3(ll att,ll L,ll R,ll l,ll r,ll val) //first 0-based index from l to r(1 based) where that index value is less than variable val.If not found -1.
{
    if(l>R || r<L)
        return -1;
    if(l<=L && r>=R)
    {
        if(L==R)
        {
            if(a[att]<val)
            {
                return L-1;
            }
            else return -1;
        }
        ll mid = (L+R)/2;
        if(a[att]>=val)
            return -1;
        if(a[att*2]<val)
        {
            return query3(att*2,L,mid,l,r,val);
        }
        else if(a[att*2+1]<val)
        {
            return query3(att*2+1,mid+1,R,l,r,val);
        }
        else return -1;



    }
    ll mid = (L+R)/2;
    ll x = query3(att*2,L,mid,l,r,val);
    if(x!=-1)
        return x;
    ll y = query3(att*2+1,mid+1,R,l,r,val);

    return y;
}




ll query2(ll att,ll L,ll R,ll l,ll r,ll val)   //last 0-based index from l to r(1 based) where that index value is equal to variable val.If not found -1.
{
    if(l>R || r<L)
        return -1;
    if(l<=L && r>=R)
    {
        if(L==R)
        {
            if(a[att]==val)
            {
                return L-1;
            }
            else return -1;
        }
        ll mid = (L+R)/2;
        if(a[att*2+1]==val)
        {
            return query2(att*2+1,mid+1,R,l,r,val);
        }
        else if(a[att*2]==val)
        {
            return query2(att*2,L,mid,l,r,val);
        }

        else return -1;
    }
    ll mid = (L+R)/2;
    ll x = query2(att*2+1,mid+1,R,l,r,val);
    if(x!=-1)
        return x;
    ll y = query2(att*2,L,mid,l,r,val);

    return y;
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
