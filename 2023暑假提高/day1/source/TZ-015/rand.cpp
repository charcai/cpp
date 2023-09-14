#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;

int main()
{
	freopen("rand.in", "r", stdin);
	freopen("rand.out", "w", stdout);
	srand(time(0));
	cout << rand() % Mod * rand() % Mod << endl;
	return 0;
}
