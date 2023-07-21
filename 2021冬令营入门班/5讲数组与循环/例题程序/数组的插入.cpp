#include <bits/stdc++.h>
using namespace std;
int a[10005],n,x,k=1;
int main(){
	cout<<k<<endl;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cin>>x;
	while (x>a[k]&& k<=n) k++;
	cout<<k<<endl;
	for (int i=n;i>=k;i--)
		a[i+1]=a[i];
	a[k]=x;
	n++;
	for (int i=1;i<n;i++)
		cout<<a[i]<<" ";
	cout<<a[n]<<endl;
	return 0;
}
