#include <bits/stdc++.h>
using namespace std;
int d[10005],n;
int main(){
	int k;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>d[i];
	for (int i=1;i<n;i++){
		int fg=0 ;
		for (int j=1;j<=n-i;j++)
			if (d[j]>d[j+1]) {
				swap(d[j],d[j+1]);
				fg=1;
		}
		if (!fg) break;
	}
	for (int i=1;i<n;i++)
		cout<<d[i]<<" ";
	cout<<d[n]<<endl;
	return 0;
}
