#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("oj10.in","w",stdout);
	srand(time(NULL));
	int n = 1000000;
	cout << n << endl;
	while (n--)
	{
		int a, b;
		a = rand() % 100000;
		b = rand() % (100000 - a + 1) + a;	
		cout << a << " " << b << endl;
	}	
	return 0;
}

