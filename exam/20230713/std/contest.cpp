#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 3e5 + 5;
int n,b[N],maxb,ans;

signed main(){
	freopen("contest.in","r",stdin);
	freopen("contest.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> b[i];
	sort(b + 1,b + 1 + n);
	for(int i = 1;i <= n;i++)
		maxb = max(maxb,b[i] + n + 1 - i);
	for(int i = 1;i <= n;i++)
		if (b[i] + n >= maxb)
			ans++;
	cout << ans << endl;
	return 0;
} 
