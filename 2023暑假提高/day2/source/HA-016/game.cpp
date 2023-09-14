#include<bits/stdc++.h>

#define N 1000005

#define int long long

using namespace std;

int T,n,ans[N],cnt,ovo,a[N],b;

multiset<int>qwq;

multiset<int>::iterator awa;

signed main(){
	
	freopen("game.in","r",stdin);

	freopen("game.out","w",stdout);
	
	scanf("%lld",&T);
	
	while(T--){
	
		scanf("%lld",&n);
	
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),qwq.insert(a[i]);
	
		cnt=1,awa=qwq.begin(),ovo=0;
		
		while(awa!=qwq.end()){

			ovo+=*awa-cnt,qwq.erase(awa);

			awa=qwq.lower_bound(++cnt);

		}cnt--;
		
		for(int i=n;i;i--){

			ans[i]=ovo,awa=qwq.lower_bound(a[i]),ovo-=a[i];

			if(awa==qwq.end()) ovo+=cnt,cnt--;

			else ovo+=*awa,qwq.erase(awa);

		}
		
		for(int i=1;i<=n;i++) printf("%lld ",ans[i]);printf("\n");

	}
	
	fclose(stdin);

	fclose(stdout);
	
	return 0;

}
