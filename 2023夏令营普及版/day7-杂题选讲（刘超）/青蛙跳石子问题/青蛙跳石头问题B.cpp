#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 10;
int n;
int a[N];
int dp[N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	memset(dp,false,sizeof(dp));
	
	bool ok = false;
	dp[1][0] = true; //起点 
	
	for (int i = 2; i <= n; i++)
		for (int j = i - 1; j >= 1 && !ok; j--)
		{
			int k = a[i] - a[j];
			if (k > j) break; //优化 k > (j - 1) + 1
			dp[i][k] = dp[j][k + 1] | dp[j][k] | dp[j][k - 1];
			if (i == n && dp[i][k]) {ok = true; break;}
		}
	
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
		
	return 0;
}
