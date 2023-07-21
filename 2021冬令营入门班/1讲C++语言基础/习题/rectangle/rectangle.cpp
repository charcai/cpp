#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("rectangle.in","r",stdin);
	freopen("rectangle.out","w",stdout);
	float lengthy,width,c,s;
	cin>>lengthy>>width;
	c=lengthy+width;
	s=lengthy*width;
	cout<<"C="<<fixed<<setprecision(2)<<c<<" S="<<fixed<<setprecision(2)<<s<<endl;
	return 0;	
}
