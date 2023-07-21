#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	int n,x; 
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cin>>x;

	for (int i=x+1;i<=n;i++)
		a[i-1]=a[i];
	n--;
	for (int i=1;i<n;i++)
		cout<<a[i]<<" ";
	cout<<a[n]<<endl;
	return 0;
}
