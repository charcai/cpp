#include<bits/stdc++.h>
using namespace std;
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
#define maxn 25
#define int long long
int n,m,x,y,a[maxn],vis[maxn],e[maxn][maxn],flg,cnt=0;
bool check(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			for(int k=1;k<=n;++k) vis[k]=0;
			int x=i;
			while(!e[x][j]&&!vis[x]){
				vis[x]=1; x=a[x];
			}
			if(!e[x][j]) return false;
		}
}
void dfs(int x){
	if(flg||(cnt>=1e5&&n>6)) return ;
	if(x==n){
		if(check()){
			puts("Yes"); flg=1;
			for(int i=1;i<=n;++i) writesp(a[i]);
			putchar('\n');
		}
		++cnt; return ;
	}
	++x;
	for(int i=1;i<=n;++i)
		if(e[x][i]){
			a[x]=i; dfs(x);
		}
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=m;++i){
		read(x),read(y);
		e[x][y]=e[y][x]=1;
	}
	flg=0; dfs(0);
	if(!flg) puts("No");
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
*/
