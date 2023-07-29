#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
int ans = INF;
int minv[N], mins[N];

int r[N], h[N];
void dfs(int dep, int v, int s)
{
	if (v + minv[dep] > n) return;    //�����Լ�֦ 
	if (s + mins[dep] >= ans) return; //�����Լ�֦1 
	if (s + 2*(n-v)/r[dep+1] >= ans) return; //�����Լ�֦2
	
	if (dep < 1)
	{
		if (v == n) 
		{
			ans = min(ans, s + r[m] * r[m]);
		}
		return;
	}
	
	//�Ż�����˳���Ȱ뾶��߶�
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
	for(int i = 1; i <= m; i++) //�뾶�߶�����Ϊ1~m 
	{
	    minv[i] = minv[i - 1] + i * i * i;
	    mins[i] = mins[i - 1] + 2 * i * i;
	}
	
	r[m + 1] = h[m + 1] = INF; //�ڱ� 
	dfs(m,0,0);
	
	if(ans == INF) ans = 0;
	cout << ans << endl;
	
	return 0;
}
