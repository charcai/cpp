#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,w,head[101],tot,d[101];
struct node{
	int u,v,nex,w;
}e[10001];
void add(int u,int v,int w){
	e[tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].nex=head[u];
	head[u]=tot++;
}
bool vis[101];
void dij(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		int k=0,minn=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&minn>d[j]){
				minn=d[j];
				k=j;
			}
		}
		vis[k]=1;
		for(int j=head[k];j!=-1;j=e[j].nex){
			if(!vis[e[j].v]&&d[e[j].v]>d[k]+e[j].w){
				d[e[j].v]=d[k]+e[j].w;
			}
		}
	}
}
int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	memset(d,0x3f,sizeof(d));
	d[n]=0;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dij();
	if(d[1]==0x3f3f3f3f){
		cout<<"inf";
		return 0;
	}
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	dij();
	int sumt=0,sump=0,jdt[n*n];
	memset(jdt,0,sizeof(jdt));
	bitset<100> bst[n*n];
	for(sumt=1;;sumt++){
		jdt[sump]++;
		for(int i=2;i<=n;i++){
			if(d[i]==1){
				sump++;
				break;
			}
		}
		bst[sump][0]=1;
		bool flag=0;
		for(int i=2;i<=n-1;i++){
			if(d[i]==0){
				bst[sump][i-1]=1;
			}
			else{
				d[i]--;
				if(d[i]==0){
					bst[sump][i-1]=1;
				}
				else flag=1;
			}
		}
		if(!flag) break;
	}
	jdt[sump]++;
	cout<<sumt<<' '<<sump+1<<endl;
	for(int i=0;i<=sump;i++){
		for(int j=0;j<n;j++){
			cout<<bst[i][j];
		}
		cout<<' '<<jdt[i]<<endl;
	}
	return 0;
}
