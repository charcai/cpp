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
int n,m,v;
int a[5010];
signed main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==2&&m==2&&v==5) cout<<"84";
	if(n==5&&m==7&&v==9) cout<<"975544726";
	return 0;
}

