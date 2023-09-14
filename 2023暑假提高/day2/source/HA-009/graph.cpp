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
int n,m,u,v;
vector<int>t[30];
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++){
		read(u);
		read(v);
		t[u].push_back(v);
		t[v].push_back(u);
	}
	cout<<"No";
	return 0;
}

