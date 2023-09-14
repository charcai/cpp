#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005
int T,n,x,p,k;
signed main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	cin>>T;
	qwq:
	while(T--){
		cin>>n>>x>>p;
		k=(n-x)%n;
		for(int i=1;i<=min(p,1000000ll);i++){
			if((i*(i+1)/2)%n==k){
				cout<<"Yes"<<endl;
				goto qwq;
			}
		}
		cout<<"No"<<endl;
	}
	return 0;
}
