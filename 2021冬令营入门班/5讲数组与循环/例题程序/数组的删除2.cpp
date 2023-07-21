#include <bits/stdc++.h>
using namespace std;
int a[10005],n,x,flag=0;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cin>>x;
	for (int i=1;i<=n;i++)
		if (a[i]==x){flag=i;break; }
	if (flag==0) {
		cout<<"no"<<endl;
		return 0;
	}
	for (int i=flag+1;i<=n;i++)
		a[i-1]=a[i];
	n--;
	for (int i=1;i<n;i++)
		cout<<a[i]<<" ";
	cout<<a[n]<<endl;
	return 0;
}
