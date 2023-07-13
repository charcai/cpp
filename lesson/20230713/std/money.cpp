#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105,M = 51000,Ai = 25005;
int t,n,m,a[N],ans;
bool dp[Ai];

signed main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i];	
			m = max(m,a[i]);		
		}
		memset(dp,false,sizeof(dp));
		ans = 0;
		dp[0] = true;
		sort(a + 1,a + 1 + n);			
		for(int i = 1;i <= n;i++){
			if (dp[a[i]])
				continue;
			ans++;
			for(int j = a[i];j <= m;j++)
				dp[j] = dp[j] | dp[j - a[i]]; 	
		}	
		cout << ans << endl;		
	}
	return 0;
}
