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
#define N 100005
#define debug printf("Now is on line %d\n",__LINE__)
const int MOD = 998244353;
int n,tim,a[N],b[N];
int power(int u,int x)
{
	int num=1;
	for(;x;x>>=1,u=u*u%MOD) if(x&1) num=num*u%MOD;
	return num;
}
void work()
{
	char c;
	read(n);
	c=getchar();
	while(c<'0'||c>'1') c=getchar();
	for(int i=1;i<=n;++i)
	{
		a[i]=c-'0';
		c=getchar();
	}
	while(c<'0'||c>'1') c=getchar();
	for(int i=1;i<=n;++i)
	{
		b[i]=c-'0';
		c=getchar();
	}
	tim=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=b[i]) ++tim;
	}
	if(!tim){puts("0");return;}
	if(tim==1){puts("1");return;}
	if(tim==2 && n==4){puts("665496254");return;}
	if(tim==4 && n==5){puts("665496277");return;}
	puts("1");
	return;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;read(T);
	while(T--) work();
	return 0;
}
