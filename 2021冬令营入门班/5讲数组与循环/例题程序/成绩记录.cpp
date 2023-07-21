#include<bits/stdc++.h>
using namespace std;
int a[55],n;
int main(){
	cin>>n;
 	for (int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=1;i<=n;i++)
		cout<<i<<":"<<a[i]<<endl;
	
	return 0;
}
/*

 5
10 9 8 10 7

*/ 
