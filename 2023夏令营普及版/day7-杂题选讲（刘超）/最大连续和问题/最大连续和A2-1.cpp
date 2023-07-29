#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
int a[N];
int dp[N]; //dp[i]表示以第 i 个数为结尾的最大连续和

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = a[1];
	for (int i = 1; i <= n; i++)
	{
		//dp[i] = max(dp[i - 1] + a[i], a[i]);
		dp[i] = max(dp[i - 1], 0) + a[i];
		if (dp[i] > ans) ans = dp[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
