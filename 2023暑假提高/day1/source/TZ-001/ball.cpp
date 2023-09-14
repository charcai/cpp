#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N = 2 * 114514;
int a[N];
int b[N];
bool slove() {
	int m1 = -1,m2 = -1;
	for(int i = 1; i <= n; i ++ ) {
		int tmp = b[a[i]];
		if(a[tmp] && a[i]) {

			if(i - tmp > m2 - m1) {
				m2 = i;
				m1 = tmp;
			}
		}
	}
//	cout << m1 << " " << m2 << endl;
	if(m2 == m1 && m2 == -1) {
		return 0;
	}
	for(int i = m1; i <= m2; i ++ ) {
		a[i] = 0;
	}
	return 1;
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		memset(b,0,sizeof(b));
		for(int i = 1; i <= n; i ++ ) {
			cin >> a[i];
			if(!b[a[i]]) {
				b[a[i]] = i;
			}
		}
		while(slove()){
			;
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++ ){
			if(!a[i]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
