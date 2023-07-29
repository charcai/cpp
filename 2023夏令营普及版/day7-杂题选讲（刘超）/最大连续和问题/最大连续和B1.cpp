#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 300000 + 10;
int a[N];
int s[N]; //前缀和

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	
	int ans = a[1];
	for (int R = 1; R <= n; R++)       //枚举右端点
	{
		int minv = INF;
		for (int L = R - m; L < R; L++)   
		{
			if (s[L] < minv) minv = s[L];
		}
		int sum = s[R] - minv;     //计算区间和
		if (sum > ans) ans = sum;  //更新最大值
	}
	cout << ans << endl;
	
	return 0;
}
