#include<bits/stdc++.h>
using namespace std;
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;

    Vertex()
    {
        for(int i=0;i<K;i++)
            next[i] = -1;
    }
};

vector<Vertex> tri;

void init()
{
    tri.clear();
    tri.resize(1);
}

void add_string(string const& s)
{
    int v = 0,c;
    for (int i=0;i<s.size();i++)
    {
        c = s[i] - 'a';
        if (tri[v].next[c] == -1)
        {
            tri[v].next[c] = tri.size();
            tri.emplace_back();
        }
        v = tri[v].next[c];

    }
    tri[v].leaf = true;
}

bool found(string const &s)
{
    int v = 0,c;
    for(int i=0;i<s.size();i++)
    {
        c = s[i] - 'a';
        if(tri[v].next[c]==-1)
            return false;
        v = tri[v].next[c];
    }
    return tri[v].leaf; //if full string.......but if prefix then it should be return true;
}
int main()
{
    string str;
    int i,n,m;
    init();
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>str;
        add_string(str);
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>str;
        if(found(str))
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

