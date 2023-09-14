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
int a[N],t,n,x,p,ansl;
signed main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	for(int i=1;i<=200010;i++)a[i]=a[i-1]+i;
	read(t);
	while(t--){
		read(n);read(x);read(p);
		ansl=0;
		for(int i=1;i<=min(2*n,p);i++){
			if((x+a[i])%n==0){
				ansl=1;
				printf("Yes\n");
				break;
			}
		}
		if(!ansl)printf("No\n");
	}
return 0;
}
/*
7
100000 1 1000000000
20 16 1000000000
20 13 1000000000
20 11 1000000000
20 8 1000000000
20 6 1000000000
20 3 1000000000

*/
