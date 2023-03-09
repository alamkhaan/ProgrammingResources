#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct Point {
	ll x,y;
	Point(){;}
	Point(ll _x,ll _y){
	    x = _x;y = _y;}
};
bool cmp(Point p,Point q)
{
    if(p.x==q.x)
        return p.y<q.y;
    return p.x<q.x;
}
vector<Point> points;
// Cross product of two vectors OA and OB
// returns positive for counter clockwise
// turn and negative for clockwise turn
ll cross_product(Point O, Point A, Point B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
ll area(vector<Point> &points)
{
    ll n,x =  0,y=  0,i;
    n  =points.size();
    for(i=0;i<n;i++)
    {
        x+= points[i].x * points[(i+1)%n].y;
        y+= points[i].y * points[(i+1)%n].x;
    }
    return abs(x-y); //divide by 2 needed.
    return (double)abs(x-y)/2.0;
}
// Returns a list of points on the convex hull
// in counter-clockwise order
vector<Point> convex_hull()
{
	int n = points.size(), k = 0;
	if (n <= 3)
		return points;
	vector<Point> ans(2 * n);
	// Sort points lexicographically
	sort(points.begin(), points.end(),cmp);
	// Build lower hull
	for (int i = 0; i < n; ++i)
    	{
		// If the point at K-1 position is not a part
		// of hull as vector from ans[k-2] to ans[k-1]
		// and ans[k-2] to A[i] has a clockwise turn
		while (k >= 2 && cross_product(ans[k - 2],ans[k - 1], points[i]) <= 0)
        {
            cout<<ans[k-2].x<<" "<<ans[k-2].y<<" "<<ans[k-1].x<<" "<<ans[k-1].y<<" "<<points[i].x<<" "<<points[i].y<<endl;
			k--;
        }
		ans[k++] = points[i];
	}
	// Build upper hull
	for (size_t i = n - 1, t = k + 1; i > 0; --i)
    	{
		// If the point at K-1 position is not a part
		// of hull as vector from ans[k-2] to ans[k-1]
		// and ans[k-2] to A[i] has a clockwise turn
		while (k >= t && cross_product(ans[k - 2],ans[k - 1], points[i - 1]) <= 0)
        {
            cout<<ans[k-2].x<<" "<<ans[k-2].y<<" "<<ans[k-1].x<<" "<<ans[k-1].y<<" "<<points[i].x<<" "<<points[i].y<<endl;
			k--;
		}
		ans[k++] = points[i - 1];
	}
	// Resize the array to desired size
	ans.resize(k - 1);
	return ans;
}
int main()
{
    ll i;
	points.push_back(Point(0,3));
	points.push_back(Point(2,2));
	points.push_back(Point(1,1));
	points.push_back(Point(2,1));
	points.push_back(Point(3,0));
	points.push_back(Point(0,0));
	points.push_back(Point(3,3));
	vector<Point> ans = convex_hull();
	for (ll i=0;i<ans.size();i++)
    {
		cout <<"("<<ans[i].x<<", "<<ans[i].y<<")"<<endl;
    }

	return 0;
}

