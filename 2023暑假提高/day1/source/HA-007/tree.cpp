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
#define maxn 5010
#define int long long
#define pb push_back
int n,x,y,dp[maxn][maxn],sz[maxn],nw;
vector<int> g[maxn];
void dfs(int x,int fa){
	dp[x][0]=dp[x][1]=0; sz[x]=1;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(y==fa) continue;
		dfs(y,x); sz[x]+=sz[y];
		for(int j=min(nw,sz[x]);j>=0;--j)
			for(int k=0;k<=min(j,sz[y]);++k)
				if(nw-k<=n-sz[y]&&j-k<=sz[x]-sz[y])
					dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[y][k]+abs(nw-k-k));
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	for(int i=1;i<n;++i){
		read(x); read(y);
		g[x].pb(y); g[y].pb(x);
	}
	for(int i=0;i<=n;++i){
		for(int j=1;j<=n;++j)
			for(int k=0;k<=n;++k) dp[j][k]=0;
		nw=i; dfs(1,0);
		writesp(dp[1][nw]);
	}
	putchar('\n');
	return 0;
}
/*
4
1 2
1 3
1 4
*/
