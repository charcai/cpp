#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("discount4.in","r",stdin);
	freopen("discount4.out","w",stdout);
	char id;
	int x;
	double pay;
	cin>>id;
	cin>>x;
	if(id=='P') pay=0.7*x;
	else 
		if (id=='G') pay=0.8*x;
		else
			if (id=='S') pay=0.9*x;
			else
				pay=0.95*x;
	cout<<fixed<<setprecision(2)<<pay<<endl;
	return 0;
} 
