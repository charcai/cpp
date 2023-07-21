 #include <bits/stdc++.h>
 using namespace std;
 int main(){
		freopen("cal10.in","r",stdin);
		freopen("cal10.out","w",stdout);
		int a,b;
		char ch;
		cin>>a>>b>>ch;
		switch(ch){
			case '+':cout<<a<<'+'<<b<<'='<<a+b<<endl; break;
			case '-':cout<<a<<'-'<<b<<'='<<a-b<<endl; break;
			case '*':cout<<a<<'*'<<b<<'='<<a*b<<endl;break;
			case '/':if (a%b) cout<<a<<'/'<<b<<'='<<a/b<<"..."<<a%b<<endl;  
					 else cout<<a<<'/'<<b<<'='<<a/b<<endl;
					 break;
			default:cout<<"Invalid operator"<<endl;
		}
		return 0;
 }
