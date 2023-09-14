#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

const int maxn = 30;
const int maxm = 210;

int n, m, u[maxm], v[maxm], vis[maxn];
vector <int> G[maxn];

bool Try(int u, int v) {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < G[u].size(); i++) vis[G[u][i]] = u;
	for(int i = 0; i < G[v].size(); i++) vis[G[v][i]] = v;
	for(int i = 1; i <= n; i++) if(!vis[i]) return false;
	return true;
}

signed main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	for(int i = 1; i <= m; i++) {
		if(Try(u[i], v[i])) {
			puts("Yes");
			for(int i = 1; i <= n; i++) cout << vis[i] << " ";
			cout << endl;
			return 0;
		}
	}
	puts("No");
	return 0;
}

