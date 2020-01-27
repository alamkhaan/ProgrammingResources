#include<bits/stdc++.h>
using namespace std;
int zArr[100009];
void z_function(string const &s,int* z)
{
    int n = (int) s.length();
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

}
int main()
{

    string str;
    cin>>str;
    z_function(str,zArr);
    for(int i=0; i<str.size(); i++)
        cout<<i<<" "<<zArr[i]<<endl;
}
