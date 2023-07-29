#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("ant10.in","w",stdout);
	
	srand(time(NULL));
	int n, t;
	n = 100000; t = 100000;
	cout << n << " " << t << endl;
	
	for (int i = 1; i <= n; i++)
	{
		int x, flag;
		x = rand() % 1000000;
		flag = rand() % 2;
		if (flag == 1) x = -x;
		int d = rand() % 2;
		if (d == 0) d = 1; else d = -1;
		cout << x << " " << d << endl;
	}
	
	return 0;
}
