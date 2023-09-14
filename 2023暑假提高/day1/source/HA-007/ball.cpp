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
int T,n,a[maxn],dp[maxn],p[maxn],mx,flg;
void solve(){
	read(n); flg=1;
	for(int i=1;i<=n;++i){
		read(a[i]); dp[i]=0;
		if(a[i]!=1&&a[i]!=2) flg=0;
	}
	if(n==1){writeln(0); return ;}
	if(flg==1){
		flg=0;
		if(a[1]==a[n]){
			writeln(n); return ;
		}
		for(int i=3;i<n;++i)
			if(a[i-1]==a[1]&&a[i]==a[n]) flg=1;
		if(flg) writeln(n);
		else writeln(n-1);
		return ;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) p[j]=0; mx=0;
		for(int j=i-1;j>=0;--j){
			if(!p[a[j+1]]) p[a[j+1]]=j+1;
			else mx=max(mx,p[a[j+1]]-j);
			dp[i]=max(dp[i],dp[j]+mx);
		}
	}
	writeln(dp[n]);
}
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(T);
	while(T--) solve();
	return 0;
}

