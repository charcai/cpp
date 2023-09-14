#include<bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,a[N],lev;
long long res[N],ans;
multiset<int> t;
multiset<int>::iterator it;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i],t.insert(a[i]);
	}
	for(it=t.begin();it!=t.end();it=t.upper_bound(lev)){
		ans+=(*it)-++lev;
		t.erase(it);
	}
	for(int i=n;i>=1;i--){
		res[i]=ans,ans-=a[i];
		it =t.lower_bound(a[i]);
		if(it==t.end()){
			ans+=lev--;
		}
		else{
			ans+=(*it),t.erase(it);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%lld",res[i]);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
