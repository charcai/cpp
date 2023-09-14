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
int T,n,a[maxn],b[maxn],ans,sum,tmp;
void solve(){
	read(n); sum=0;
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j) b[j]=a[j];
		sort(b+1,b+i+1); ans=0; tmp=1;
		for(int j=1;j<=i;++j){
			if(b[j]<tmp) continue;
			ans+=b[j]-tmp; ++tmp;
		}
		writesp(ans);
	}
	putchar('\n');
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(T);
	while(T--) solve();
	return 0;
}
/*
2
3
3 1 2
6
4 1 5 4 1 1
*/
