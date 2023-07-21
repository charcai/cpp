#include<bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	int left,right,temp,p,ans=0;
	cin>>left>>right;
	for(int i=left; i<=right; i++) {
		temp=i;
		p=0;
		while(temp>0) {
			a[++p]=temp%10;
			temp/=10;
		}
		for(int j=p; j>=1; j--) {
			if(a[j]==2) ans++;
		}
	}
	cout<<ans<<endl;
}
