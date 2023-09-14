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
const int  mod=1000000007;
#define N 5000+10
int n,m,u,a[N];
double ans=1;
double b[N];
signed main(){
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	read(n);read(m);read(u);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		ans=ans*1.0*(a[i]*n+(i*m*u))/n;
	}
	int an=ans;
	cout<<an%mod;
return 0;
}
/*

5 7 9
9 9 8 2 4
*/
