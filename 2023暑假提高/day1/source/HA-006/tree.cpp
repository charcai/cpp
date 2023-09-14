#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define inf 0x3f3f3f3f
#define int long long
vector<int> g[N];
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,x,y;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout<<0<<" ";
	for(int i=1;i<=n;i++){
		cout<<(n-i)*i+abs(i-2)*(i-1)<<" ";
	}
	return 0;
}
