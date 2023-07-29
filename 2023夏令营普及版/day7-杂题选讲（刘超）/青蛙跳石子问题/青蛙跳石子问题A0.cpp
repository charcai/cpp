#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 10000 + 10;
int L, S, T, M;
int a[N];
bool flag[N]; //flag[i] 表示位置 i 处是否有石子 
int dp[N];

int main()
{
	cin >> L >> S >> T >> M;
	for (int i = 1; i <= M; i++) 
	{
		cin >> a[i];
		flag[a[i]] = 1; //flag[i] 表示位置 i 处是否有石子 
	}

	memset(dp,INF,sizeof(dp));
	dp[0] = 0;
	
	for (int i = 1; i < L + T; i++)
	{
		for (int j = max(i - T,0); j <= i - S; j++)
		{
			dp[i] = min(dp[i], dp[j] + flag[i]);
		}
	}
	
	int ans = INF;
	for (int i = L; i < L + T; i++) ans = min(ans, dp[i]);
	
	cout << ans << endl;
	
	return 0;
}
