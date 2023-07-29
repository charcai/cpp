#include <bits/stdc++.h>
using namespace std;

int a[510][510];
int n, m;

int main()
{
	freopen("maze9.in","w",stdout);
	
	srand((int)time(NULL));   //每次执行种子不同，生成不同的随机数
	n = 30;
	m = 30;
	
	cout << n << " " << m << endl;
	
	int k = 100;
	while(k--)
	{
		int i = rand() % n + 1;
		int j = rand() % m + 1;
		a[i][j] = 1;
	}
	
	a[1][1] = a[n][m] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
