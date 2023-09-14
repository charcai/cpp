#include<bits/stdc++.h>
#define int long long
#define N 100005
#define INF INT_MAX
using namespace std;
struct star{
	int next,to,val;
}e[N<<2];
struct node{
	int u,step;
	bool operator<(const node& a)const{
		return step>a.step;
	}
};
priority_queue<node>q;
int m,n,k,cnt,head[N],dis[N],last,llast,fans;
bool vis[N],final;
void add(int u,int v,int w){
	e[++cnt].next=head[u];
	head[u]=cnt;
	e[cnt].to=v;
	e[cnt].val=w;
}
void dijkstra(int x){
	for(int i=1;i<=n;i++) dis[i]=INF,vis[i]=false;
	q.push(node{x,0});
	dis[x]=0;
	while(!q.empty()){
		int t=q.top().u;
		q.pop();
		if(vis[t]) continue;
		vis[t]=true;
		for(int i=head[t];i;i=e[i].next){
			int y=e[i].to,d=e[i].val;
			if(dis[y]>dis[t]+d){
				dis[y]=dis[t]+d;
				q.push(node{y,dis[y]});
			}
		}
	}
}
signed main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	dijkstra(n);
	if(dis[1]==INF){ 
		printf("inf");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<n;i++) q.push(node{i,min(dis[1],dis[i])});
	last=q.top().step;
	while(true){
		while(!q.empty()&&q.top().step==last){
			if(q.size()==1) final=true;
			q.pop();
		}
		fans++;
		if(final) break;
		last=q.top().step;
	}
	printf("%lld %lld\n",dis[1],fans);
	for(int i=1;i<n;i++) q.push(node{i,min(dis[1],dis[i])});
	for(int i=1;i<n;i++) vis[i]=true;
	vis[n]=false,last=q.top().step,fans=dis[1],final=false;
	while(true){
		for(int i=1;i<=n;i++){
			if(vis[i]) printf("1");
			else printf("0");
		}
		while(!q.empty()&&q.top().step==last){
			vis[q.top().u]=false;
			if(q.size()==1) final=true;
			q.pop();
		}
		printf(" %lld\n",last-llast);
		if(final){
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		llast=last,last=q.top().step;
	}
}
/*
7 10
1 3 5
2 6 8
3 2 6
4 1 6
7 6 5
2 4 7
5 7 1
1 5 7
2 7 2
1 2 3
*/
