#include<bits/stdc++.h>
#define LL long long
using namespace std;

int T;
int n,t,mx;
LL num[200005],ln,cnt;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		mx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&t);mx=max(mx,t);
			num[t]++;
			ln=1;cnt=0;
			for(int j=1;j<=mx;j++){
				int k=num[j];
				if(k){
					int mn=min((LL)j,ln+k-1);
					cnt+=((j-ln)+(j-mn))*(mn-ln+1)/2;
					ln=mn+1;
				}
			}
			printf("%lld ",cnt);
		}
		for(int i=1;i<=mx;i++) num[i]=0;
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


