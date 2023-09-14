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
#define maxn 110
#define maxm 100010
#define int long long
struct edge{int u,v,w,nxt;}eg[maxm<<1];
int n,m,hd[maxn],tot=0,x,y,z,flg,t;
signed main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	read(n); read(m); flg=1;
	for(int i=1;i<=m;++i){
		read(eg[i].u); read(eg[i].v);
		read(eg[i].w);
		if(eg[i].u!=1) flg=0;
	}
	if(flg){
		flg=0;
		for(int i=1;i<=m;++i)
			if(eg[i].v==n) flg=1;
		if(!flg) puts("inf");
		else{
			for(int i=1;i<=m;++i)
				if(eg[i].v==n){
					t=eg[i].w;
					writesp(eg[i].w),writeln(1);
				}
			for(int i=1;i<n;++i) write(1);
			writesp(0); writeln(t);
		}
		return 0;
	}
	puts("inf");
	return 0;
}

