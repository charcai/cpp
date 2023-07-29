#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
int n, m;
vector<int> G[MAXN];
int deg[MAXN];
int a[MAXN], cnt;

void topsort()
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(deg[i] == 0) q.push(i);
	
	while(q.size())
	{
		int x = q.front(); q.pop();
		a[++cnt] = x;
		for(int i = 0; i < G[x].size(); i++)
		{
			int y = G[x][i];
			deg[y]--;
			if(deg[y] == 0) q.push(y); 
		}
	}
}

int main()
{
	cin >> n >> m;
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		deg[v]++;  //预处理所有点的入度 
		G[u].push_back(v);
	}	
	
	topsort();
	
	for(int i = 1; i <= cnt; i++)
		cout << a[i] << " ";
	cout << endl; 
			
	return 0;
}
