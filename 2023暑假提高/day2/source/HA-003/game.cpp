#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3f

const int maxn = 2e5 + 10;

int n, sum, top, a[maxn], pre[maxn], ans[maxn];
bool vis[maxn];

signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		if(n <= 2000) {
			priority_queue <int, vector<int>, greater<int> > q;
			for(int i = 1; i <= n; i++) cin >> a[i];
			ans[1] = a[1] - 1;
			for(int i = 2; i <= n; i++) {
				ans[i] = 0;
				for(int j = 1; j <= i; j++) q.push(a[j]);
				int las = q.top(); q.pop();
				while(!q.empty()) {
					int t = q.top(); q.pop();
					if(las == t) continue;
					else if(t > las + 1) ans[i] += t - las - 1, las += 1;
					else las = t;
				}
			}
			for(int i = 1; i <= n; i++) cout << ans[i] << " ";
			cout << endl;
		} else {
			memset(vis, 0, sizeof(vis));
			memset(pre, 0, sizeof(pre));	
			for(int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
			top = sum = 0;
			for(int i = 1; i <= n; i++) {
				top++;
				if(a[i] < top && vis[a[i]]) {
					top--; 	
					sum += a[i];
				} else sum += top;
				vis[a[i]] = true;
				ans[i] = pre[i] - sum;
			}
			for(int i = 1; i <= n; i++) cout << ans[i] << " ";
			cout << endl;	
		}
	}
	return 0;
}

