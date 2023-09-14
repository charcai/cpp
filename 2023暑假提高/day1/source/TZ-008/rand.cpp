#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int n,m,v,a[5005],ans = 1;
int main()
{
	cin >> n >> m >> v;
	for (int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		a[i] += m / n * v;
	}
	for (int i = 1;i <= m % n;i++) a[i] += v;
	for (int i = 1;i <= n;i++) ans = ans * a[i] % Mod;
	cout << ans << endl;
	return 0;
}

