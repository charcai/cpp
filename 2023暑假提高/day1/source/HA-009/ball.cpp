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
int T,n,a[200010];
int t[200010];
int maxn,k;
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(T);
	for(int _=1;_<=T;_++){
		read(n);
		int ans=0;
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++){
			read(a[i]);
			if(t[a[i]]==0) t[a[i]]=i;
			if(i-t[a[i]]+1>=maxn){
				maxn=i-t[a[i]]+1;
				k=i;
			}
		}
		while(1){
			for(int i=t[a[k]];i<=k;i++){
				if(a[i]==-1) continue;
				a[i]=-1;
				ans++;
			}
			maxn=0;
			for(int i=1;i<=n;i++){
				if(a[i]!=-1){
					if(i-t[a[i]]+1>=maxn){
						maxn=i-t[a[i]]+1;
						k=i;
					}
				}
			}
			if(maxn<=1) break; 
		}
		writeln(ans);
	}
	return 0;
}

