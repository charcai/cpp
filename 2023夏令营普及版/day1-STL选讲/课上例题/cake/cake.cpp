#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n;
pair<int,int> a[maxn];
int main(){
	freopen("cake.in ","r",stdin);
	freopen("cake.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=make_pair(x,i);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	   cout<<a[i].second<<" ";
	return 0;
}


