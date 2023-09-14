#include<bits/stdc++.h>
using namespace std;
int t,n,a[200001],ans[200001];
bool vis[200001];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		//queue<int> q;
		//for(int i=1;i<=n;i++){
		//	q.push(i);
		//}
		vector<int> v;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			memset(vis,0,sizeof(vis));
			v.push_back(a[i]);
			sort(v.begin(),v.end());
			int cnt=0,ans=0;
			for(int j=0;j<i;j++){
				if(v[j]==cnt) continue;
				cnt++;
				ans+=(v[j]-cnt);
			}
			//ans[i]=ans[i-1];
			//if(vis[a[i]]==1) continue;
			//vis[a[i]]=1;
			cout<<ans<<' ';
		}
		cout<<endl;
	}
	return 0;
}
/*
2
3
3 1 2
6
4 1 5 4 1 1
*/
