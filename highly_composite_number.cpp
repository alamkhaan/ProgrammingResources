#include<bits/stdc++.h>
using namespace std;


int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23 };

int resNum, resDiv, n;
void recur ( int pos, int limit, long long num, int div )
{
    if ( div > resDiv )   // Get the number with highest NOD
    {
        resNum = num;
        resDiv = div;
    }
    else if ( div == resDiv && num < resNum )   //In case of tie, take smaller number
    {
        resNum = num;
    }

    if ( pos == 9 )
        return; //End of prime list

    long long p = prime[pos];

    for ( int i = 1; i <= limit; i++ )
    {
        if ( num * p > n )
            break;
        recur ( pos + 1, i, num * p, div * ( i + 1 ) );
        p *= prime[pos];
    }
}
int main () {
    n = 1000000000;
    resNum = 0;
    resDiv = 0;
    recur ( 0, 30, 1, 1 );
    printf ( "%d %d\n", resNum, resDiv );
}
