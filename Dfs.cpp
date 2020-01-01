#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int n,Time=0;
vector<int> adj[1000];
struct vertex
{
    int color;
    int par;
    int d;
    int f;
};
vertex node[1000];

void dfs_visit(int u)
{
    node[u].color = 1;
    Time++;
    node[u].d = Time;
    for(int i=0;i<adj[u].size();i++)
    {
        if(node[adj[u][i]].color==0)
        {
            node[adj[u][i]].color = 1;
            node[adj[u][i]].par = u;
            dfs_visit(adj[u][i]);
        }
    }
    Time++;
    node[u].f = Time;
    node[u].color = 2;

}

void dfs()
{
    for(int i=1;i<=n;i++)
    {
        node[i].color = 0;
        node[i].par = -1;
    }
    Time = 0;
    for(int i=1;i<=n;i++)
    {
        if(node[i].color==0)
        {
            dfs_visit(i);
        }
    }
}
int main()
{
    int m,i,j,x,y;
    cout<<"Enter node numbers : ";
    cin>>n;
    cout<<"Enter edge numbers : ";
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Enter node number : ";
    dfs();
    cin>>x;
    cout<<"For node "<<x<<" - starting time is "<<node[x].d<<",finishing time is "<<node[x].f<<endl;
    return 0;
}
