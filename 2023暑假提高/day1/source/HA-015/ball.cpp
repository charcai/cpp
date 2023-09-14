#include<bits/stdc++.h>
#define LL long long
using namespace std;

int T,n;
int a[200010],b[200010];
int num[200010],c[200010];
int dp[200010],ans,mn;

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mn=max(mn,a[i]);
			b[i]=num[a[i]];
			if(a[i]!=a[i-1]) num[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			int k=b[i],kk=c[a[i]];
			dp[i]=dp[i-1];
			if(k==0) continue;
			if(kk==0) kk=k;
			if(dp[k-1]+i-k+1>=dp[kk-1]+i-kk+1){
				dp[i]=max(dp[i],dp[k-1]+i-k+1);
				c[a[i]]=k;
			}
			else dp[i]=max(dp[i],dp[kk-1]+i-kk+1);
//			cout<<i<<"A"<<dp[i]<<endl;
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
		ans=0;
		for(int i=1;i<=n;i++) dp[i]=b[i]=0;
		for(int i=1;i<=mn;i++) num[i]=c[i]=0;
		mn=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

