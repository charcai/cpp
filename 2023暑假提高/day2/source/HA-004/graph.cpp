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
#define N 1000000+10
int Head[N],ver[N],Next[N],ans,v[N],a[N],ansl;
int tot,n,m,num;
int add(int x,int y){
	ver[++tot]=y;Next[tot]=Head[x];Head[x]=tot;
}
bitset<30>ed[N];
void dfs(int x,bitset<30>num,int st){
	if(v[x]==1){
		if(num.count()>=n&&x==st){
			ansl=1;
			printf("Yes\n");
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					for(int j=Head[i];j;j=Next[j]){
						int y=ver[j];
						if(v[y]==1){
							a[i]=y;
							break;
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				writesp(a[i]);
			}
		}
		return;
	}
	v[x]=1;
	for(int i=Head[x];i;i=Next[i]){
		int y=ver[i];
		a[x]=y;
		dfs(y,num|ed[y],st);
		a[x]=0;
		if(ansl==1)return;
	}
	v[x]=0;
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		add(x,y);add(y,x);
		ed[x].set(y,1);ed[y].set(x,1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[j]=0;a[j]=0;
		}
		dfs(i,ed[i],i);
		if(ansl==1)break;
	}
	if(!ansl)printf("No\n");
return 0;
}
/*
7 9
1 2
1 3
1 4
1 5
4 5
4 6
4 7
5 6
6 7

10
12
1 2
1 3
1 5
1 6
6 7
5 7
2 4
3 4
4 8
4 9
8 10
9 10

6 5
1 2
2 3
3 4
4 5
5 6

7 9
1 2
1 3
1 4
1 5
4 5
4 6
4 7
5 6
6 7

6 7
1 2
2 3
3 1
4 5
5 6
4 6
2 5

3 2
1 2
2 3

4 4
1 3
2 3
4 1
4 2

20
20
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 3

5
5
1 2
2 3
3 4
4 5
5 3

8 8
1 2
2 3
3 4
4 1
1 5
2 6
3 7 
4 8
*/

