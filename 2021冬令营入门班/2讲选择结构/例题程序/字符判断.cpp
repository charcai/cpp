#include <bits/stdc++.h>
using namespace std;
char ch;
int main(){
	cin>>ch;
	if (ch>='A' && ch<='Z')  	cout<<"capital"<<endl;
	else
		if (ch>='a' && ch<='z') 	cout<<"lowercase"<<endl;
		else
			if (ch>='0' && ch<='9')	 cout<<"number"<<endl;
			else 
				cout<<"others"<<endl;
  	return 0;
}

