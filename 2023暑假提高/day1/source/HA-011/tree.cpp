#include<bits/stdc++.h>
using namespace std;
int m,n,s,a[5005][5005],t[5001],x,y;
int main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		a[x][++t[x]]=y;
		a[y][++t[y]]=x;
	}
	printf("0 %d",n-1);
	for(int i=2;i<=n;i++){
		printf(" %d",i*(n-i)+(i-2)*(i-1)))
	}
	return 0;
}
