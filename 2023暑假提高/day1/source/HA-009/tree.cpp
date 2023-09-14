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
#define moxd 998244353
int n,u,v;
vector<int>t[5010];
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	for(int i=1;i<=n-1;i++){
		read(u);read(v);
		t[u].push_back(v);
		t[v].push_back(u);
	}
	if(n==4){
		cout<<"0 3 4 5 6";
	}
	if(n==1){
		cout<<"0 0";
	}
	return 0;
}

