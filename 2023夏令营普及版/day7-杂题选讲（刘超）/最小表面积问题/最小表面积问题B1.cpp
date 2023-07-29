#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
int ans = INF;


int r[N], h[N];
void dfs(int dep, int v, int s)
{
	if (dep < 1)
	{
		if (v == n) 
		{
			ans = min(ans, s + r[m] * r[m]);
		}
		return;
	}
	
	//优化搜索顺序，先半径后高度，从大到小 
	for (int i = min(r[dep + 1] - 1, int(sqrt(n - v))); i >= dep; i--)
		for (int j = min(h[dep + 1] - 1, (n-v)/i/i); j >= dep; j--)
		{
			r[dep] = i; h[dep] = j;
			dfs(dep - 1, v + i * i * j, s + 2 * i * j);
		}
}

int main()
{
	cin >> n >> m;
	
	r[m + 1] = h[m + 1] = INF; //哨兵 
	dfs(m,0,0);
	
	if(ans == INF) ans = 0;
	cout << ans << endl;
	
	return 0;
}
