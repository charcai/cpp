#include <bits/stdc++.h>
using namespace std;
int d[10005],n;
int main(){
	int k;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>d[i];
	for (int i=1;i<n;i++){
		k=i;
		for (int j=i+1;j<=n;j++)
			if (d[k]>d[j]) k=j;
		swap(d[i],d[k]);
	}
	for (int i=1;i<n;i++)
		cout<<d[i]<<" ";
	cout<<d[n]<<endl;
	return 0;
}
