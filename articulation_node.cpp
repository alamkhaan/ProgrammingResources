#include <bits//stdc++.h>
using namespace std;


#define MAXN 50009
vector<int> G[MAXN];
bool vis[MAXN];
int timer, dis[MAXN], low[MAXN];
bool flag[MAXN];
int val[MAXN];
vector<int> data;
vector<int>arti;
void dfs (int u, int p = -1)
{
    vis[u] = true;
    dis[u] = low[u] = timer++;
    int children = 0,i;
    for(i=0;i<G[u].size();++i)
    {
        int v = G[u][i];
        if(v==p)
            continue;
        if(vis[v])
            low[u] = min(low[u],dis[v]);
        else
        {
            dfs (v, u);
            low[u] = min (low[u], low[v]);
            if (low[v]>=dis[u] && p!=-1)
                arti.push_back(u);
            children++;
        }
    }
    if(p==-1 && children>1)
        arti.push_back(u);
}


int main() {
    int n, m,k;

    cin>>n>>m;
    for(int p=0; p<m; p++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    timer = 0;
    for (int i=0; i<n; ++i)
        vis[i] = false;
    dfs (1);
    cout<<arti.size()<<endl;
    for(int i=0; i<arti.size(); i++)
    {
        cout<<arti[i]<<endl;

    }

}
