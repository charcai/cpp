#include<bits/stdc++.h>
using namespace std;
int n,m,u[1000],v[1000],ans[21],fa[21],h;
vector<int> g[21];
bool t,vis[21];
bool dfs1(int wz,int aim){
	if(vis[wz]==1) return 0;
	for(int i=0;i<g[wz].size();i++){
		if(g[wz][i]==aim) return 1;
	}
	vis[wz]=1;
	return dfs1(ans[wz],aim);
}
bool check(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			memset(vis,0,sizeof(vis));
			if(!dfs1(i,j)){
				return 0;
			}
		}
	}
	return 1;
}
int father(int u){
	return u==fa[u]?u:father(fa[u]);
}
void dfs(int dep){
	if(t) return ;
	if(dep==n+1){
		//for(int i=1;i<=n;i++){
		//	cout<<ans[i]<<' ';
		//}
		//cout<<endl;
		if(check()){
			cout<<"Yes"<<endl;
			for(int i=1;i<=n;i++){
				cout<<ans[i]<<' ';
			}
			t=1;
			return;
		}
		return;
		//cout<<1<<endl;
	}
	if(t) return;
	for(int i=0;i<g[dep].size();i++){
		bool flag=0;
		ans[dep]=g[dep][i];
		//if(father(dep)==father(g[dep][i])){
		//	h++;
		//	flag=1;
		//}
		//if(h==2){
		//	h--;
		//	continue;
		//}
		//fa[g[dep][i]]=father(dep);
		dfs(dep+1);
		//if(flag) h--;
		//if(!flag) fa[g[dep][i]]=g[dep][i];
	}
	if(t) return ;
	//cout<<"No"<<endl;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	dfs(1);
	if(!t) cout<<"No";
	return 0;
}
