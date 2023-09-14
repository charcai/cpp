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
int T,n,hp[200010],dp[200010],aoe[200010];
int f[200010];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(T);
	for(int _=1;_<=T;_++){
		read(n);
		for(int i=1;i<=n;i++) read(hp[i]),f[i]=f[i-1]+hp[i];
		bool flag=0;
		aoe[1]=1;
		if(hp[1]==1) flag=1;
		dp[1]=hp[1]-1;
		cout<<dp[1]<<' ';
		for(int i=2;i<=n;i++){
			if(hp[i]==1){
				if(flag==1){
					aoe[i]=aoe[i-1];
				}
				else{
					flag=1;
					aoe[i]=aoe[i-1]+1;
				}
			}
			else aoe[i]=aoe[i-1]+1;
			if(hp[i]<=aoe[i-1]) dp[i]=min(dp[i-1],f[i]-(aoe[i]*(aoe[i]+1)/2));
			else dp[i]=f[i]-(aoe[i]*(aoe[i]+1)/2);
			cout<<dp[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
