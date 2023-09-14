#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
signed main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	int t,n,x,p,f,c;
	cin>>t;
	while(t--){
		cin>>n>>x>>p;
		f=1;c=0;
		for(int i=1;i<=min(n*3,p);i++){
			c+=i;
			if(c%n==(n-x)%n){
				puts("Yes");
				f=0;
				break;
			}
		}
		if(f) puts("No");
	}
	return 0;
}
