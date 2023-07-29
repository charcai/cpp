#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("maxsum10.in","w",stdout);
	
	srand(time(NULL));
	
	int n, m;
	n = 300000;
	m = rand() % n + 1;
	cout << n << " " << m << endl;
	
	for (int i = 1; i <= n; i++)
	{
		int x = rand() % 1000;
		int f = rand() % 2;
		if (f == 0) cout << x << " ";
		else cout << -x << " ";
	}
	cout << endl;
	
	return 0;
}
