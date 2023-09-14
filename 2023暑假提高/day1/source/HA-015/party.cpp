#include<bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int n,m;
struct node{
	int num,tm;
}tim[110][110];
LL ar[10010][110],at[110],mn=INF,cnt,cntt,tt[10010];
bool flag,vis[110];

int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,t;i<=m;i++){
		scanf("%d%d%d",&x,&y,&t);
		tim[x][++tim[x][0].num]=(node){y,t};
		tim[y][++tim[y][0].num]=(node){x,t};
		if(x==n||y==n) mn=min(mn,(LL)t);
	}
	for(int i=1;i<n;i++) ar[0][i]=INF;
	tt[0]=mn;vis[n]=1;
	for(int i=1;i<=tim[n][0].num;i++) ar[0][tim[n][i].num]=tim[n][i].tm;
	for(int i=1;i<10000;i++,cnt++){
		for(int j=1;j<=100;j++) at[j]=INF;
//		printf("A%lld\n",mn);
		if(mn==INF) break;
		mn=INF;
		for(int j=1;j<=n;j++) ar[i][j]=INF;
		for(int j=1;j<=n;j++){
			ar[i][j]=min(ar[i][j],ar[i-1][j]-tt[i-1]);
//			cout<<ar[i][j]<<endl;
			if(ar[i][j]!=INF){
				if(ar[i][j]<=0&&!vis[j]){
//					cout<<j<<endl;
					vis[j]=1;
					if(j==1){
						cnt--;
						flag=1;
						break;
					}
					for(int k=1;k<=tim[j][0].num;k++){
						at[tim[j][k].num]=min(ar[i][tim[j][k].num],(LL)tim[j][k].tm);
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			ar[i][j]=min(ar[i][j],at[j]);
			if(!vis[j]) mn=min(mn,ar[i][j]);
		}
		cntt+=tt[i-1];
		tt[i]=mn;
	}
	if(flag) {
		printf("%lld %lld\n",cntt,cnt+1);
		for(int i=0;i<=cnt;i++){
			for(int j=1;j<=n;j++){
				if(ar[i][j]<=0) printf("0");
				else printf("1");
			}
			printf(" %lld\n",tt[i]);
		}
	}
	else printf("inf");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

