#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
int a[N];
int s[N]; //前缀和

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	
	int ans = a[1];
	for (int R = 1; R <= n; R++)       //枚举右端点
	{
		int minv = s[0];               //找(右端点)左侧最小值
		for (int L = 1; L <= R - 1; L++)    
		{
			if (s[L] < minv) minv = s[L];
		}
		int sum = s[R] - minv;     //计算区间和
		if (sum > ans) ans = sum;  //更新最大值
	}
	cout << ans << endl;
	
	return 0;
}
