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
#define mod 1000000007
#define maxn 5010
#define int long long
int n,m,val,a[maxn],sum=0,cnt=0,ans;
void dfs(int st){
	if(st==m){
		int tmp=1; cnt=(cnt+1)%mod;
		for(int i=1;i<=n;++i) tmp=tmp*a[i]%mod;
		sum=(sum+tmp)%mod;
		return ;
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j) a[j]+=val;
		dfs(st+1);
		for(int j=i;j<=n;++j) a[j]-=val;
	}
}
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	}
	return res%mod;
}
signed main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	read(n); read(m); read(val);
	for(int i=1;i<=n;++i) read(a[i]);
	dfs(0); ans=sum*qpow(cnt,mod-2)%mod;
	writeln(ans);
	return 0;
}

