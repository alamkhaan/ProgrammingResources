const ll N = 1e7+7;
ll num[N];
ll mobius[N];
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
void Mobius()
{
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
            mobius[i] = 1;
        else
        {

            if (num[i / num[i]] == num[i])
                mobius[i] = 0;
            else
                mobius[i] = -1 * mobius[i / num[i]];
        }
    }
}
