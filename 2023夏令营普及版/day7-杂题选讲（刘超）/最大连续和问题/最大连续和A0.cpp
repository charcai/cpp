#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
int a[N];
int s[N]; //ǰ׺��

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	
	int ans = a[1];
	for (int R = 1; R <= n; R++)       //ö���Ҷ˵�
	{
		for (int L = 1; L <= R; L++)   //ö����˵�
		{
			int sum = s[R] - s[L - 1]; //���������
			if (sum > ans) ans = sum;  //�������ֵ
		}
	}
	cout << ans << endl;
	
	return 0;
}
