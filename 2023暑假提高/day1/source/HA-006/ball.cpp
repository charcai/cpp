#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define inf 0x3f3f3f3f
#define int long long
int a[N];
int dp[N];
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int T,n,ans;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=1;j<i;j++){
				if(a[i]==a[j]) dp[i]=max(dp[i],dp[j-1]+(i-j+1));
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
