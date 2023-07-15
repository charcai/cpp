#include<bits/stdc++.h>
using namespace std;
int n,d[100005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> d[i];
		if (d[i] > d[i - 1])
			ans += d[i] - d[i - 1];
	}
	cout << ans << endl;
	return 0;
}
