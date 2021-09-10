const ll N = 1e7+7;
ll num[N];
void seive()
{
    for(ll i=1;i<N;i++)
    {
        num[i]  = i;
    }
    for(ll i = 4;i<N;i+=2)
        num[i]  =2;
    for(ll i=3;i*i<N;i+=2)
    {
        if(num[i]==i)
        {
            for(ll j=2*i;j<N;j+= i)
            {
                if(num[j]==j)
                    num[j]  = i;
            }
        }
    }
}

ll fact(ll n)
{
    ll ans = 1;
    while(n!=1)
    {
        ll x = num[n];
        ll cnt =0;
        while(n%x==0)
        {
            cnt++;
            n  =n/x;
        }
        cout<<x<<" "<<cnt<<endl;   // x prime number occurs cnt times
    }
    return ans;
}
