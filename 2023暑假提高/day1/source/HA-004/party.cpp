#include<bits/stdc++.h>
using namespace std;

#define int long long
namespace IO{
	template<typename T> inline void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x==0){
			putchar('0'); return ;
		}
		if(x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}
	template<typename T> inline void read(T &x){
		x=0; int w=1; char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') w=-1; ch=getchar();
		}
		while(isdigit(ch))
			x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
		x*=w; return ;
	}
}
using namespace IO;
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')
#define inf 0x3f3f3f3f
#define mod 998244353
#define N 110
int Head[N],ver[N],Next[N],tot,edge[N],d[N],t[N],num;
int n,m;
void add(int x,int y,int z){
	tot++;ver[tot]=y;edge[tot]=z;Next[tot]=Head[x];Head[x]=tot;
}
bool v[N];
struct un{
	int x,y;
};
bool operator <(const un &a,const un &b){
	return a.y>b.y;
}
priority_queue<un>que;
bool ans[N*N][N];
struct node{
	int id,d;
};
node a[N];
int cmp(node x,node y){
	return x.d<y.d;
}
void dij(){
	memset(d,inf,sizeof(d));
	memset(v,0,sizeof(v));
	que.push(un{n,0});
	d[n]=0;
	while(que.size()){
		int x=que.top().x;que.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=Head[x];i;i=Next[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				que.push(un{y,d[y]});
			}
		}
	}
}
signed main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int x,y,z;
		read(x);read(y);read(z);
		add(x,y,z);add(y,x,z);
	}
	dij();
	if(d[1]>=inf){
		printf("inf\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i].d=min(d[i],d[1]);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)ans[0][i]=1;
	t[0]=a[1].d;
	int s=t[0],cnt=1;
	for(int i=1;i<=n;i++)ans[1][i]=ans[0][i];
	while(a[cnt].d==a[1].d){
		ans[1][a[cnt].id]=0;
		cnt++;	
	}
	while(cnt<=n){
		num++;
		t[num]=a[cnt].d-s;
		s=a[cnt].d;
		for(int i=1;i<=n;i++)ans[num+1][i]=ans[num][i];
		while(a[cnt].d==s){
			ans[num+1][a[cnt].id]=0;
			cnt++;
		}
	}
	writesp(a[n].d);writeln(num);
	for(int i=1;i<=num;i++){
		for(int j=1;j<=n;j++){
			printf("%lld",ans[i][j]);
		}
		putchar(' ');
		writeln(t[i]);
	}
return 0;
}
/*
5 4
1 3 2
1 4 2
2 3 1
2 5 1
5 4
1 2 2
2 3 2
3 5 1
2 5 1
*/
