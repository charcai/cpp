#include<bits/stdc++.h>
using namespace std;
int t,n,a[200001],dp[200001];
int vis[200001];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(vis[a[i]]==0){
				vis[a[i]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]==a[j]){
					if(vis[a[j]]==j){
						dp[i]=max(dp[i],dp[j]+i-j+1);
					}
					else dp[i]=max(dp[i],dp[j]+i-j);
				}
				else{
					dp[i]=max(dp[i],dp[j]);
				}
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
/*
2
5
1 2 2 3 3
4
1 2 1 2
*/
