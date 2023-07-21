#include<bits/stdc++.h>
using namespace std;
int a[15],b[15],A,B,s=0;
int main(){
	freopen("cowmult10.in","r",stdin);
	freopen("cowmult10.out","w",stdout);
	cin>>A>>B;
	int ka=0,kb=0;
	while(A){
		ka++;
		a[ka]=A%10;
		A/=10;
		
	}
	while(B){
		kb++;
		b[kb]=B%10;
		B/=10;
	}
	for (int i=1;i<=ka;i++)
		for (int j=1;j<=kb;j++)
			s=s+a[i]*b[j];
	cout<<s<<endl;
 	return 0;
}
