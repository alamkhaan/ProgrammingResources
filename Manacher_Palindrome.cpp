#include<bits/stdc++.h>
using namespace std;
int d1[100009],d2[100009];
void even_length(string const &s,int n)
{
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k ;
        }
    }
}
void odd_length(string const &s,int n)
{

    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
}
int main()
{
    string str;
    int i,n;
    cin>>str;
    n = str.size();
    odd_length(str,n);
    even_length(str,n);
    for(i=0;i<n;i++)
    {
        cout<<i<<" = "<<d1[i]<<endl;
    }
    for(i=0;i<n;i++)
    {
        cout<<i<<" = "<<d2[i]<<endl;
    }

}
