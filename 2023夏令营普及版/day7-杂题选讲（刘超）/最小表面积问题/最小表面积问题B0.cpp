#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
int ans = INF;


int r[N], h[N];
void dfs(int dep, int v, int s)
{
	if (dep > m)
	{
		if (v == n) 
		{
			ans = min(ans, s + r[m] * r[m]);
		}
		return;
	}
	
	//优化搜索顺序，先半径后高度
	for (int i = r[dep - 1] + 1; i * i <= n - v; i++)  //计算上界时设高度为 1
		for (int j = h[dep - 1] + 1; i * i * j <= n - v; j++)
		{
			r[dep] = i; h[dep] = j;
			dfs(dep + 1, v + i * i * j, s + 2 * i * j);
		}
}

int main()
{
	cin >> n >> m;
	
	dfs(1,0,0);
	
	if(ans == INF) ans = 0;
	cout << ans << endl;
	
	return 0;
}
