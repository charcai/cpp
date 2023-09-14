#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x, p;

int main(){
	freopen("rotate.in", "r", stdin);
	freopen("rotate.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		ll sum = 0, target;
		bool flag = false;
		cin >> n >> x >> p;
		target = n - x;
		target %= n;
		for(ll i = 1; i <= n; i++){
			if(i > p) break;
			sum += i;
			if(sum % n == target){
				cout << "YES" <<endl;
				flag = true;
				break ;
			}
		}
		if(!flag) cout << "NO" <<endl;
	}

	return 0;
}

