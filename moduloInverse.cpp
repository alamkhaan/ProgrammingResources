#include<bits/stdc++.h>
using namespace std;
long long egcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0)
    {
        x = 0;
        y = 1;
        return b;
    }
    long long x1,y1;
    long long d = egcd(b%a,a,x1,y1);

    x = y1 - (b/a)*x1;
    y = x1;

    return d;
}

long long bigmod(long long a,long long b, long long c)
{
    if(b==0)
        return 1;

    if(b%2==0)
    {
        long long x=bigmod(a,b/2,c);
        return ((x%c)*(x%c))%c;
    }
    else return (a%c * bigmod(a,b-1,c))%c;
}

long long inv[100000];
void moduloInverseRange(long long m)
{
    inv[1] = 1;
    for(long long i = 2; i < m; ++i)
    inv[i] = (m - (m/i) * inv[m%i] % m) % m;
}
int main()
{
    long long a=2,m=1e9+7,x,y,p;
    p  = egcd(a,m,x,y);
    cout<<(x+m)%m<<endl; // when m and a are co-prime(egcd)
    cout<<bigmod(a,m-2,m); //when m is prime(fermat little theorm)
}
