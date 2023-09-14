#include<bits/stdc++.h>

#define int long long

#define N 100005

using namespace std;

struct star{

	int next,to;

}e[N];

int n,m,head[N],cnt,in[N];

bool vis[N];

void add(int u,int v){

	e[++cnt].next=head[u];

	head[u]=cnt;

	e[cnt].to=v;

}

signed main(){
	
	freopen("graph.in","r",stdin);
	
	freopen("graph.out","w",stdout);

	cin>>n>>m;

	for(int i=1,u,v;i<=m;i++){

		cin>>u>>v;

		add(u,v),add(v,u);

		in[u]++,in[v]++;

	}

	cout<<"Yes"<<endl;

	for(int i=1,maxn,id;i<=n;i++){

		maxn=0;

		for(int j=head[i];j;j=e[j].next){

			if(in[e[j].to]>maxn||(in[e[j].to]==maxn&&e[j].to>id)){

				maxn=in[e[j].to];

				id=e[j].to;

			}

		}

		cout<<id<<" ";

	}
	
	fclose(stdin);
	
	fclose(stdout);

	return 0;

}
