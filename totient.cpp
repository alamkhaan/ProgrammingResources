typedef long long ll;
ll phi[100006], prime[100006];

void sievephi(ll n)
{
    ll i,j;

    for(i=1; i<=n; i++) phi[i]=i;

    phi[1]=1;
    prime[1]=1;

    for(i=2; i<=n; i++)
    {
        if(!prime[i])
        {
            for(j=i;j<=n; j+=i)
            {
                prime[j+i]=1;
                phi[j]=(phi[j]/i)*(i-1);

            }
        }
    }
}
