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
	int minv = s[0];
	
	for (int R = 1; R <= n; R++)      //ö���Ҷ˵�
	{
		int sum = s[R] - minv;        //���������
		if (sum > ans) ans = sum;     //�������ֵ
		if (s[R] < minv) minv = s[R];
	}
	cout << ans << endl;
	
	return 0;
}
