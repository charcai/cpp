#include <bits/stdc++.h>
using namespace std;
int n,x,y,k;
int main(){
	cin>>n>>x>>y;
	k=y/x;
	if (y%x) k++;
	if (n>=k) cout<<n-k<<endl;
	else cout<<0<<endl;
  	return 0;
}

