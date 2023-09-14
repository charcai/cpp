#include <bits/stdc++.h>

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)

const int N = 5005;

int n, ans[N];
std::vector<int> e[N];
void Addedge(int u, int v) {
	e[u].push_back(v);
	e[v].push_back(u);
}

int siz[N], flag[N];
void Dfs2(int u, int f) {
	siz[u] = flag[u];
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i];
		if (v == f) continue;
		Dfs2(v, u);
		siz[u] += siz[v];
	}
}
int sum(int k) {
	int res = 0;
	Dfs2(1, 0);
	F(i, 2, n) res += abs(k - siz[i] - siz[i]);
	return res;
}
void Dfs(int dep, int num) {
	ans[dep] = std::max(ans[dep], sum(dep));
	if (dep == n || num == n) return;
	F(i, num + 1, n) 
		flag[i] = 1,
		Dfs(dep + 1, i),
		flag[i] = 0;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	std::cin >> n;
	F(i, 1, n - 1) {
		int u, v;
		std::cin >> u >> v;
		Addedge(u, v);
	}
	Dfs(0, 0);
	F(i, 0, n) std::cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
