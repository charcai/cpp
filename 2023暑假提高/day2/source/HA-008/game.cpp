#include<bits/stdc++.h>
using namespace std;

int t;
int n;

int a[200003];
int ans[200003];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		
		int x;
		for(register int q=1;q<=n;q++){
			sort(a+1,a+q+1);
			x=0;
			ans[q]=0;
			for(register int i=1;i<=q;i++){
				if(a[i]==x){
					continue;
				}
				x++;
				ans[q]+=a[i]-x;
			}
		}
		for(register int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
