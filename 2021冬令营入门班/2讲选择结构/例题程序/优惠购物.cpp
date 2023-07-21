#include <bits/stdc++.h>
using namespace std;
int x,g=0;
double pay;
char id;
int main(){
	cin>>id;
	cin>>x;
	if (id=='V') {
		if(x<=500) pay=x*0.8;
		else{
			 pay=x*0.7;
			 g=1;
		} 
	} 
	else{
		pay=x*0.9;
		if (x<=800) g=1;
	}
	if (g) cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	cout<<fixed<<setprecision(2)<<pay<<endl;
	return 0;
}
		
	
