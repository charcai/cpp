#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;
int T,n,a[N],dp[N],ans;
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),dp[i]=0;
		dp[1]=ans=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[j]==a[i]){
					dp[i]=max(dp[i],dp[j-1]+(i-j+1));
				}
			}
		}
		for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
