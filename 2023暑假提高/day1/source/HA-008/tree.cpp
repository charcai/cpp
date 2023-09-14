#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	cin>>n;
	cout<<"0 ";
	for(int i=1;i<=n;i++){
		cout<<(i-1)*abs(i-2)+(n-i)*i<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
