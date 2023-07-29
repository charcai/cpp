#include<bits/stdc++.h>
#define maxn 200010
#define pb emplace_back
#define int long long
using namespace std;
struct node{int id,dis;};
priority_queue<node,vector<node>,less<node> > q;
bool operator <(node a,node b){return a.dis<b.dis;}
int n,k,x,y,z,u,v,rt,fa[maxn],a[maxn],vis[maxn],d[maxn],ans;
vector<int> g[maxn];
void dfs(int x,int y){
	fa[x]=y;
	for(int i=0;i<g[x].size();++i){
		if(g[x][i]==y) continue;
		d[g[x][i]]=d[x]+1;
		dfs(g[x][i],x);
	}
}
void dfs2(int x,int y){
	a[x]=0;
	for(int i=0;i<g[x].size();++i){
		if(g[x][i]==y) continue;
		dfs2(g[x][i],x);
		a[x]=max(a[x],a[g[x][i]]+1);
	}
}
int get_rt(int u,int v){
	int r=d[v]>>1;
	while(d[v]>r) v=fa[v];
	return v;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		g[x].pb(y); g[y].pb(x);
	}
	d[1]=0; dfs(1,0); u=1;
	for(int i=2;i<=n;++i) if(d[i]>d[u]) u=i;
	d[u]=0; dfs(u,0); v=1;
	for(int i=2;i<=n;++i) if(d[i]>d[v]) v=i;
	rt=get_rt(u,v); dfs2(rt,0);
	q.push((node){rt,a[rt]}); vis[rt]=1;
	while(k--){
		x=q.top().id; q.pop();
		for(int i=0;i<g[x].size();++i)
			if(!vis[g[x][i]]){
				q.push((node){g[x][i],a[g[x][i]]});
				vis[g[x][i]]=1;
			}
	}
	cout<<q.top().dis+1<<endl;
	return 0;
}
