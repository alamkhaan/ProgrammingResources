#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int N =100000000;
int status[100000000/32];

bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

int main()
{
    int i, j, sqrtN;
    for( i = 3; i*i<=N; i += 2 )
    {
        if( check(status[i>>5],i&31)==0)
        {
            for( j = i*i; j <= N; j += 2*i )
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
    prime.push_back(2);
    for(i=3;i<=N;i+=2)
    {
        if( check(status[i>>5],i&31)==0)
        {
            prime.push_back(i);
        }
    }
    return 0;
}
