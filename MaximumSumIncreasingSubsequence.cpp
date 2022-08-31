#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,arr[100009];
ll getSum(ll BITree[], ll index)
{
	ll sum = 0;
	while (index > 0) {
		sum = max(sum, BITree[index]);
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(ll BITree[], ll newIndex,ll index, ll val)
{
	while (index <= newIndex)
    {
		BITree[index] = max(val, BITree[index]);
		index += index & (-index);
	}
}

ll MSIS()
{
	ll newindex = 0, max_sum;
	map<ll, ll> uniqueArr;
	for (ll i = 0; i < n; i++)
    {
		uniqueArr[arr[i]] = 0;
	}
	for (map<ll, ll>::iterator it = uniqueArr.begin();it != uniqueArr.end(); it++)
	{
		newindex++;
		uniqueArr[it->first] = newindex;
	}
	ll* BITree = new ll[newindex + 1];

	for (ll i = 0; i <= newindex; i++)
    {
		BITree[i] = 0;
	}

	for (ll i = 0; i < n; i++)
    {
		max_sum = getSum(BITree, uniqueArr[arr[i]] - 1);
		updateBIT(BITree, newindex,uniqueArr[arr[i]], max_sum + arr[i]);
	}

	return getSum(BITree, newindex);
}

int main()
{
	ll i;
	cin>>n;
	for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	cout<<MSIS()<<endl;

	return 0;
}
