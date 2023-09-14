#include<bits/stdc++.h>
using namespace std;

#define int long long
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
#define N 1000000+10
bool a[N],b[N];
int t,n,ans,tot;
void dfs(int x){
	bool ansl=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			ansl=0;
			break;
		}
	}
	if(ansl==1){
		ans+=x;
		tot++;
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]^=1;
		dfs(x+1);
		a[i]^=1;
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		ans=0;tot=0;
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			if(c=='1')a[i]=1;
			else a[i]=0;
		}
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			if(c=='1')b[i]=1;
			else b[i]=0;
		}
		dfs(0);
		ans/=tot;
		ans%=mod;
		writeln(ans);
	}
return 0;
}
