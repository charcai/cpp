#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n,k=0;
	cin>>n;
	while(n){
		a[k]=n%2;
		n=n/2;
		k++; 
	}
	k--;
	for (int i=k;i>0;i--)
		cout<<a[i];
	cout<<a[0]<<endl;
	return 0;
}
