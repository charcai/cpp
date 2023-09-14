#include<bits/stdc++.h>
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
#define N 200005
#define debug printf("Now is on line %d\n",__LINE__)
int tot,n,a[N],head[N],f[N];
struct dot{int l,r;}d[N];
bool cmp(dot u,dot v){return u.r<v.r;}
void work()
{
	read(n);
	memset(head,0,(n+1)*sizeof(int));
	tot=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		if(head[a[i]]) d[++tot]=dot{head[a[i]],i};
		head[a[i]]=i;
	}
	sort(d+1,d+tot+1,cmp);
	int l=1,r=1;
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		while(d[r].r==i && r<=tot) ++r;
		for(int j=l;j<r;++j) f[i]=max(f[i],max(f[d[j].l-1]+d[j].r-d[j].l+1,f[d[j].l]+d[j].r-d[j].l));
		l=r;
	}
	writeln(f[n]);
	return;
}
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int T;read(T);
	while(T--) work();
	return 0;
}
