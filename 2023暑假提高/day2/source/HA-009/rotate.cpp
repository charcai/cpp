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
int T;
int n,x,p;
signed main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	read(T);
	for(int _=1;_<=T;_++){
		read(n);
		read(x);
		read(p);
		bool flag=0;
		for(int i=1;i<=p;i++){
			if((((i*(i+1))/2)+x)%n==0){
				cout<<"Yes"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"No"<<endl;
	}
	return 0;
}

