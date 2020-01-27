#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105000;

struct node
{
    int next[26];
    int len;
    int sufflink;
    int num;

};

int len;
string s;
vector<node> tree;
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome
long long ans;

bool addLetter(int pos)
{
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true)
    {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].sufflink;
    }
    if (tree[cur].next[let])
    {
        //cout<<"Duplicate"<<endl;
        suff = tree[cur].next[let];
        return false;
    }

    num++;
    tree.emplace_back();
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;

    if (tree[num].len == 1)
    {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    while (true)
    {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
        {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }
    }

    tree[num].num = 1 + tree[tree[num].sufflink].num;

    return true;
}
int cnt = -2;
void dfs(int node) //distinct palindrome
{
    cnt++;
    for(int i=0;i<26;i++)
    {
        if(tree[node].next[i]!=0)
        {
            //cout<<"par = "<<node<<", child = "<<tree[node].next[i]<<endl;
            dfs(tree[node].next[i]);
        }
    }
}

void initTree()
{
    tree.emplace_back();
    tree.emplace_back();
    tree.emplace_back();
    num = 2;
    suff = 2;
    tree[1].len = -1;
    tree[1].sufflink = 1;
    tree[2].len = 0;
    tree[2].sufflink = 1;
}

int main()
{
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));

    cin>>len;
    cin>>s;

    initTree();

    for (int i = 0; i < len; i++)
    {
        addLetter(i);
        ans += tree[suff].num; // all possible palindrome(duplicate)
    }
    dfs(1);
    dfs(2);

    cout << ans <<" "<<cnt<< endl;

    return 0;
}
/*

testcase::
abbabba
aabcaa
abcda
abababa
aaaa
*/
