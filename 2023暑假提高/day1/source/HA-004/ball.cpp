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
#define N 400000+10
int n,t,a[N],dp[N],nex[N];
vector<int>d[N];
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)read(a[i]);
		memset(dp,0,sizeof(dp));
		memset(nex,0,sizeof(nex));
		for(int i=1;i<=n;i++){
			d[i].clear();
		}
		for(int i=1;i<=n;i++){
			d[a[i]].push_back(i);
		}
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			for(int j=0;j<d[a[i]].size();j++){
				int y=d[a[i]][j];
				if(y==i)break;
				dp[i]=max(dp[i],dp[y-1]+i-y+1);
			}
		}
		writeln(dp[n]);
	}
return 0;
}
/*
4
5
1 2 2 3 3
4
1 2 1 2
10
2 1 2 1 3 1 3 4 5 1
6
1 1 2 3 2 1
 */
