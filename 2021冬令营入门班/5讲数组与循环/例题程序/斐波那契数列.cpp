#include<bits/stdc++.h>
using namespace std;
int a[22]={0,1};
int main(){
	for (int i=2;i<20;i++)
		a[i]=a[i-1]+a[i-2];
	for(int i=19;i>0;i--)
		cout<<a[i]<<" ";
	cout<<a[0]<<endl;
	return 0;
}

