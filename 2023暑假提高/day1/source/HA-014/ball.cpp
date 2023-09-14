#include<bits/stdc++.h>
#define MAXN 20010
using namespace std;
vector<int>p[MAXN];
bool vis[MAXN];
int n;
int maxn=-0x3f;
void work(int wiki,int ans){
	if(wiki==n){
		maxn=max(maxn,ans);
		return;
	}
	for(register int i=0;i<p[wiki].size();i++){
		if(vis[p[wiki][i]])continue;
	    for(register int j=i+1;j<p[wiki].size();j++){
	    	if(vis[p[wiki][j]])continue;
			int tmp=ans;
			vector<int>tp;
	    	for(register int k=p[wiki][i];k<=p[wiki][j];k++){
	    		if(!vis[k]){
	    			tmp++;
	    			tp.push_back(k);
				}
	    		vis[k]=1;
			}
			work(wiki+1,tmp);
			for(register int k=0;k<tp.size();k++){
				vis[k]=0;
			}
		}
	}
	work(wiki+1,ans);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int T;
	cin>>T;
	for(register int l=1;l<=T;l++){
		cin>>n;
		for(register int i=1;i<=n;i++){
			int x;
			cin>>x;
			p[x].push_back(i);
		}
		work(1,0);
		cout<<maxn<<endl;
		for(int i=1;i<=n;i++){
			p[i].clear();
		}
		memset(vis,0,sizeof(vis));
		maxn=-0x3f;
	}
	return 0;
}
