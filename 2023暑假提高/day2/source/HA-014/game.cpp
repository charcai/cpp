#include<bits/stdc++.h>
using namespace std;
int a[200200];
int hp[200200];
int kill[200200];
int minn[200200];
int n;
int maxnum=-1;
void dfs(int dep){
	bool flag1=1;
	for(int i=1;i<=n;i++){
		if(kill[i])flag1=0;
		if(kill[i]==0){
			minn[i]=min(minn[i],a[i]);
		}
	}
	if(flag1)return;
	for(int i=1;i<=n;i++){
		if(!kill[i])continue;
		a[i]++;
		kill[i]--;
		dfs(dep+1);
		a[i]--;
		kill[i]++;
	}
	bool flag=1;
	int d[n+10];
	for(int i=1;i<=n;i++)d[i]=kill[i];
	while(flag){
		flag=0;
		for(int i=1;i<=n;i++){
			if(!kill[i])continue;
			kill[i]--;
			if(!kill[i])flag=1;
		}
	}
	dfs(dep+1);
	for(int i=1;i<=n;i++)kill[i]=d[i];
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	cin>>T;
	for(register int ll=1;ll<=T;ll++){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)minn[i]=INT_MAX;
		for(int i=1;i<=n;i++){
			cin>>hp[i];
			kill[i]=hp[i];
		}
		dfs(1);
		for(int i=1;i<=n;i++)cout<<minn[i]<<" ";
		cout<<endl;
	}
	return 0;
}
