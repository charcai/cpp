#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
int n, m;
vector<int> G[MAXN];
int d[MAXN];

void bfs()
{
	queue<int> q;
	q.push(1); d[1] = 1;
	
	while(q.size())
	{
		int x = q.front(); q.pop();
		cout << x << " ";
		
		for(int i = 0; i < G[x].size(); i++)
		{
			int y = G[x][i];
			if(!d[y])
			{
				q.push(y);
				d[y] = d[x] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	bfs();
		
	return 0;
}

