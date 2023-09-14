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
#define N 200005
#define debug printf("Now is on line %d\n",__LINE__)
int n,a[N],f[N<<2],lz[N<<2];
inline void pushup(int id)
{
	f[id]=min(f[id<<1],f[id<<1|1]);
	return;
}
inline void pushdown(int id)
{
	f[id<<1]+=lz[id];
	lz[id<<1]+=lz[id];
	f[id<<1|1]+=lz[id];
	lz[id<<1|1]+=lz[id];
	lz[id]=0;
	return;
}
void build(int id,int l,int r)
{
	lz[id]=0;
	if(l==r)
	{
		f[id]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	pushup(id);
	return;
}
void change(int id,int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R)
	{
		f[id]+=x;
		lz[id]+=x;
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(L<=mid) change(id<<1,l,mid,L,R,x);
	if(mid<R) change(id<<1|1,mid+1,r,L,R,x);
	pushup(id);
	return;
}/*
int query(int id,int l,int r,int x)
{
	if(l==r) return f[id];
	pushdown(id);
	int mid=(l+r)>>1;
	if(x<=mid) return query(id<<1,l,mid,x);
	else return query(id<<1|1,mid+1,r,x);
}*/
void work()
{
	int x,prea;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	build(1,1,n);
	prea=0;
	for(int i=1;i<=n;++i)
	{
		prea+=a[i];
		change(1,1,n,a[i],n,-1);
		x=min(i,i+f[1]);
	//	cout<<x<<' '<<i+f[1]<<'/';
	//	for(int j=1;j<=n;++j) cout<<query(1,1,n,j)<<' ';
		writesp(prea-x*(x+1)/2-i+x);
	}
	putchar('\n');
	return;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;read(T);
	while(T--) work();
	return 0;
}
