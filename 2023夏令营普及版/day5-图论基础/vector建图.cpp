#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000 + 10;
int n, m, s;
struct Node
{
	int v, w;
	Node(int _v, int _w)
	{
		v = _v;
		w = _w;
	}
};
vector<Node> G[MAXN];

int main()
{
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++)	
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(Node(v,w));	
	}
	
	for(int i = 0; i < G[s].size(); i++)
	{
		cout << G[s][i].v << " " << G[s][i].w << endl;
	}
	
	return 0;
}

