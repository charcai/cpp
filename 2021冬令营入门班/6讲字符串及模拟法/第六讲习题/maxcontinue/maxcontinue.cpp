#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
	int n,ans=1,cnt=1;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i>=2&&a[i]==a[i-1]+1) cnt++;
		else {
			if(cnt>ans) ans=cnt;
			cnt=1;
		}
	}
	cout<<ans<<endl;
}
