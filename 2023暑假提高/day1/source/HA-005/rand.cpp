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
#define INF 0x3f3f3f3f
#define N 5003
#define debug printf("Now is on line %d\n",__LINE__)
const int MOD=1000000007;
int n,m,v,cnt,ans,a[N];
int power(int u,int x)
{
	int num=1;
	for(;x;x>>=1,u=u*u%MOD) if(x&1) num=num*u%MOD;
	return num;
}
void dfs(int dep)
{
	if(dep>m)
	{
		int x=1;
		++cnt;
		for(int i=1;i<=n;++i) x=x*a[i]%MOD;
		ans=(ans+x)%MOD;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j) a[j]+=v;
		dfs(dep+1);
		for(int j=i;j<=n;++j) a[j]-=v;
	}
}
signed main()
{
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	read(n);read(m);read(v);
	for(int i=1;i<=n;++i) read(a[i]);
	dfs(1);
	writeln(ans*power(cnt,MOD-2)%MOD);
	return 0;
}
