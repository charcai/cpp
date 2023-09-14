#include<bits/stdc++.h>
#define LL long long
using namespace std;

int T;
int n,x,p;
LL num[1000005],vis[100005];
bool flag=0;
int kkk;

int main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=0;
		scanf("%d%d%d",&n,&x,&p);
		int x1=x,x2=x;
		for(int i=1;i<=p;i++){
			x1+=i;x1%=n;
			vis[x1]++;
			if(vis[x1]>n) break;
			if(!x1) {
				flag=1;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
		for(int i=0;i<=n;i++) vis[i]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

