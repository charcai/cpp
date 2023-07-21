#include <bits/stdc++.h>
using namespace std;
int d[10005],n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>d[i];
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (d[i]>d[j]) swap(d[i],d[j]);
	for (int i=1;i<n;i++)
		cout<<d[i]<<" ";
	cout<<d[n]<<endl;
	return 0;
}
