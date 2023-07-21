#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("change10.in","r",stdin);
	freopen("change10.out","w",stdout); 
	int p,n,k=0;
	cin>>n>>p;
	while(n){
		a[k]=n%p;
		n=n/p;
		k++; 
	}
	k--;
	for (int i=k;i>0;i--)
		cout<<a[i];
	cout<<a[0]<<endl;
	return 0;
}
