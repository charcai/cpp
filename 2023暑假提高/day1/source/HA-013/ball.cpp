#include<bits/stdc++.h>
#define maxn 200010
using namespace std;

long long n,_,ans;
long long a[maxn],b[maxn],pre[maxn],dp[maxn];

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);		
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(pre,0,sizeof(pre));
	memset(dp,0,sizeof(dp));
	cin>>_;
	while(_--){
		cin>>n; ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			pre[i]=b[a[i]],b[a[i]]=i;
		for(int i=1;i<=n;i++) b[i]=0;
//		for(int i=1;i<=n;i++) cout<<pre[i]<<" "; cout<<endl;
		for(int i=1;i<=n;i++)
			if(pre[i]){
				if(pre[pre[i]]) dp[i]=dp[pre[i]]+i-pre[i];
				dp[i]=dp[pre[i]-1]+i-pre[i]+1;
			}
			else dp[i]=dp[i-1];
		for(int i=1;i<=n;i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
		for(int i=0;i<=n;i++)
			a[i]=b[i]=pre[i]=dp[i]=0;
	}
	return 0;
}

/*

2
10
1 3 4 1 3 6 7 8 9 3
4
1 2 1 2 

*/
