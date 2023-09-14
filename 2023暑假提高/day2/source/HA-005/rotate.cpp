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
int n,st,p;
bool b[N];
void work()
{
	read(n);read(st);read(p);
	int x=st;
	if(p<=n)
	{
		for(int i=1;i<=p;++i)
		{
			x=(x+i)%n;
			if(!x){puts("Yes");return;}
		}
		puts("No");
		return;
	}
	memset(b,0,(n+1)*sizeof(bool));
	for(int i=1;i<=n;++i)
	{
		x=(x+i)%n;
		b[x]=1;
		if(!x){puts("Yes");return;}
	}
	x=(x+n-st)%n;
	for(int i=1;i<=p/n;++i)
	{
		if(b[n-i*x%n])
		{
			cout<<n-i*x%n<<endl;
			puts("Yes");return;
		}
	}
	puts("No");
	return;
}
signed main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	int T;read(T);
	while(T--) work();
	return 0;
}
