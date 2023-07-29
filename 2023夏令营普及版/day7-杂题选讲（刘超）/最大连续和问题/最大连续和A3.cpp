#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
int a[N];
int ans = a[1];

void solve(int L, int R)
{
	if (L == R)
	{
		ans = max(ans, a[L]);
		return;
	}
	
	int mid = (L + R) >> 1;
	solve(L,mid); solve(mid + 1, R);
	
	int lsum = a[mid], lmax = a[mid];
	for (int i = mid - 1; i >= L; i--)
	{
		lsum += a[i];
		if (lsum > lmax) lmax = lsum;
	}
	int rsum = a[mid + 1], rmax = a[mid + 1];
	for (int i = mid + 2; i <= R; i++)
	{
		rsum += a[i];
		if (rsum > rmax) rmax = rsum;
	}
	ans = max(ans, lmax + rmax);
} 

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	solve(1,n);
	
	cout << ans << endl;
	
	return 0;
}
