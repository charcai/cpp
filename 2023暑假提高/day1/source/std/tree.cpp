#include <bits/stdc++.h>
using namespace std;

int n,dep[5010],cnt[5010],ans[5010];
vector<int> v[5010];

inline void dfs(int x,int pr)
{
	for(int i=0;i<(int)v[x].size();i++) if(v[x][i]!=pr){
		dep[v[x][i]]=dep[x]+1;
		dfs(v[x][i],x);
	}
}

signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++) ans[i]=0;
	for(int i=1;i<=n;i++){
		dep[i]=0;dfs(i,-1);
		for(int j=0;j<=n;j++) cnt[j]=0;
		for(int j=1;j<=n;j++) cnt[dep[j]]++;
		int tot=0,sum=0;
		for(int j=0;j<=n;j++){
			for(int k=1;k<=cnt[j];k++){
				tot++;sum+=j;
				ans[tot]=max(ans[tot],(n-1)*tot-2*sum);
			}
		}
	}
	for(int i=0;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}
