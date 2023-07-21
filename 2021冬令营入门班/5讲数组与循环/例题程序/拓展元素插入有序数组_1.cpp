#include <bits/stdc++.h>
using namespace std;
int n,a[10005],x,fg;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cin>>x;
	fg=n+1;
	for (int i=1;i<=n;i++)
		if (a[i]>x) {fg=i;break;}
	for (int i=n;i>=fg;i--)
		a[i+1]=a[i];
	a[fg]=x;
	n++;
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
} 
