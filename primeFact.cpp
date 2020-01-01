vector<long long> v;
void fact(ll n)
{
    long long m = n;
    if(m%2==0)
    {
        v.pb(2);
    }
    while(m%2==0)
    {
        m = m/2;
    }
    for(ll i=3;i<=sqrt(m+1);i+=2)
    {
        if(m%i==0)
        {
            v.pb(i);
        }
        while(m%i==0)
        {
            m = m/i;
        }
    }
    if(m>1)
        v.pb(m);
}
