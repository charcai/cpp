#include<bits/stdc++.h>
using namespace std;
int a[2005],opt[2005],b[2005][2005],c[2005],t[2005];
int n,T,s,ans;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++) t[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[a[i]][++t[a[i]]]=i;
			c[i]=t[a[i]];
		}
		if(a[1]==a[n]) {
			printf("%d",n); continue;
		}
		for(int i=1;i<=n;i++){
			opt[i]=opt[i-1];
			for(int j=c[i]-1;j>0;j--)
				opt[i]=max(opt[i],i-b[a[i]][j]+opt[b[a[i]][j]-1]+1);
			ans=max(ans,opt[i]);
//			printf("%d ",opt[i]);
		}
//		printf("\n");
		printf("%d\n",ans);
	}
	return 0;
}
