#include <bits/stdc++.h>
using namespace std;
int a[10005],n,x,flag;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cin>>x;
	flag=n+1;
	for (int i=1;i<=n;i++)
		if (a[i]>x){flag=i;break; }
	for (int i=n;i>=flag;i--)
		a[i+1]=a[i];
	a[flag]=x;	n++;
	for (int i=1;i<n;i++)
		cout<<a[i]<<" ";
	cout<<a[n]<<endl;
	return 0;
}
