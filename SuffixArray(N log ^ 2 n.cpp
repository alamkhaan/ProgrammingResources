#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 65536
#define MAXLG 17
string A;
struct entry
{
    ll nr[2], p;

} L[MAXN];

ll P[MAXLG][MAXN], N, i, stp, cnt;

ll cmp(struct entry a, struct entry b)
{
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

ll lcp(ll x, ll y)
{
    ll k,ret=0;
    if(x==y)
        return N-x;
    for(k=stp-1;k>=0 && x<N && y<N;k--)
    {
        if(P[k][x]==P[k][y])
        {
            x+= 1<<k;
            y+= 1<<k;
            ret+= 1<<k;
        }
    }
    return ret;
}

void buildSuffixArray()
{
    for(N = A.size(), i = 0; i < N; i ++)
        P[0][i] = A[i] - 'a';

    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
    {
        for (i = 0; i < N; i ++)
        {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }

        sort(L, L + N, cmp);

        for (i = 0; i < N; i ++)
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
    }
}

int main(void)
{
    cin>>A;
    buildSuffixArray();

    for(i=0;i<N;i++)
    {
        cout<<i<<" "<<P[stp-1][i]<<endl;
    }
    return 0;
}
