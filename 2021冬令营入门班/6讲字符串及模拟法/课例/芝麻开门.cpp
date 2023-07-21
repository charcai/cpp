#include<bits/stdc++.h>
using namespace std;
int main(){
	string user,pwd;
	getline(cin,user);
    getline(cin,pwd);
	if(user=="alibaba"){
		if(pwd=="open sesame"){
			cout<<"Welcome home!"<<endl;
		} 
		else cout<<"Please input correct password!";   
	}
	else cout<<"Sorry,please leave!"<<endl;
}
