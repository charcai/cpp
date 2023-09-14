#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace IO
{
	template <typename T> inline void read(T &x)
	{
		x=0;int y=1;
		char c=getchar();
		while(c<'0'||c>'9'){if(c=='-')y=-1; c=getchar();}
		while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
		x*=y;
		return;
	}
	template <typename T> inline void write(T x)
	{
		if(x<0){putchar('-');x=-x;}
		if(x>9) write(x/10);
		putchar(x%10 + '0');
		return;
	}
}
using namespace IO;
#define writeln(x) write(x),putchar('\n')
#define writesp(x) write(x),putchar(' ')
#define INF 0x3f3f3f3f3f3f3f3f
#define N 22
#define debug printf("Now is on line %d\n",__LINE__)
int n,m,w[N],a[N];
void dfs(int dep)
{
	if(dep==n)
	{
		int S,T,x;
		for(int i=0;i<n;++i) if(!((w[i]>>a[i])&1)) return;
		for(int i=0;i<n;++i)
		{
			x=a[i];S=(1<<i);
			for(int j=0;j<=n;++j)
			{
				S|=(1<<x);
				x=a[x];
			}
			T=0;
			for(int j=0;j<n;++j) if((S>>j)&1) T|=w[j];
			if(T+1!=(1<<n)) return;
		}
		puts("Yes");
		for(int j=0;j<n;++j) writesp(a[j]+1);
		exit(0);
	}
	for(a[dep]=0;a[dep]<n;++a[dep]) dfs(dep+1);
	return;
}
signed main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int u,v;
	read(n);read(m);
	for(int i=1;i<=m;++i)
	{
		read(u);read(v);
		--u;--v;
		w[u]|=(1<<v);w[v]|=(1<<u);
	}
	dfs(0);
	puts("No");
	return 0;
}
