#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pqueue priority_queue
#define pb push_back
const int maxn=550;
int n;
int fa[maxn];
int tree[maxn];
bool v[maxn];
vector<int> vec[maxn];
//int dp[maxn][maxn][maxn];
//int f[maxn][maxn];
void Trav(int idx){
	tree[idx]=v[idx];
	for(int i=0;i<vec[idx].size();i++){
		int u=vec[idx][i];
		if(u==fa[idx]) continue;
		fa[u]=idx;
		Trav(u);
		tree[idx]+=tree[u];
	} 
//	cout<<idx<<' '<<tree[idx]<<'\n';
}
//void dfs(int idx){
//	for(int i=0;i<vec[idx].size();i++){
//		int u=vec[idx][i];
//		if(u==fa[idx])continue;
//		dfs(u);  
//	}
////	for(int i=0;i<=n;i++)dp[idx][i][0]=dp[idx][i][1]=0;
//	for(int i=0;i<vec[idx].size();i++){
//		int u=vec[idx][i];
//		if(u==fa[idx])continue;
//		for(int sum=0;sum<=n;sum++)
//		for(int i=0;i<=tree[idx];i++)f[sum][i]=dp[idx][sum][i];
//		for(int sum=0;sum<=n;sum++)
//		for(int l=max(0,sum-n+tree[u]);l<=min(sum,tree[u]);l++){
//			for(int k=min(sum,tree[idx]);k>=max(sum-n+tree[idx],l);k--){
////				if(sum==2&&idx==2){
////					cout<<u<<' '<<k<<' '<<l<<" ";//<<dp[idx][sum][k]<<' ';
////					cout<<dp[idx][sum][k-l]<<'+'<<dp[u][sum][l]<<'+'<<max(sum-l*2,2*l-sum)<<'\n';
////				}
////				if(sum==4&&k==2&&l==1)cout<<"QwQ\n";
////				cout<<idx<<' '<<sum<<' '<<k<<' '<<l<<'\n';
////				if(f[sum][k-l]==-1)continue;
////				cout<<idx<<"->"<<u<<' '<<sum<<' '<<k<<' '<<l<<"   "<<dp[idx][sum][k]<<"="<<dp[u][sum][l]<<'+'<<f[sum][k-l]<<'+'<<max(sum-l*2,2*l-sum)<<'\n';
//				dp[idx][sum][k]=max(dp[idx][sum][k],dp[u][sum][l]+f[sum][k-l]+max(sum-l*2,2*l-sum));
////				if(k>l)dp[idx][sum][k]=max(dp[idx][sum][k],dp[u][sum][l]+dp[idx][sum][k-l-1]+max(sum-l*2,2*l-sum));
//				
//			}
//		}
//	}
////	for(int sum=0;sum<=n;sum++){
////		for(int l=min(sum,tree[idx]);l>0;l--){
////			dp[idx][sum][l]=max(dp[idx][sum][l],dp[idx][sum][l-1]);
////		}
////	}
////	cout<<idx<<' '<<dp[idx][1][0]<<' '<<dp[idx][1][1]<<'\n';
//}
int ans;
int num;
void dfs(int idx){
	for(int i=0;i<vec[idx].size();i++){
		int u=vec[idx][i];
		if(u==fa[idx]) continue;
		ans+=max(2*tree[u]-num,num-2*tree[u]);
		dfs(u);
	} 
}
int x[maxn];
int main(){
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
	cin>>n;
//	memset(dp,-1,sizeof dp);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		vec[u].pb(v);
		vec[v].pb(u);
	}
	for(int i=0;i<(1<<20);i++){
		for(int j=0;j<n;j++) {
			if(i&(1<<j))v[j+1]=1;
			else v[j+1]=0;
		}Trav(1);
		ans=0;
		num=tree[1];
		dfs(1);
		x[num]=max(ans,x[num]);
	}
	for(int i=0;i<=n;i++){
		cout<<x[i]<<' ';
	} 
	return 0;
}
/*
4
1 2
3 2
2 4
*/
