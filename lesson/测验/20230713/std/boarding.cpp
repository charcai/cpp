#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n,m,lft,rgt,mid,ans,t[N];
bool check(int x){
	int s = 0;
	for(int i = 1;i <= n;i++){
		s += x / t[i];		

	}
	return s >= m;
}

signed main(){
	freopen("boarding.in","r",stdin);
	freopen("boarding.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> t[i];
		rgt = max(rgt,t[i]);
	}
	rgt *= m;
	while(lft <= rgt){
		mid = lft + rgt >> 1;
		if (check(mid))
			ans = mid,rgt = mid - 1;
		else
			lft = mid + 1; 
	}
	cout << ans << endl;
	return 0;
	
} 
