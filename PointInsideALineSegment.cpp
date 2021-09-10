/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define pb     push_back
#define inf     2e18
#define low     -2e18
#define PI        acos(-1.0)
#define endl  "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)
const int sz = 3e5+9;
ll a[sz],b[sz];
string str,str2;
struct Point {

	ll x,y;
	Point()
	{
	    ;
	}
	Point(ll _x,ll _y)
	{
	    x = _x;
	    y = _y;
	}
};

ll cross_product(Point O, Point A, Point B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
ll dot_prouct(Point A,Point B)
{
    return A.x*B.x + A.y*B.y;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0,m;
    FAST
    cin>>x>>y>>n>>m;
    ll p,q;
    cin>>t;
    while(t--)
    {
        cin>>p>>q;
        ll ab = dot_prouct(Point(n-x,m-y),Point(n-x,m-y));
        ll ac  = dot_prouct(Point(n-x,m-y),Point(p-x,q-y));
        if(cross_product(Point(p,q),Point(x,y),Point(n,m))==0 && ac>=0 && ac<=ab) // ac==0 or ac==ab means same point
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}

