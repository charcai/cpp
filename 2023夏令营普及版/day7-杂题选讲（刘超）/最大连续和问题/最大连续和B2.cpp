#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 300000 + 10;

int n, m;
int a[N], s[N];

int ans;

void solve(int L, int R)
{
	if (L == R)
	{
		ans = max(ans, a[L]);
		return;
	}
	
	int mid = (L + R) >> 1;
	solve(L,mid); solve(mid + 1, R);
	
	int j = mid;
	int minv = INF;
	//这里必须从大到小枚举 i 才能保证 minv 的正确 
	for (int i = R; i >= mid + 1; i--)   //枚举区间右端点
	{
		while (j >= L && i - j + 1 <= m) //枚举区间左端点
		{
			minv = min(minv, s[j - 1]);
			j--;
		}
		ans = max(ans, s[i] - minv);
	}
} 

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	
	ans = a[1];
	
	solve(1,n);
	
	cout << ans << endl;
	
	return 0;
}
