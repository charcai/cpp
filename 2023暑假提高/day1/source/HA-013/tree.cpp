#include<bits/stdc++.h>
#define maxn 5010
using namespace std;

struct node{
	int u,v;
	int Nex;
};

long long n,x,y,tot1=0;
long long head[maxn],son[maxn],so[maxn],ans[maxn],vis[maxn];
long long b[510][510];
node edge[maxn*2];
stack<long long> q;

void add_edge(int x,int y){
	edge[++tot1].u=x; edge[tot1].v=y;
	edge[tot1].Nex=head[x]; head[x]=tot1;
}

void dfs(int x){
	q.push(x);
	vis[x]=1; son[x]=1; b[x][x]=1;
	for(int i=head[x];i;i=edge[i].Nex)
		if(!vis[edge[i].v]){
			dfs(edge[i].v);
			for(int j=1;j<=n;j++)
				b[x][j]=b[x][j]|b[edge[i].v][j];
			son[x]+=son[edge[i].v];
		}
	
	return ;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		add_edge(x,y);
		add_edge(y,x);
	}
	memset(b,0,sizeof(b));
	dfs(1);
	memset(ans,0,sizeof(ans));
	for(int i=2;i<=n;i++)
		ans[n]+=abs((n-son[i])-son[i]);
	for(int i=1;i<=n;i++) so[i]=son[i];
	for(int i=n-1;i>=1;i--){
		long long nw,mn=0x3f3f3f3f;
		for(int j=1;j<=n;j++)
			if(vis[j]){
				long long tot=0;
				for(int k=2;k<=n;k++)
					if((so[k]>=n-son[k] && b[k][j]) || (so[k]<=n-son[k] && !b[k][j])) tot++;
					else tot--;
				if(mn>tot) mn=tot,nw=j;
			}
		ans[i]=ans[i+1]-mn;
		for(int j=1;j<=n;j++)
			if(b[j][nw]) so[j]--;
			else son[j]++;
	}
	for(int i=0;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
	return 0;
}

/*

4
1 2
3 2
2 4

*/
