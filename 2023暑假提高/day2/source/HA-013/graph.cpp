#include<bits/stdc++.h>
using namespace std;

long long n,m,x,y,tot,cnt=0,flag=0;
long long a[25][25],vis[25],v[25],du[25],dfn[25],low[25],d[25];
long long ans[25],e[25];
stack<long long> q,Q,p;

void check(){
	long long s,t=0;
	while(!Q.empty()){
		e[++t]=Q.top();
		Q.pop();
	}
	for(int i=t;i>=1;i--) p.push(e[i]);
	tot=0;
	memset(v,0,sizeof(v));
	while(!p.empty()){
		s=p.top(); p.pop();
		for(int i=1;i<=n;i++)
			if(a[s][i] && !v[i]){
				tot++;
				v[i]=1;
			}
	}
	if(tot==n){
		memset(ans,0,sizeof(ans));
		for(int i=t;i>=1;i--) p.push(e[i]);
		s=p.top();
		while(!p.empty()){
			long long l=p.top(); p.pop();
			if(!p.empty()) ans[l]=p.top();
			else ans[l]=s;
		}
		for(int i=1;i<=n;i++)
			if(!ans[i]){
				for(int j=1;j<=t;j++)
					if(a[i][e[j]]){
						ans[i]=e[j];
						break;
					}
			}
		flag=1;
	}
	for(int i=t;i>=1;i--) Q.push(e[i]);
	return ;
}

void dfs(int x,int fa){
	q.push(x);
	long long op=0;
	vis[x]=1; dfn[x]=low[x]=++cnt;
	for(int i=1;i<=n;i++)
		if(a[x][i] && i!=fa){
			if(!vis[i]){
				dfs(i,x);
				if(d[i]) op=1,d[i]=1;
				if(flag==1) return ;
				low[x]=min(low[x],low[i]);
			} 
			else{
				low[x]=min(low[x],dfn[i]);
				if(low[x]<dfn[x]){
					long long o=q.top();
					while(dfn[o]>=low[x] && !q.empty()){
//						cout<<o<<" ";
						Q.push(o);
						q.pop();
						if(!q.empty()) o=q.top();
					}
//					cout<<endl;
					check();
					while(!Q.empty()){
						q.push(Q.top());
						Q.pop();
					}
				}				
			} 
		}
	vis[x]=0;
	q.pop();
	return ;
}

int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		tot=0;
		for(int i1=1;i1<=n;i1++)
			if(a[i][i1]){
				if(!vis[i1]) tot++;
				vis[i1]=1;
			}
		if(tot==n-1){
			cout<<"Yes"<<endl;
			for(int i1=1;i1<=n;i1++){
				if(i1!=i) cout<<i<<" ";
				else{
					if(i==1) cout<<2<<" ";
					else cout<<1<<" ";
				}
			}
			cout<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++) vis[i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i][j]){
				tot=0;
				for(int i1=1;i1<=n;i1++)
					if(a[i][i1]){
						if(!vis[i1]) tot++;
						vis[i1]=1;
					}
				for(int i1=1;i1<=n;i1++)
					if(a[j][i1]){
						if(!vis[i1]) tot++;
						vis[i1]=1;
					}
				if(tot==n){
					cout<<"Yes"<<endl;
					for(int i1=1;i1<=n;i1++){
						if(a[i1][i]) cout<<i<<" ";
						else cout<<j<<" ";
					}
					cout<<endl;
					return 0;
				}
				for(int i=1;i<=n;i++) vis[i]=0;
			}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	if(flag){
		cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}

/*

6 7
1 2
2 3
3 1
4 5
5 6
4 6
2 5

3 2
1 2
2 3

4 4
1 3
2 3
4 1
4 2

6 5
1 2
2 3
3 4
4 5
5 6

11 13
1 2
2 3
3 4
4 5
5 6
6 1
2 7
2 8
4 8
4 11
6 9
6 10
8 5

*/
