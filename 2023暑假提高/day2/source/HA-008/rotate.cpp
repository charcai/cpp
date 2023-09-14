#include<bits/stdc++.h>
using namespace std;

#define int long long

int t;
int n,x,p;
int f[200003];

signed main(){
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>x>>p;
		for(int i=1;i<=2*n && i<=p;i++){
			x=(x+i)%n;
			if(x==0){
				cout<<"Yes\n";
				goto ret;
			}
		}
		cout<<"No\n";
		ret:;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}