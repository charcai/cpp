#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 10005;
const int INF = (1<<30);

int n,m;
int a[N];
int head[N],tot;
struct node{
	int id,dis;
	bool operator <(const node &a) const {
		return dis>a.dis;
	}
};
struct edge{
	int v,nxt,w;
}e[N<<1];

priority_queue<node> q;

int is[105],vis[N];
int ans[N][105],t[N];
int T,k;

void add(int u,int v,int w)
{
	e[++tot].nxt=head[u];
	head[u]=tot;
	e[tot].v=v;
	e[tot].w=w;
}


int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);

	cin>>n>>m;
	int aa=0;
	for(int i=1;i<n;i++) is[i]=1;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
		if(x==1||y==1)aa++;
	}
	if(m==0||aa==m)
	{
		cout<<"inf";
		return 0;
	}
	for(int i=head[n];i;i=e[i].nxt)
	{
		q.push((node){e[i].v,e[i].w});
	}
	q.push((node){n,0});
	while(!q.empty())
	{
		node tmp=q.top();q.pop();
		int max_=tmp.dis,a[105],tot_a=0;
		int flag=0;
		
		a[++tot_a]=tmp.id;
		
		vis[tmp.id]=1;
		
		while(q.size())
		{
			node tp=q.top();
			if(tp.dis==max_){
				a[++tot_a]=tp.id;
				q.pop();			
			}
			else break;
		}
		
		//for(int i=1;i<=tot_a;i++)if(a[i]==1)flag=1;
		//if(flag)break;
		
		//if(tmp.id!=n){
			t[++k]=max_;
			for(int i=1;i<=tot_a;i++) is[a[tot_a]]=0;
			for(int i=1;i<=n;i++) ans[k][i]=is[i];
		//}
		
		
		for(int j=1;j<=tot_a;j++)
		{
			int u=a[j];//cout<<u<<endl;
			for(int i=head[u];i;i=e[i].nxt)
			{
			
				if(vis[e[i].v])continue;//	cout<<e[i].v<< " "<<e[i].w<<endl;
				q.push((node){e[i].v,e[i].w});
			}
		}
		
	}
	for(int i=1;i<=k;i++)
	{
		if(ans[i][1]==0)
		{
			k=i-1;
			break;
		}
	}
	T=0;
	for(int i=k;i>=1;i--)T+=t[i+1];
	cout<<T<<" "<<k<<endl;
	for(int i=k;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<" ";
		cout<<t[i+1]<<endl;
	}
	return 0;
}
/*
5 4 
1 3 2 
1 4 2 
2 3 1 
2 5 1 
*/
