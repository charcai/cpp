#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 300000 + 10;
int a[N];
int s[N]; //ǰ׺��

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	
	int ans = a[1];
	for (int R = 1; R <= n; R++)       //ö���Ҷ˵�
	{
		int minv = INF;
		for (int L = R - m; L < R; L++)   
		{
			if (s[L] < minv) minv = s[L];
		}
		int sum = s[R] - minv;     //���������
		if (sum > ans) ans = sum;  //�������ֵ
	}
	cout << ans << endl;
	
	return 0;
}
