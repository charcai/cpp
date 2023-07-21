#include<bits/stdc++.h>
using namespace std;
int main() {
	long long datax,datay;
	long long  x,y;
	while(cin>>datax) {
		x=datax;
		datay=0;
		while(x!=0) {
			y=x%10;
			datay=datay*10+y;
			x=x/10;
		}
		if(datay==datax) cout<<datax<<endl;
	}
	return 0;
}
