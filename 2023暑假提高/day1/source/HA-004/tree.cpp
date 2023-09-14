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
#define N 5000+10
int n,tot,Head[N],ver[N],Next[N],fa[N],di[N],xx[N],yy[N],cnt=1,v[N];
struct un{
	int du,id;
}dian[N];
void add(int x,int y){
	tot++;ver[tot]=y;Next[tot]=Head[x];Head[x]=tot;
}
int cmp(un x,un y){
	return x.du>y.du;
}
void dfs(int x,int f){
	fa[x]=f;
	for(int i=Head[x];i;i=Next[i]){
		int y=ver[i];
		if(y==f)continue;
		dfs(y,x);
	}
}
void up(int x){
	while(x!=0){
		di[x]++;
		x=fa[x];
	}
}
void down(int x){
	while(x!=0){
		di[x]--;
		x=fa[x];
	}
}
void work(int k){
	int ans=-1,num=0;
	for(int i=cnt;i<=n;i++){
		if(dian[i].du<dian[k].du)break;
		if(dian[i].du>dian[k].du){
			cnt=i+1;
			continue;
		}
		if(v[dian[i].id])continue;
		up(dian[i].id);
		int ansn=0;
		for(int i=1;i<n;i++){
			int x=xx[i],y=yy[i];
			if(fa[y]==x)swap(x,y);
			ansn+=abs(di[x]-(k-di[x]));
		}
		if(ansn>ans){
			ans=ansn;num=dian[i].id;
		}
		down(dian[i].id);
	}
	up(num);
	v[num]=1;
	writesp(ans);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		add(x,y);add(y,x);
		dian[x].du++;dian[y].du++;
		xx[i]=x;yy[i]=y;
	}
	for(int i=1;i<=n;i++){
		dian[i].id=i;
	}
	sort(dian+1,dian+n+1,cmp);
	dfs(1,0);
	writesp(0);
	for(int i=1;i<=n;i++){
		work(i);
	}
return 0;
}
/*
6
1 2
1 3
1 5
2 4
2 6

6
1 2
1 3
1 4
2 5
2 6
5
1 2
3 2
2 4
5 1
*/
