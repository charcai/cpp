#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
int a[N];
int dp[N]; //dp[i]��ʾ�Ե� i ����Ϊ��β�����������

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = a[1];
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		//dp[i] = max(dp[i - 1],0) + a[i];
		sum += a[i];
		if (sum > ans) ans = sum;
		if (sum < 0) sum = 0;
	}
	cout << ans << endl;
	return 0;
}
