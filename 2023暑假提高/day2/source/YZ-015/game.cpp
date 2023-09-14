#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, a[200001];
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			sort(a + 1, a + 1 + i);
			int ans = 0, idx = 0;
			for(int i = 1; i <= n; i++){
		        idx++;
		        if (a[i] >= idx) ans += a[i] - idx;
		        else idx--;
		    }
		    cout << ans << ' ';
		}
		cout <<endl;
	}

	return 0;
}


