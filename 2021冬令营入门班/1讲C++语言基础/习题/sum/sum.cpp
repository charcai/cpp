#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    int a;
	int s=0,x,y,z;
	cin>>a;
	x=a/100;
	y=a/10%10;
	z=a%10;
	s=s+x+y+z;
	cout<<s<<endl;
	return 0;	
}
