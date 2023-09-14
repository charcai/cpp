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
#define maxn 200010
#define int long long
int T,n,x,p,sum,ans;
void solve(){
	read(n); read(x); read(p);
	ans=sum=0; p=min(p,n*2);
	for(int i=1;i<=p;++i){
		sum=(sum+i)%n;
		if(sum==(n-x)%n) ans=1;
	}
	if(ans) puts("Yes");
	else puts("No");
}
signed main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	read(T);
	while(T--) solve();
	return 0;
}
/*
7
5 2 1
5 2 2
10 0 100
11 7 100
3 1 1000
31 0 10
100 49 7

*/
