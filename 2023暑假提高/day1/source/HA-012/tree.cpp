#include<bits/stdc++.h>
using namespace std;
int n,u,v,head[5001],tot,dep[5001],size[5001],cnt,now[5001],sum;
bool vis[5001];
struct node{
	int u,v,nex;
}e[10002];
void add(int u,int v){
	e[tot].u=u;
	e[tot].v=v;
	e[tot].nex=head[u];
	head[u]=tot++;
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	size[u]=1;
	for(int i=head[u];i!=-1;i=e[i].nex){
		int v=e[i].v;
		if(v!=fa){
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
void dfs1(int u,int fa){
	if(vis[u]==1) now[u]=1;
	for(int i=head[u];i!=-1;i=e[i].nex){
		if(vis[e[i].v]==1&&e[i].v!=fa){
			dfs1(e[i].v,u);
			now[u]+=now[v];
		}
	}
}
void check(int u,int fa,int k){
	for(int i=head[u];i!=-1;i=e[i].nex){
		if(e[i].v!=fa){
			sum+=(abs(k-now[e[i].v]-now[e[i].v]));
		//	cout<<u<<' '<<v
			check(e[i].v,u,k);
		}
	}
}
int col(int k){
	int ans=0,tianjia;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			for(int j=head[i];j!=-1;j=e[j].nex){
				if(vis[e[j].v]==0){
					vis[e[j].v]=1;
					memset(now,0,sizeof(now));
					sum=0;
					dfs1(1,0);
					check(1,0,k);
					//cout<<endl;
					//cout<<k<<' '<<sum<<endl;
					if(sum>ans){
						tianjia=e[j].v;
						ans=sum;
					}
					vis[e[j].v]=0;
				}
			}
		}
	}
	vis[tianjia]=1;
	return ans;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	now[1]=1;
	cout<<0<<' ';
	cnt=1;
	dfs(1,0);
	cout<<n-1<<' ';
	vis[1]=1;
	for(int i=2;i<=n;i++){
		cout<<col(i)<<' ';
	}
	return 0;
}
