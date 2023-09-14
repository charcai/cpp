#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

const int maxn = 2e5 + 10;

struct Node {
	int l, r, len;
} s[1000010];

bool Cmp(Node a, Node b) {
	if(a.l == b.l) return a.r < b.r;
	else return a.l < b.l;
}

struct Edge {
	int v, w, nex;
} edge[4000010];
int tot, head[1000010];

void Add(int u, int v) {
	edge[++tot].v = v;
	edge[tot].w = s[v].len;
	edge[tot].nex = head[u];
	head[u] = tot;
	return ;
}

struct Queue {
	int id, val;
	bool operator < (const Queue &x) const {
		return x.val > val;
	}
};
priority_queue <Queue> q;
int dis[1000010];
bool vis[1000010];

void Dij() {
	memset(vis, 0, sizeof(vis));
	memset(dis, -INF, sizeof(dis));
	dis[0] = 0; q.push(Queue{0, 0});
	while(!q.empty()) {
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i; i = edge[i].nex) {
			int v = edge[i].v;
			if(dis[v] < dis[u] + edge[i].w) {
				dis[v] = dis[u] + edge[i].w;
				q.push(Queue{v, dis[v]});
			}
		}
	}
	return ;
}

vector <int> m[maxn];
int n, cnt, ans, a[maxn];

signed main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		bool f = true;
		cin >> n;
		for(int i = 1; i <= n; i++) m[i].clear();
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			m[a[i]].push_back(i);
			if(a[i] != 1 && a[i] != 2 && f) f = false;
		}
		if(!f) {
			cnt = tot = 0;
			memset(head, 0, sizeof(head));
			for(int i = 1; i <= n; i++) {
				if(m[i].size() > 1) {
					for(int j = 0; j < m[i].size(); j++) {
						for(int k = j + 1; k < m[i].size(); k++) {
							s[++cnt].l = m[i][j];
							s[cnt].r = m[i][k];
							s[cnt].len = s[cnt].r - s[cnt].l + 1;
						}
					}
				}
			}
			sort(s + 1, s + cnt + 1, Cmp);
			for(int i = 1; i <= cnt; i++) {
				Add(0, i);
			}
			for(int i = 1; i < cnt; i++) {
				for(int j = i + 1; j <= cnt; j++) {
					if(s[j].l <= s[i].r) continue;
					Add(i, j);
				}
			}
			Dij();
			ans = 0;
			for(int i = 1; i <= cnt; i++) ans = max(ans, dis[i]);
			cout << ans << endl;
		} else {
			if(a[1] == a[n]) cout << n << endl;
			else {
				ans = 0;
				for(int i = n; i > 1; i--) {
					if(a[i] == a[1]) {
						ans = i;
						break;
					}
				}
				for(int i = 1; i < n; i++) {
					if(a[i] == a[n]) {
						ans = max(ans, n - i + 1);
						break;
					}
				}
				int f1 = 0;
				for(int i = 2; i < n; i++) {
					if(!f1 && a[i] == a[1]) f1 = i;
					if(f1 && a[i] == a[n]) ans = max(ans, n - i + 1 + f1);
				}
				f1 = 0;
				for(int i = n - 1; i > 1; i--) {
					if(!f1 && a[i] == a[n]) f1 = n - i + 1;
					if(f1 && a[i] == a[1]) ans = max(ans, f1 + i);
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
