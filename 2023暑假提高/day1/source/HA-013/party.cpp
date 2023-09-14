#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

long long n,m,x,y,z,flag=0;
long long a[110][110],b[110][110],vis[110];
long long tim[110],num[110];
queue<long long> q;

void dfs(int x){
	vis[x]=1;
	for(int i=1;i<=n;i++)
		if(a[x][i]!=inf && !vis[i]) dfs(i); 
	return ;
}

int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(x!=1) flag=1;
		a[x][y]=z;
		a[y][x]=z;
	}
	if(!flag){
		if(m<n-1){
			cout<<"inf"<<endl;
			return 0;
		}
		long long tot=0;
		for(int i=1;i<=n;i++)
			if(a[1][i]!=inf) tot+=a[1][i];
		cout<<tot<<" "<<m<<endl;
		for(int i=1;i<=n;i++)
			if(a[1][i]!=inf){
				for(int j=1;j<i;j++) cout<<1;
				cout<<0;
				for(int j=i+1;j<=n;j++) cout<<1;
				cout<<" "<<a[1][i]<<endl;
			}
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			if(i==1) b[j][j+i]=a[j][j+i];
			else b[j][j+i]=min(b[j][j+i-1],b[j+1][j+i]);
	memset(vis,0,sizeof(vis));
	dfs(1);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			cout<<"inf"<<endl;
			return 0;
		}
	memset(num,0,sizeof(num));
	memset(tim,0x3f,sizeof(tim)); tim[n]=0;
	q.push(n);
	while(!q.empty()){
		long long p=q.front(); q.pop();
		for(int i=1;i<=n;i++)
			if(a[p][i] && tim[i]>tim[p]+a[p][i]){
				tim[i]=tim[p]+a[p][i];
				q.push(i);
			}
	}
	cout<<tim[1]<<" "<<n*n<<endl;
	return 0;
}

/*

5 4
1 3 2
1 4 2
2 3 1
2 5 1

*/
