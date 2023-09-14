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
#define N 105
#define M 5005
#define debug printf("Now is on line %d\n",__LINE__)
int n,m;
struct dot{int u,v,x;}d[M];
signed main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	int flag=0,flag2=0;
	read(n);read(m);
	for(int i=1;i<=m;++i)
	{
		read(d[i].u);read(d[i].v);read(d[i].x);
		if(d[i].u!=1) flag=1;
		if(d[i].v==n) flag2=i;
	}
	if(flag){puts("inf");return 0;}
	if(flag2)
	{
		int i=flag2;
		writesp(d[i].x);writeln(1);
		for(int i=1;i<n;++i) putchar('1');
		putchar('0');putchar(' ');
		writeln(d[i].x);
	}
	else puts("inf");
	return 0;
}
