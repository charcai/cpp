#include<bits/stdc++.h>
using namespace std;
int t[10005],L,M,num,ans;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&L,&M);
	for(int i = 1;i <= M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		t[x]++;
		t[y + 1]--;		
	}
	for(int i = 0;i <= L;i++){
		num += t[i];
		ans = ans + (num == 0);
	}
	printf("%d\n",ans);
} 
