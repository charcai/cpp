#include<bits/stdc++.h>
#define maxn 50005
#define INE 0x3f3f3f3f
using namespace std;
struct node{
	int u,v;
};
node edge[maxn*2];
int next[maxn*2],head[maxn],s[maxn],d[maxn];
int n,dp1[maxn],dp[maxn];

void work(int k){
	d[k]=1;
	for(int i=head[k];i!=0;i=next[i]){
		int x=edge[i].v;
		//cout<<k<<":"<<x<<endl;
		if(s[x]==0){
			s[x]=1;
			work(x);
			d[k]+=d[x];
			dp[k]+=dp[x]+d[x];
		}
	}
	return ;
}

void work1(int k){
	//cout<<k<<endl;
	for(int i=head[k];i!=0;i=next[i]){
		int x=edge[i].v;
		//cout<<s[x]<<endl;
		if(s[x]==0){
			s[x]=1;
			dp1[x]=dp1[k]+(n-d[x])+(dp[k]-dp[x]-d[x]);
			//cout<<x<<" "<<dp1[x]<<endl;
			work1(x);
		}
	}
	return ;
}

int main(){
	//freopen("temp.in","r",stdin);
	int tot=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		edge[++tot].u=x;edge[tot].v=y;
		next[tot]=head[x];head[x]=tot;
		//cout<<edge[tot].u<<" "<<edge[tot].v<<next[tot]<<endl;
		
		edge[++tot].u=y;edge[tot].v=x;
		next[tot]=head[y];head[y]=tot;
		//cout<<edge[tot].u<<" "<<edge[tot].v<<next[tot]<<endl;
	}
	s[1]=1;work(1);
	memset(s,0,sizeof(s));
	//for(int i=1;i<=n;i++)cout<<i<<":"<<d[i]<<" "<<dp[i]<<endl;
	s[1]=1;work1(1);
	
	int ans=INE,ans1=0;
	for(int i=1;i<=n;i++){
		//cout<<i<<":"<<dp1[i]<<endl;
		if(dp[i]+dp1[i]<ans){
			ans=dp[i]+dp1[i];ans1=i;
		}
	}
	//cout<<ans1<<endl;
	printf("%d %d\n",ans1,ans);
	return 0;
}
