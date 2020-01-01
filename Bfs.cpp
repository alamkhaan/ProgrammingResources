#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int n;
vector<int> v[1000];
int vis[1000],dis[1000];
void bfs(int u)
{
    vis[u] = 1;
    dis[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0;i<v[temp].size();i++)
        {
            if(vis[v[temp][i]]==0)
            {
                vis[v[temp][i]] = 1;
                q.push(v[temp][i]);
                dis[v[temp][i]] = dis[temp]+1;
            }
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
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<"Enter starting node: ";
    cin>>x;
    bfs(x);
    for(i=1;i<=n;i++)
    {
        cout<<"Distance from "<<x<<" to "<<i<<" is "<<dis[i]<<endl;
    }
}
