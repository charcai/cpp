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
#define N 2000000+10
int n,t,a[N];
priority_queue<int>que;
priority_queue<int>q;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		while(que.size())que.pop();
		while(q.size())q.pop();
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			que.push(-a[i]);
			if(a[i]>cnt){
				ans+=a[i]-cnt-1;
				cnt++;
				writesp(ans);
				continue;
			}
			cnt=0;ans=0;
			for(int j=1;j<=i;j++){
				int x=-que.top();que.pop();
				q.push(-x);
				if(x==cnt)continue;
				if(x>cnt){
					ans+=x-cnt-1;
					cnt++;
				}
			}
			writesp(ans);
			que=q;
			while(q.size())q.pop();
		}
		putchar('\n');
	}
return 0;
}
/*
3
3
3 1 2
6
4 1 5 4 1 1
4
1 2 5 4
*/
