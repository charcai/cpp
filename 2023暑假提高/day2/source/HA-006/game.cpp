#include<bits/stdc++.h>
using namespace std;
#define N 200010
int a[N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int t,n,tot,ans,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		for(i=1;i<=n;++i){
			sort(a+1,a+i+1);
			tot=1;
			ans=0;
			for(j=1;j<=i;++j){
				if(a[j]>=tot){
					ans+=a[j]-tot;
					tot++;
				}
			}
			printf("%d ",ans);
		}
		puts("");
	}
	return 0;
}
