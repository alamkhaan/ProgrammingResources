#include<bits/stdc++.h>
using namespace std;

vector<int> lcp;
vector<int> sort_cyclic_shifts(string const& s)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        pair<int, int> cur,prev;
        for (int i = 1; i < n; i++)
        {
            cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}



/*int lcp(int i, int j)
{
    int ans = 0;
    for (int k = log_n; k >= 0; k--) {
        if (c[k][i] == c[k][j]) {
            ans += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ans;
}*/

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> Rank(n, 0);
    for (int i = 0; i < n; i++)
        Rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (Rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[Rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[Rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
int a[4000009];
void build(int att,int L,int R)
{
    if(L==R)
    {
        a[att] = lcp[L-1];
        return;
    }

    int mid = (L+R)/2;
    build(att*2,L,mid);
    build(att*2+1,mid+1,R);

    a[att] = min(a[att*2],a[att*2+1]);
}

int query(int att,int L,int R,int l,int r)
{
    if(l>R || r<L)
        return INT_MAX;
    if(l<=L && r>=R)
        return a[att];
    int mid = (L+R)/2;
    int x = query(att*2,L,mid,l,r);
    int y = query(att*2+1,mid+1,R,l,r);

    return min(x,y);
}
int main()
{
    string str;
    cin>>str;
    vector<int> suffix =  sort_cyclic_shifts(str);
    lcp = lcp_construction(str,suffix);
    for(int i=0;i<suffix.size();i++)
        cout<<"i = "<<suffix[i]<<endl;

    return 0;
}

