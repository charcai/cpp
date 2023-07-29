#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
int n, m;
bool vis[N];
int a[N], deg[N];
vector<int> G[N];
bool adj[N][N];

int ans;

struct Node
{
	int x, steps;
	Node (int _x, int _steps)
	{
		x = _x; steps = _steps;
	}
};

void topsort()
{
	queue<Node> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) q.push(Node(i,1));
			
	while (q.size())
	{
		Node cur = q.front(); q.pop();
		int x = cur.x;
		
		ans = max(ans, cur.steps);
		
		for (int i = 0; i < G[x].size(); i++)
		{
			int y = G[x][i];
			deg[y]--;
			if (deg[y] == 0) q.push(Node(y,cur.steps + 1)); 
		}
	}
}

int main()
{
	//freopen("level.in","r",stdin);
	//freopen("level.out","w",stdout);
	
	cin >> n >> m;
	
	while (m--) //����m�˳��� 
	{
		int s; cin >> s;
		memset(vis,0,sizeof(vis));
		
		for (int i = 1; i <= s; i++) 
		{
			cin >> a[i];
			vis[a[i]] = 1;
		}
			
		for (int i = a[1]; i <= a[s]; i++)
		{
			if (vis[i])
			{
				for (int j = a[1]; j <= a[s]; j++) //ö�پ��������г�վ 
				{
					if (!vis[j] && !adj[j][i]) //adj�����ж�j��i�Ƿ����бߣ������ظ����� 
					{
						G[j].push_back(i); 
						adj[j][i] = true; 
						deg[i]++;
					} 
				}
			}
		}
	}
	
	topsort();
	
	cout << ans << endl;
		
	return 0;
}

