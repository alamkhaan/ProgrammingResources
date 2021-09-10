#include <bits/stdc++.h>
using namespace std;
const int MAXS = 251000;
const int MAXC = 26;
vector<int> out[MAXS];
int nex[MAXS];
int f[MAXS];
int g[MAXS][MAXC];
string arr[600];
int ans[600];
int states;
void buildAhoCorasik(int k)
{
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);
    states = 1;

    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int currentState = 0;

        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';

            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
            currentState = g[currentState][ch];
        }
        out[currentState].push_back(i);
    }

    for (int ch = 0; ch < MAXC; ++ch)
    {
        if (g[0][ch] == -1)
            g[0][ch] = 0;
        nex[g[0][ch]] = -1;
    }
    memset(f, -1, sizeof f);
    queue<int> q;
    for (int ch = 0; ch < MAXC; ++ch)
    {
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (q.size())
    {
        int state = q.front();
        q.pop();

        for (int ch = 0; ch < MAXC; ++ch)
        {
            if (g[state][ch] != -1)
            {
                int failure = f[state];
                while (g[failure][ch] == -1)
                    failure = f[failure];

                failure = g[failure][ch];
                f[g[state][ch]] = failure;

                if(out[failure].size()>0)
                    nex[g[state][ch]] = failure;
                else nex[g[state][ch]] = nex[failure];

                q.push(g[state][ch]);
            }
        }
    }
}

int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';

    while (g[answer][ch] == -1)
        answer = f[answer];

    return g[answer][ch];
}


void searchWords(int k,string text)
{

   buildAhoCorasik(k);

    int currentState = 0;
    int temp;

    for (int i = 0; i < text.size(); ++i)
    {
        currentState = findNextState(currentState, text[i]);

        temp = currentState;
        if(out[temp].size()>0)
        {
            for(int j=0;j<out[temp].size();j++)
            {
                cout<<arr[out[temp][j]]<<" appears from "<<i-arr[out[temp][j]].size()+2<<" to "<<i+1<<endl;  // 1 based indexing
                //ans[out[temp][j]]++;
            }
        }
        temp = nex[temp];
        while(temp!=-1)
        {
            for(int j=0;j<out[temp].size();j++)
            {
                cout<<arr[out[temp][j]]<<" appears from "<<i-arr[out[temp][j]].size()+2<<" to "<<i+1<<endl; // 1 based indexing
                //ans[out[temp][j]]++;
            }
            temp = nex[temp];
        }
    }
}
int main()
{
    arr[0] = "aba";
    arr[1] = "ba";
    arr[2] = "ac";
    arr[3] = "a";
    arr[4] = "abc";
    string text = "ababacbabc";
    int k =  5;


    searchWords( k, text);

    return 0;
}
