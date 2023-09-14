#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

const int maxn = 5e3 + 10;
const int Mod = 1e9 + 7;

int n, m, v, ans, a[maxn];

int ksm(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = res * a % Mod;
		a = a * a % Mod;
		b >>= 1;
	}
	return res % Mod;
}

void DFS(int cnt) {
	if(cnt == m) {
		int res = 1;
		for(int i = 1; i <= n; i++) {
			res = res * a[i] % Mod;
		}
		ans = (ans + res) % Mod;
		return ;
	}
	for(int i = 1; i <= n; i++) {
		a[i] += v;
		DFS(cnt + 1);
	}
	for(int i = 1; i <= n; i++) a[i] -= v;
	return ;
}

signed main() {
	freopen("rand.in", "r", stdin);
	freopen("rand.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> v;
	for(int i = 1; i <= n; i++) cin >> a[n - i + 1];
	DFS(0);
	cout << ans * ksm(ksm(n, m), Mod - 2) % Mod << endl;
	return 0;
}

